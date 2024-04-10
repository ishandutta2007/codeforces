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


using namespace std;


struct point
{
	double x, y;
	point(){}
	point(double _x, double _y) {
		x = _x;
		y = _y;
	}
};


point o;


double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main() {
	cin >> o.x >> o.y;
	int n;
	cin >> n;
	double ans = 1000000000000.0;
	for (int i = 0; i < n; i++) {
		point z;
		double s;
		cin >> z.x >> z.y >> s;
		ans = min(ans, dist(o, z) / s);
	}
	printf("%.10lf\n", ans);
    return 0;
}