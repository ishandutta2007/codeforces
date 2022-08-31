#include <cstdio>

#include <iostream>

using namespace std;

struct Vec {
	int x, y;

	Vec() {}

	Vec(int x, int y) : x(x), y(y) {}

	Vec tr() const {
		return Vec(x + y, x - y);
	}
};

Vec a[4], b[4];

istream& operator>>(istream& in, Vec& vec) {
	return in >> vec.x >> vec.y;
}

int main() {
	for (int i = 0; i < 4; ++i)
		cin >> a[i];
	for (int i = 0; i < 4; ++i)
		cin >> b[i];
	int l, r, u, d;
	l = min(a[0].x, a[2].x);
	r = max(a[0].x, a[2].x);
	d = min(a[0].y, a[2].y);
	u = max(a[0].y, a[2].y);
	int ax = b[0].x + b[2].x, ay = b[0].y + b[2].y;
	if (l * 2 <= ax && ax <= r * 2 && d * 2 <= ay && ay <= u * 2) {
		puts("Yes");
		return 0;
	}
	for (int i = 0; i < 4; ++i)
		if (l <= b[i].x && b[i].x <= r && d <= b[i].y && b[i].y <= u) {
			puts("Yes");
			return 0;
		}
	for (int i = 0; i < 4; ++i) {
		a[i] = a[i].tr();
		b[i] = b[i].tr();
	}
	l = min(b[0].x, b[2].x);
	r = max(b[0].x, b[2].x);
	d = min(b[0].y, b[2].y);
	u = max(b[0].y, b[2].y);
	for (int i = 0; i < 4; ++i)
		if (l <= a[i].x && a[i].x <= r && d <= a[i].y && a[i].y <= u) {
			puts("Yes");
			return 0;
		}
	puts("NO");
	return 0;
}