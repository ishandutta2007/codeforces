#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
struct point {
	int x, y;
};

point p[1500];

long long S2(point a, point b, point c) {
	return abs((b.x - a.x) * 1ll * (c.y - a.y) - (b.y - a.y) * 1ll * (c.x - a.x));
}

ld dist(point a, point b) {
	return sqrtl((a.x - b.x) * 1. * (a.x - b.x) + (a.y - b.y) * 1. * (a.y - b.y));
}
int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n;
	cin >> n;
	int x, y;
	ld m = 1e10;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i] = point{ x, y };
	}
	p[n] = p[0];
	p[n + 1] = p[1];
	for (int i = 0; i < n; i++) {
		long long s2 = S2(p[i], p[i + 1], p[i + 2]);
		ld d = dist(p[i], p[i + 2]);
		ld h = s2 / d;
		ld half = h / 2;
		m = min(m, half);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ld d = dist(p[i], p[j]);
			m = min(m, d / 2);
		}
	}
	cout << fixed << setprecision(17) << m << endl;
	return 0;
}