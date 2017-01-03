#include "gamewindow.h"


void GameWindow::setRunning(bool newRunning)
{
	_running = newRunning;
}

bool GameWindow::getRunning()
{
	return _running;
}

GameWindow::GameWindow(bool running, GLFWwindow* window): _running(running)
{
	_window = window;
	/* glClearColor - specify clear values for the color buffers
	   void glClearColor(GLfloat red, GLfloat green, GLfloat blue,
			     GLfloat alpha); */
	glClearColor(1.0f, 0.6f, 0.2f, 1.0f);

	/* This function retrieves the size, in pixels, of the framebuffer of
	 * the specified window. */
	glfwGetFramebufferSize(window, &_width, &_height);
	glViewport(0, 0, _width, _height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
			GLdouble top, GLdouble nearVal, GLdouble farVal); */
	glOrtho(0.0, _width, 0.0, _height, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

}

void GameWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.6f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2f(   0.0f,   0.0f);
		glVertex2f( 100.0f,   0.0f);
		glVertex2f( 100.0f, 100.0f);
		glVertex2f(   0.0f, 100.0f);
	glEnd();	
	glBegin(GL_TRIANGLES);
		glVertex2f(   200.0f,  200.0f);
		glVertex2f(   280.0f,  280.0f);
		glVertex2f(   360.0f,  200.0f);
	glEnd();

	
	glColor3f(0.6f, 0.2f, 0.2f);
	glBegin(GL_POINTS);
		glVertex2f(   20.0f,   35.0f);
		glVertex2f(   28.0f,   40.0f);
		glVertex2f(   28.0f,   30.0f);
		glVertex2f(   35.0f,   28.0f);
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POINTS);
	for(float i=0.0; i<200; i++){
		glVertex2f( 200.0f+i, 100.0f+i);	
	}
	glEnd();


	/* Swap front and back buffers */
	glfwSwapBuffers(_window);
}

void GameWindow::update()
{
}
