#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	double width, height, x0, y0, z0, vx, vy, vz;
	scanf("%lf%lf%lf", &width, &height, &x0);
	y0=width/2;
	z0=0;
	scanf("%lf%lf%lf", &vy, &vx, &vz);
	double time=-x0/vx, ansy, ansz;
	ansz=z0+vz*time;
	ansz -= floor(ansz/(2*height))*2*height;
	if(ansz > height)
		ansz=2*height-ansz;
	ansy=y0+vy*time;
	if(ansy < 0){
		ansy += (floor((-ansy)/(2*width))+2)*2*width;
	}
	ansy -= floor(ansy/(2*width))*2*width;
	if(ansy > width)
		ansy=2*width-ansy;
	printf("%.6lf %.6lf", ansy, ansz);
	return 0;
}