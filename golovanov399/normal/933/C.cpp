#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

using ld = long double;

const ld eps = 1e-9;

bool lt(ld x, ld y) {
	return x < y - eps;
}

bool le(ld x, ld y) {
	return x < y + eps;
}

bool eq(ld x, ld y) {
	return le(x, y) && le(y, x);
}

struct Point {
	ld x, y;

	bool operator <(const Point& p) const {
		return lt(x, p.x) || (le(x, p.x) && lt(y, p.y));
	}

	bool operator ==(const Point& p) const {
		return eq(x, p.x) && eq(y, p.y);
	}

	Point operator -(const Point& p) const {
		return {x - p.x, y - p.y};
	}

	Point operator +(const Point& p) const {
		return {x + p.x, y + p.y};
	}

	Point rot(ld phi) const {
		ld nx = x * cosl(phi) - y * sinl(phi);
		ld ny = x * sinl(phi) + y * cosl(phi);
		return {nx, ny};
	}

	ld len() const {
		return sqrtl(x * x + y * y);
	}
};

bool isAdj(Point c1, ld r1, Point c2, ld r2) {
	ld d = (c1 - c2).len();
	if (lt(r1 + r2, d) || lt(d, abs(r1 - r2))) {
		return false;
	}
	return true;
}

void add(vector<Point>& pts, Point c1, ld r1, Point c2, ld r2) {
	ld d = (c1 - c2).len();
	if (lt(r1 + r2, d) || lt(d, abs(r1 - r2))) {
		return;
	}

	if (eq(r1 + r2, d)) {
		Point v = c2 - c1;
		v.x *= (r1 / (r1 + r2));
		v.y *= (r1 / (r1 + r2));
		pts.push_back(c1 + v);
	} else if (eq(r1 - r2, d)) {
		Point v = c2 - c1;
		v.x *= (r1 / (r1 - r2));
		v.y *= (r1 / (r1 - r2));
		pts.push_back(c1 + v);
	} else if (eq(r2 - r1, d)) {
		swap(r1, r2);
		swap(c1, c2);
		Point v = c2 - c1;
		v.x *= (r1 / (r1 - r2));
		v.y *= (r1 / (r1 - r2));
		pts.push_back(c1 + v);
	} else {
		ld phi = acosl((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
		Point v = c2 - c1;
		v.x *= (r1 / d);
		v.y *= (r1 / d);
		pts.push_back(c1 + v.rot(phi));
		pts.push_back(c1 + v.rot(-phi));
	}
}

int main() {
	int n = nxt();
	vector<Point> p(n);
	vector<ld> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y >> r[i];
	}

	vector<Point> pts;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			add(pts, p[i], r[i], p[j], r[j]);
		}
	}

	make_unique(pts);
	int num_ver = pts.size();
	int num_edges = 0;

	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (auto pt : pts) {
			if (eq((pt - p[i]).len(), r[i])) {
				++cnt;
			}
		}
		if (cnt == 0) {
			++num_edges;
			++num_ver;
		} else {
			num_edges += cnt;
		}
	}

	int num_comps = 1;
	if (n == 2 && !isAdj(p[0], r[0], p[1], r[1])) {
		++num_comps;
	}
	if (n == 3 && !isAdj(p[0], r[0], p[1], r[1]) && !isAdj(p[0], r[0], p[2], r[2])) {
		++num_comps;
	}
	if (n == 3 && !isAdj(p[0], r[0], p[1], r[1]) && !isAdj(p[1], r[1], p[2], r[2])) {
		++num_comps;
	}
	if (n == 3 && !isAdj(p[0], r[0], p[2], r[2]) && !isAdj(p[1], r[1], p[2], r[2])) {
		++num_comps;
	}
	if (n == 3 && !isAdj(p[0], r[0], p[2], r[2]) && !isAdj(p[1], r[1], p[2], r[2]) && !isAdj(p[1], r[1], p[0], r[0])) {
		--num_comps;
	}

	cout << num_comps + 1 + num_edges - num_ver << "\n";

	return 0;
}