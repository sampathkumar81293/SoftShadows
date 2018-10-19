#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GLM/glm.hpp>


#include <iostream>
#include <vector>

using namespace std;
using namespace glm;

GLuint VBO;



//GLuint VBO;
void renderScene(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	//glClearColor(0.0, 0.3, 0.3, 1.0);

	glutSwapBuffers();
}

void CreateVertexBuffer()
{
	vector <vec3> Vertices;
	Vertices.push_back(vec3(-1.0, -1.0, 0.0));
	Vertices.push_back(vec3(1.0, -1.0, 0.0));
	Vertices.push_back(vec3(0.0, 1.0, 0.0));

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(vec3), &Vertices[0], GL_STATIC_DRAW);
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_3"))
	{
		std::cout << " GLEW Version is 4.5\n ";
	}
	else
	{
		std::cout << "GLEW 4.5 not supported\n ";
	}

	//glEnable(GL_DEPTH_TEST);
	// register callbacks
	glutDisplayFunc(renderScene);
	CreateVertexBuffer();
	glutMainLoop();

	return 0;
}

/*
void init();
void display(void);
void centerOnScreen();
void drawObject();

//  define the window position on screen
int window_x;
int window_y;

int window_width = 480;
int window_height = 480;
char *window_title = "Sample OpenGL FreeGlut App";

void CreateVertexBuffer()
{
	vector <vec3> Vertices;
	Vertices.push_back(vec3(-1.0, -1.0, 0.0));
	Vertices.push_back(vec3(1.0, -1.0, 0.0));
	Vertices.push_back(vec3(0.0, 1.0, 0.0));

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 3*sizeof(vec3), &Vertices[0], GL_STATIC_DRAW);
}


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawObject();
	glutSwapBuffers();
}


void drawObject()
{
	glutWireIcosahedron();
}


void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}

void initialiseglutcallbacks()
{

	glutDisplayFunc(display1);
}

void main(int argc, char **argv)
{

	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);



	init();
	initialiseglutcallbacks();

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		exit;
	}

	CreateVertexBuffer();
	//  Start GLUT event processing loop
	glutMainLoop();
}

*/
