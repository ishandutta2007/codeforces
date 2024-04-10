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

const double pi = acos(-1.0);
const double eps = 1e-8;
const double seps = 1e-6;

void finish_bad() {
	cout << -1 << endl;

	exit(0);
}

void finish_ok(double x) {
	cout.precision(20);

	cout << x << endl;
	exit(0);
}

int main() {
	double y1, y2, yw, xb, yb, r;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> y1 >> y2 >> yw >> xb >> yb >> r;

	if (xb < r + eps)
		finish_bad();

	double ytp = y1 + r + seps;
	double h = (yw - r - yb) / (yw - r - ytp) + 1;
	double xans = xb / h;

	//if (xans < r + eps)
	//	finish_bad();

	double vx = - (yw - ytp - r), vy = xans;
	double k = sqrt(vx * vx + vy * vy);
	vx /= k;
	vy /= k;

	if (vy * (y2 - ytp) < r + eps)
		finish_bad();

	finish_ok(xans);

	return 0;
}