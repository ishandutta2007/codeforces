#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);\
const int iter = 5 * 1000 * 1000;
const double eps = 1e-8;

double w, h, al;
double x[2][4], y[2][4];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> w >> h >> al;

	al = al / 180 * pi;

	x[0][0] = w / 2;
	x[0][1] = w / 2;
	x[0][2] = -w / 2;
	x[0][3] = -w / 2;
	y[0][0] = -h / 2;
	y[0][1] = h / 2;
	y[0][2] = h / 2;
	y[0][3] = -h / 2;
	
	for (int i = 0; i < 4; i++) {
		x[1][i] = x[0][i] * cos(al) - y[0][i] * sin(al);
		y[1][i] = x[0][i] * sin(al) + y[0][i] * cos(al);
	}

	double lb = w / 2;
	double rb = -w / 2;
	for (int i = 0; i < 4; i++) {
		lb = min(lb, x[1][i]);
		rb = max(rb, x[1][i]);
	}

	lb = max(lb, -w / 2);
	rb = min(rb, w / 2);

	double stp = (rb - lb) / iter;
	double ans = 0;

	for (int i = 0; i < iter; i++) {
		double xc = lb + stp * i + stp / 2;
		double mx = -h / 2;
		double mn = h / 2;

		for (int j = 0; j < 4; j++)
			if (fabs(x[1][j] - xc) < eps) {
				mx = max(mx, y[1][j]);
				mn = min(mn, y[1][j]);
			} else {
				if (fabs(x[1][j] - x[1][(j + 1) % 4]) > eps && (x[1][j] - xc) * (x[1][(j + 1) % 4] - xc) < 0) {
					double yc = y[1][j] + (y[1][(j + 1) % 4] - y[1][j]) / (x[1][(j + 1) % 4] - x[1][j]) * (xc - x[1][j]);

					mx = max(yc, mx);
					mn = min(yc, mn);
				}
			}

		//cout << mx << ' ' << mn << endl;

		mx = min(mx, h / 2);
		mn = max(mn, -h / 2);
		ans += max(0.0, mx - mn);
	}

	cout.precision(20);
	cout << ans * stp << endl;

	return 0;
}