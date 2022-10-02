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


#define y1 yyy1



double x1, y1, x2, y2, v, t, vx, vy, wx, wy;


bool get(double m) {
	double x3 = vx * min(m, t) + x1 + max(0.0, m - t) * wx;
	double y3 = vy * min(m, t) + y1 + max(0.0, m - t) * wy;
	double d = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	return d / v <= m;
}



int main() {
	cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;
	double l = 0.0;
	double r = 1000000000.0;
	for (int i = 0; i < 2000; i++) {
		double m = (l + r) / 2.0;
		if (get(m)) {
			r = m;
		} else {
			l = m;
		}
	}
	printf("%.10lf\n", l);
    return 0;
}