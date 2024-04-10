#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct Cost {
	int64_t a = 0, b = 0, c = 0, d = 0, bc = 0;
};

inline Cost operator+(const Cost &a, const Cost &b) {
	return {a.a + b.a, a.b + b.b, a.c + b.c, a.d + b.d, a.bc + b.bc};
}

struct Point {
	int64_t x, y;
};

struct Rect {
	Point pa, pb, pc, pd;
	
	Rect() {}
	
	Rect(Point p1, Point p2)
		: pa(p1), pb({p1.x, p2.y}), pc({p2.x, p1.y}), pd(p2) {
	}
};

inline int64_t progr(int64_t a, int64_t b) {
	return (a + b) * (abs(b - a) + 1) / 2;
}

inline int64_t dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline int64_t prDist(Point pivot, Point p1, Point p2) {
	return progr(dist(pivot, p1), dist(pivot, p2));
}

inline Cost moveAll(Rect r, Point src, Point dst) {
	return {
		prDist(r.pa, src, dst) - dist(r.pa, src),
		prDist(r.pb, src, dst) - dist(r.pb, src),
		prDist(r.pc, src, dst) - dist(r.pc, src),
		prDist(r.pd, src, dst) - dist(r.pd, src),
		0
	};
}

inline Cost getCost(Point dim, Point p1, Point p2, Point cur) {
	int segX = (cur.x < p1.x) ? 0 : ((cur.x < p2.x) ? 1 : 2);
	int segY = (cur.y < p1.y) ? 0 : ((cur.y < p2.y) ? 1 : 2);
	int seg = segX*3 + segY;
	Rect r(p1, p2);
	
	auto moveToDst = [&](Point dst) {
		return getCost(dim, p1, p2, dst) + moveAll(r, cur, dst);
	};
	
	switch (seg) {
		case 0: {
			return moveToDst(p1);
		} break;
		case 1: {
			return moveToDst({p1.x, cur.y});
		} break;
		case 2: {
			return moveToDst({p1.x, cur.y});
		} break;
		case 3: {
			return moveToDst({cur.x, p1.y});
		} break;
		case 4: {
			int64_t dx = p2.x - cur.x, dy = p2.y - cur.y;
			int64_t bNear = dy * (cur.x - p1.x) + progr(dy, 0) + progr(cur.x - p1.x, p2.x - p1.x);
			int64_t cNear = dx * (cur.y - p1.y) + progr(dx, 0) + progr(cur.y - p1.y, p2.y - p1.y);
			int64_t diff = 2 * dx * dy;
			Cost c {
				prDist(p1, cur, p2) - dist(r.pa, cur),
				bNear - dist(r.pb, cur),
				cNear - dist(r.pc, cur),
				prDist(p2, cur, p2) - dist(r.pd, cur),
				diff
			};
			return c + getCost(dim, p1, p2, p2);
		} break;
		case 5: {
			return moveToDst({p2.x, cur.y});
		} break;
		case 6: {
			return moveToDst({cur.x, p1.y});
		} break;
		case 7: {
			return moveToDst({cur.x, p2.y});
		} break;
		case 8: {
			return moveAll(r, cur, {dim.x-1, dim.y-1});
		} break;
		default: {
			assert(false);
		}
	}
}

struct Sensor {
	int64_t ca, cb, cc, cd;
	Rect r;
	
	inline bool ok() {
		return ca >= 0 && cb >= 0 && cc >= 0 && cd >= 0;
	}
	
	inline void degrade(Point p) {
		ca -= dist(p, r.pa);
		cb -= dist(p, r.pb);
		cc -= dist(p, r.pc);
		cd -= dist(p, r.pd);
	}
	
	Sensor(int64_t t, Rect r)
		: ca(t), cb(t), cc(t), cd(t), r(r) {
	}
};

inline bool canReach(Point dim, Sensor s, Point cur) {
	Cost c = getCost(dim, s.r.pa, s.r.pd, cur);
	s.ca -= c.a; s.cb -= c.b; s.cc -= c.c; s.cd -= c.d;
	if (!s.ok()) {
		return false;
	}
	int64_t toAdd = c.bc >> 1;
	int64_t db = s.cb >> 1, dc = s.cc >> 1;
	return toAdd <= db + dc;
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	int64_t n, t, a, b, c; cin >> n >> t >> a >> b >> c;
	Point dim {n, n}, p1 {a-1, b-1}, p2 {a+c-2, b+c-2}, cur {0, 0};
	Rect r(p1, p2);
	Sensor s(t, r);
	if (!canReach(dim, s, cur)) {
		cout << "Impossible" << endl;
		return 0;
	}
	string res = "";
	for (int i = 0; i < 2*n-2; i++) {
		bool goRight;
		if (cur.x == n-1) {
			goRight = false;
		} else if (cur.y == n-1) {
			goRight = true;
		} else {
			Sensor s2 = s;
			s2.degrade({cur.x+1, cur.y});
			goRight = canReach(dim, s2, {cur.x+1, cur.y});
		}
		if (goRight) {
			res += 'R';
			cur.x++;
			s.degrade(cur);
		} else {
			res += 'U';
			cur.y++;
			s.degrade(cur);
		}
	}
	cout << res << endl;
	assert(s.ok());
	return 0;
}