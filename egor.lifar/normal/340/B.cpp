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


struct point{
	int x, y;
	point(){}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
};



int n;
point p[300];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double ans1 = 0.0;
			for (int k = 0; k < n; k++) {
				if (k != i && k != j) {
					point s1 = point(p[j].x - p[i].x, p[j].y - p[i].y);
					point s = point(p[k].x - p[i].x, p[k].y - p[i].y);
					if (s.x * s1.y - s1.x * s.y > 0) {
						//cout << "opa" << endl;
						ans1 = max(ans1, fabs((s.x * s1.y - s1.x * s.y)) / 2.00);
					}
				}
			}
			double ans2 = 0.0;
			for (int k = 0; k < n; k++) {
				if (k != i && k != j) {
					point s1 = point(p[j].x - p[i].x, p[j].y - p[i].y);
					point s = point(p[k].x - p[i].x, p[k].y - p[i].y);
					if (s.x * s1.y - s1.x * s.y < 0) {
						//cout << "op" << endl;
						ans2 = max(ans2, fabs((s.x * s1.y - s1.x * s.y)) / 2.00);
					}
				}
			}
			if (ans2 > 0 && ans1 > 0) {
				ans = max(ans, ans1 + ans2);
			}
			//cout << ans1 << ' ' << ans2 << endl;
			//cout << i << ' ' << j << endl;
		}
	}
	printf("%.10lf\n", ans);
    return 0;
}