#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct vec {
	int x, y;
	void read() {
		cin >> x >> y;
		x *= 2, y *= 2;
	}
	void write() {
		cout << x << " " << y << endl;
	}
	void stasyan_ti_chto_nadelal() {
		int newx = x + y;
		int newy = x - y;
		x = newx, y = newy;
	}
	vec operator + (vec a) {
		return { x + a.x, y + a.y };
	}
	vec operator / (int n) {
		return { x / n, y / n };
	}
};

struct sq {
	vec c;
	vector <vec> p;
	sq() { p.resize(4); c = { 0, 0 }; }
	void read() {
		for (int i = 0; i < 4; i++) {
			p[i].read();
			c = c + p[i];
		}
		c = c / 4;
	}
	void write() {
		for (int i = 0; i < 4; i++)
			p[i].write();
		cout << endl;
	}
	void stasyan_ti_chto_nadelal() {
		c = { 0, 0 };
		for (int i = 0; i < 4; i++) {
			p[i].stasyan_ti_chto_nadelal();
			c = c + p[i];
		}
		c = c / 4;
	}
};

int main() {
	sq a, b;
	a.read(), b.read();
	int minX = INF, minY = INF, maxX = -INF, maxY = -INF;
	for (int i = 0; i < 4; i++) {
		minX = min(a.p[i].x, minX);
		maxX = max(a.p[i].x, maxX);
		minY = min(a.p[i].y, minY);
		maxY = max(a.p[i].y, maxY);
	}
	for (int i = 0; i < 4; i++) {
		if (minX <= b.p[i].x && b.p[i].x <= maxX && minY <= b.p[i].y && b.p[i].y <= maxY) {
			cout << "YES";
			return 0;
		}
	}
	if (minX <= b.c.x && b.c.x <= maxX && minY <= b.c.y && b.c.y <= maxY) {
		cout << "YES";
		return 0;
	}
	swap(a, b);
	a.stasyan_ti_chto_nadelal(), b.stasyan_ti_chto_nadelal();
	minX = INF, minY = INF, maxX = -INF, maxY = -INF;
	for (int i = 0; i < 4; i++) {
		minX = min(a.p[i].x, minX);
		maxX = max(a.p[i].x, maxX);
		minY = min(a.p[i].y, minY);
		maxY = max(a.p[i].y, maxY);
	}
	for (int i = 0; i < 4; i++) {
		if (minX <= b.p[i].x && b.p[i].x <= maxX && minY <= b.p[i].y && b.p[i].y <= maxY) {
			cout << "YES";
			return 0;
		}
	}
	if (minX <= b.c.x && b.c.x <= maxX && minY <= b.c.y && b.c.y <= maxY) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}