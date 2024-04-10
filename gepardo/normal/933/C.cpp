#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

struct DoubleContainer {
	long double d;
};

inline DoubleContainer dc(long double d) {
	return {d};
}

const long double eps = 1e-12;

inline bool operator==(const DoubleContainer &a, const DoubleContainer& b) {
	return abs(a.d - b.d) < eps;
}

inline bool operator<(const DoubleContainer &a, const DoubleContainer &b) {
	return (a == b) ? false : (a.d < b.d);
}

inline bool operator>(const DoubleContainer &a, const DoubleContainer &b) {
	return (a == b) ? false : (a.d > b.d);
}

struct Point {
	long double x, y;
	
	inline auto toPair() const {
		return make_pair(dc(x), dc(y));
	};
};

inline bool operator<(const Point &a, const Point &b) {
	return a.toPair() < b.toPair();
}

inline vector<Point> _intr(long double r1, Point p2, long double r2) {
	long double K = 2*p2.x, L = 2*p2.y, M = p2.x*p2.x + p2.y*p2.y + r1*r1 - r2*r2;
	if (L == 0) {
		return {};
	}
	long double A = K*K + L*L, B = -2*M*K, C = M*M - L*L * r1*r1;
	long double D = B*B - 4*A*C;
	if (dc(D) < dc(0)) {
		return {};
	} else if (dc(D) == dc(0)) {
		long double x1 = -B / (2*A);
		long double y1 = (M - K*x1) / L;
		return {{x1, y1}};
	} else {
		long double x1 = (-B + sqrt(D)) / (2*A);
		long double x2 = (-B - sqrt(D)) / (2*A);
		long double y1 = (M - K*x1) / L;
		long double y2 = (M - K*x2) / L;
		return {{x1, y1}, {x2, y2}};
	}
}

inline vector<Point> intr(Point p1, long double r1, Point p2, long double r2) {
	Point pt {p2.x - p1.x, p2.y - p1.y};
	bool swp = false;
	if (pt.y == 0) {
		swp = true;
		swap(pt.x, pt.y);
	}
	auto res = _intr(r1, pt, r2);
	for (auto &it: res) {
		if (swp) {
			swap(it.x, it.y);
		}
		it.x += p1.x;
		it.y += p1.y;
	}
	return res;
}

class DisjointSetUnion {
private:
	int n;
	int knt;
	vector<int> p;
	vector<int> sz;
public:
	inline int kount() const {
		return knt;
	}
	
	int parent(int v) {
		if (p[v] < 0) {
			return v;
		} else {
			return p[v] = parent(p[v]);
		}
	}
	
	inline bool merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return false;
		}
		knt--;
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
		return true;
	}
	
	DisjointSetUnion(int n)
		: n(n), knt(n), p(n, -1), sz(n, 1) {
	}
};

int main() {
	int n; cin >> n;
	vector<Point> v(n);
	vector<long double> r(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> r[i];
	}
	
	map<Point, int> pts;
	DisjointSetUnion dsu(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			auto q = intr(v[i], r[i], v[j], r[j]);
			for (auto it: q) {
				pts[it]++;
			}
			if (!q.empty()) {
				dsu.merge(i, j);
			}
		}
	}
	
	int ans = dsu.kount() + 1;
	for (auto it: pts) {
		int q = 1;
		while (it.second != 0) {
			it.second -= q;
			q++;
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}