#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


struct point{
	double x, y;
	point(){}
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	point(point a, point b) {
		x = b.x - a.x;
		y = b.y - a.y;
	}
};


double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main() {
	point p, v;
	cin >> p.x >> p.y >> v.x >> v.y;
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	point t = point(p.x - v.y / dist(point(0.0, 0.0), v) * a / 2.0, p.y + v.x / dist(point(0.0, 0.0), v) * a / 2.0);
	point t1 = point(p.x + v.y / dist(point(0.0, 0.0), v) * a / 2.0, p.y - v.x / dist(point(0.0, 0.0), v) * a / 2.0);
	point t2 = point(p.x + v.x / dist(point(0.0, 0.0), v) * b, p.y + v.y / dist(point(0.0, 0.0), v) * b);
	point t3 = point(t.x + v.y / dist(point(0.0, 0.0), v) * (a - c) / 2.0, t.y - v.x / dist(point(0.0, 0.0), v) * (a - c) / 2.0);
	point t4 = point(t1.x - v.y / dist(point(0.0, 0.0), v) * (a - c) / 2.0, t1.y + v.x / dist(point(0.0, 0.0), v) * (a - c) / 2.0);
	point t5 = point(t3.x - v.x / dist(point(0.0, 0.0), v) * d, t3.y - v.y / dist(point(0.0, 0.0), v) * d);
	point t6 = point(t4.x - v.x / dist(point(0.0, 0.0), v) * d, t4.y - v.y / dist(point(0.0, 0.0), v) * d);
	printf("%.10lf %.10lf\n", t2.x, t2.y);
	printf("%.10lf %.10lf\n", t.x, t.y);
	printf("%.10lf %.10lf\n", t3.x, t3.y);
	printf("%.10lf %.10lf\n", t5.x, t5.y);
	printf("%.10lf %.10lf\n", t6.x, t6.y);
	printf("%.10lf %.10lf\n", t4.x, t4.y);
	printf("%.10lf %.10lf\n", t1.x, t1.y);
	return 0;
}