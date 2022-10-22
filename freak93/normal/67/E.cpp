#include <iostream>
#include <algorithm>
#define punct pair<int, int>
#define x first
#define y second
#include <cstdio>

using namespace std;

int mod(int x) {
	if (x < 0)
		return -x;
	return x;
}

typedef long long ll;

int area(punct a, punct b, punct c) {
	ll aux = (ll) a.x * (b.y - c.y) + (ll) b.x * (c.y - a.y) + (ll) c.x * (a.y - b.y);
	if (aux < 0)
		return -1;
	return (aux > 0);
}

const int maxn = 1005;

int n, i, normal, sgn, x, y, j, step;
punct a[maxn], left2, right2;

int main() {
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	a[n + 1] = a[1];
	sgn = a[2].x - a[1].x;
	if (sgn < 0)
		sgn = -1;
	else
		sgn = 1;
	left2 = a[1];
	right2 = a[2];
	for (i = 2; i <= n; ++i) {
		x = area(a[i], a[i + 1], left2);
		y = area(a[i], a[i + 1], right2);
		if (x > 0 && y > 0) {
			cout << "0";
			return 0;
		}
		if (x <= 0 && y <= 0)
			continue;
		if (x <= 0) {
			for (step = 1; step < mod(a[2].x - a[1].x); step <<= 1);
			for (j = left2.x; step; step >>= 1) {
				if (area(a[i], a[i + 1], make_pair(j + step * sgn, left2.y)) <= 0)
					j += step * sgn;
			}
			right2.x = j;
			continue;
		}
		for (step = 1; step < mod(a[2].x - a[1].x); step <<= 1);
		for (j = right2.x; step; step >>= 1) {
			if (area(a[i], a[i + 1], make_pair(j - step * sgn, left2.y)) <= 0)
				j -= step * sgn;
			left2.x = j;
			continue;
		}
	}
	cout << mod(right2.x - left2.x) + 1;
}