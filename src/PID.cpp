#include "PID.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {
	p_error = 0;
	d_error = 0;
	i_error = 0;
	no_of_steps = 0;
	total_error = 0;
}

PID::~PID() {
}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp;
	this->Kd = Kd;
	this->Ki = Ki;

	d_error = 0;
	i_error = 0;
	p_error = 0;
}

void PID::UpdateError(double cte) {

	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

	total_error += pow(cte, 2);
	no_of_steps++;

}

double PID::getSteeringValue(double cte) {

	double steer = -Kp * cte - Kd * d_error - Ki * i_error;
	cout << "computed steer" << steer << endl;
	return steer;

}

double PID::TotalError() {

	return total_error / no_of_steps;

}

