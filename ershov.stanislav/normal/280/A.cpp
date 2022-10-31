#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const long double pi = 3.1415926535897932384626433832795;

double x[40], y[40];
int n;

void add(int xx, int yy, double ang) {
	x[n]=cos(ang)*xx-sin(ang)*yy;
	y[n]=sin(ang)*xx+cos(ang)*yy;
	n++;
}

void cut(double xa, double ya, double xb, double yb) {
	double a=ya-yb, b=xb-xa;
	double c=-a*xa-b*ya;
	double xx[40], yy[40];
	double eps=1e-10;
	int nn=0;
	x[n]=x[0], y[n]=y[0];
	for (int i=0; i<n; i++) {
		double z1=a*x[i]+b*y[i]+c, z2=a*x[i+1]+b*y[i+1]+c;
		if (z1<eps) {
			xx[nn]=x[i], yy[nn]=y[i], nn++;
		}
		if ((z1<eps && z2>eps) || (z1>eps && z2<eps)) {
			double aa=y[i+1]-y[i], bb=x[i]-x[i+1];
			double cc=-aa*x[i]-bb*y[i];
			double d=a*bb-b*aa;
			xx[nn]=-(c*bb-b*cc)/d;
			yy[nn]=-(a*cc-c*aa)/d;
			nn++;
		}
	}
	n=nn;
	for (int i=0; i<n; i++) x[i]=xx[i], y[i]=yy[i];
}

int main() {
	int w, h, iang;
	cin >> w >> h >> iang;
	double ang=iang/180.0*pi;
	add(w, h, ang);
	add(-w, h, ang);
	add(-w, -h, ang);
	add(w, -h, ang);
	cut(w, h, w, -h);
	cut(w, -h, -w, -h);
	cut(-w, -h, -w, h);
	cut(-w, h, w, h);
	double area=0;
	x[n]=x[0], y[n]=y[0];
	for (int i=0; i<n; i++) area+=x[i]*y[i+1]-x[i+1]*y[i];
	cout << fixed << setprecision(10) << area/8;
}