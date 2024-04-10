#include <bits/stdc++.h>

using namespace std;

double calc(int w, int h, double a){
	double dx=h*tan(a/2)/2.0;
	double x2=w/2.0-dx;
	return x2*(x2*tan(a));
}

double PI = 3.14159265358;

int main(){
	int w, h, A;
	scanf("%d%d%d", &w, &h, &A);
	if(h > w)
		swap(h, w);
	double a=A;
	if(a > 90)
		a = 180-a;
	a *= PI/180;
	double ans=(h+0.0)*w;
	double dy=w*tan(a/2)/2;
	double y2=h/2.0-dy;
	if(y2 < 0){
		ans = h*(h/sin(a));
	}
	else{
		ans -= calc(w, h, a);
		ans -= calc(h, w, a);
	}
	printf("%.7lf\n", ans);	
}