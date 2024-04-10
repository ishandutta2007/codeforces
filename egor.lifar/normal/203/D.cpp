#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <math.h>


using namespace std;


#define eps 0.000001
#define INF 1000000000


double a, b, m;
double x, y, z;
double vx, vy, vz;


int main() {
	cin >> a >> b >> m;
	cin >> vx >> vy >> vz;
	x = a / 2.0;
	y = m;
	while (true) {
		//cout << x << ' ' << y << ' ' << z << endl;
		if (abs(y) <= eps) {
			break;
		}
		//return 0;
		double s = INF;
		double s1 = INF;
		double s2 = INF;
		double s3 = INF;
		double s4 = INF;
		if (vy < 0) {
			s = -y / vy;
			if (abs(s) <= eps) {
				s = INF;
			}
		}
		if (vz < 0) {
			s1 = -z / vz;
			if (abs(s1) <= eps) {
				s1 = INF;
			}
		}
		if (vx < 0) {
			s2 = -x / vx;
			if (abs(s2) <= eps) {
				s2 = INF;
			}
		}
		if (vz > 0) {
			s3 = (b - z) / vz;
			if (abs(s3) <= eps) {
				s3 = INF;
			}
		}
		if (vx > 0) {
			s4 = (a - x) / vx;
			if (abs(s4) <= eps) {
				s4 = INF;
			}
		}
		//cout << s << ' ' << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << endl;
		double ans = min(s, min(s1, s2));
		ans = min(ans, min(s3, s4));
		//cout << ans << endl;
		x += vx * ans;
		y += vy * ans;
		z += vz * ans;
		if (abs(ans - s) <= eps) {
			vy *= -1;
		}
		if (abs(ans - s1) <= eps) {
			vz *= -1;
		}
		if (abs(ans - s2) <= eps) {
			vx *= -1;
		}
		if (abs(ans - s3) <= eps) {
			vz *= -1;
		}
		if (abs(ans - s4) <= eps) {
			vx *= -1;
		}
		//cout << x << ' ' << y << ' ' << z << endl;
	}
	printf("%.10lf %.10lf\n", x, z);
    return 0;
}