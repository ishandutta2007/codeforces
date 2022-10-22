#include <bits/stdc++.h>
#define dist(a,b) sqrt(((a).x - (b).x) * ((a).x - (b).x) + ((a).y - (b).y) * ((a).y - (b).y))
#define double long double
using namespace std;

const double pi = 3.14159265358979323846;

struct Point {
	double x, y;
};

int main () {
	Point a, b; double r1, r2;
	cin >> a.x >> a.y >> r1 >> b.x >> b.y >> r2;
	if (r1 > r2) swap(a, b), swap(r1, r2);
	double d = dist(a, b);
	if (r1 + r2 <= d) {
		printf("0\n");
		return 0;
	}
	if (r1 + d <= r2) {
		#undef double
		printf("%.6f\n", (double)(r1 * r1 * pi));
		#define double long double
		return 0;
	}
	double arg1 = acos((r1 * r1 + d * d - r2 * r2) / r1 / d / 2);
	double arg2 = acos((r2 * r2 + d * d - r1 * r1) / r2 / d / 2);
	double area1 = arg1 * r1 * r1 - cos(arg1) * r1 * r1 * sin(arg1);
	double area2 = arg2 * r2 * r2 - cos(arg2) * r2 * r2 * sin(arg2);
	#undef double
	printf("%.6f\n", (double)(area1 + area2));
	return 0;
}