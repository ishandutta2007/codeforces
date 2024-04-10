#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	double a, d;
	int n;
	scanf("%lf%lf%d", &a, &d, &n);
	//cerr << a << ' ' << d << ' ' << n << '\n';
	for(int i = 1; i <= n; i++) {
		long long v = (long long)(floor(d * i / a));
		double l = d * i - v * a;
		//cerr << v << ' ' << l << '\n';
		v %= 4;
		double x, y;
		if(v == 0) {
			x = l;
			y = 0;
		} else if(v == 1) {
			x = a;
			y = l;
		} else if(v == 2) {
			y = a;
			x = a - l;
		} else if(v == 3) {
			x = 0;
			y = a - l;
		}
		//cerr << v << ' ' << x << ' ' << y << '\n';
		printf("%.9f %.9f\n", x, y);
	}
	return 0;
}