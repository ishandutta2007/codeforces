#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_d"

const double pi = acos(-1.0);
const int size = 10 * 1000 + 10;
const double eps = 1e-8;
const int iters = 65;
const double fi = (sqrt(5.0) - 1.0) / 2.0;

int xc1[size], yc1[size], xc2[size], yc2[size];
int n, m;
int px, py, qx, qy;

long long sqr(long long d) {
	return d * d;
}

double sqrd(double x) {
	return x * x;
}

double getdist(double xc1, double yc1, double xc2, double yc2) {
	double vx1 = xc1 - xc2;
	double vy1 = yc1 - yc2;

	double nxb = xc2 - (xc2 - qx) * 2;
	double nyb = yc2 - (yc2 - qy) * 2;
	double nxa = xc1 - (xc1 - px) * 2;
	double nya = yc1 - (yc1 - py) * 2;

	double vx2 = nxb - nxa;
	double vy2 = nyb - nya;

	double cenx = (vx1 + vx2) / 2;
	double ceny = (vy1 + vy2) / 2;

	double d1 = sqrd(vx1 - cenx) + sqrd(vy1 - ceny);
	double d2 = sqrd(cenx) + sqrd(ceny);

	return fabs(d2 - d1);
}

long long getdiff(int a, int b) {
	int vx1 = xc1[a] - xc2[b];
	int vy1 = yc1[a] - yc2[b];

	int nxb = xc2[b] - (xc2[b] - qx) * 2;
	int nyb = yc2[b] - (yc2[b] - qy) * 2;
	int nxa = xc1[a] - (xc1[a] - px) * 2;
	int nya = yc1[a] - (yc1[a] - py) * 2;

	int vx2 = nxb - nxa;
	int vy2 = nyb - nya;

	vx1 *= 2;
	vx2 *= 2;
	vy1 *= 2;
	vy2 *= 2;

	int cenx = (vx1 + vx2) / 2;
	int ceny = (vy1 + vy2) / 2;

	long long d1 = sqr(vx1 - cenx) + sqr(vy1 - ceny);
	long long d2 = sqr(cenx) + sqr(ceny);

	return d2 - d1;
}

bool onborder(int a, int b) {
	return getdiff(a, b) == 0ll;
}

bool inside(int a, int b) {
	return getdiff(a, b) < 0ll;
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	int n = 1000;
	cout << rand() << ' ' << rand() << endl;
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << rand() << ' ' << rand() << endl;
	cout << rand() << ' ' << rand() << endl;
	
	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << rand() << ' ' << rand() << endl;
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &px, &py);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &xc1[i], &yc1[i]);
	scanf("%d%d", &qx, &qy);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &xc2[i], &yc2[i]);

	bool flag = false;
	for (int it = 0; it < 2; it++) {
		for (int i = 0; i < n; i++) {
	//		if (flag)
	//			break;
			int p1 = i;
			int p2 = (i + 1) % n;

			for (int j = 0; j < m; j++) {
				if (onborder(p1, j))
					flag = true;
				if (onborder(p2, j))
					flag = true;
				double lb = 0.0;
				double rb = 1.0;
				double v1, v2, res;
				bool f1 = false, f2 = false;
				for (int it = 0; it < iters; it++) {
					double k1 = lb + (rb - lb) * (1 - fi);
					double k2 = lb + (rb - lb) * fi;
					double d1, d2;
					if (f1) {
						d1 = res;
						f1 = false;
					} else {
						d1 = getdist(xc1[p1] * k1 + xc1[p2] * (1 - k1), yc1[p1] * k1 + yc1[p2] * (1 - k1), xc2[j], yc2[j]);
					}
					if (f2) {
						d2 = res;
						f2 = false;
					} else {
						d2 = getdist(xc1[p1] * k2 + xc1[p2] * (1 - k2), yc1[p1] * k2 + yc1[p2] * (1 - k2), xc2[j], yc2[j]);
					}

					if (d1 < d2) {
						f2 = true;
						res = d1;
						rb = k2;
					} else {
						f1 = true;
						res = d2;
						lb = k1;
					}
				}

				double k = (lb + rb) / 2.0;
				double d = getdist(xc1[p1] * k + xc1[p2] * (1 - k), yc1[p1] * k + yc1[p2] * (1 - k), xc2[j], yc2[j]);
				
				if (fabs(d) < eps)
					flag = true;
			}
		}
		
		int tot = max(n, m);
		for (int i = 0; i < tot; i++) {
			swap(xc1[i], xc2[i]);
			swap(yc1[i], yc2[i]);
		}

		swap(n, m);
		swap(px, qx);
		swap(py, qy);
	}

	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	//cout << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

	return 0;
}