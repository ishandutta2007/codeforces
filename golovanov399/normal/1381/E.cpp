#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Point {
	int x, y;

	bool operator <(const Point& p) const {
		return tie(x, y) < tie(p.x, p.y);
	}

	bool operator ==(const Point& p) const {
		return tie(x, y) == tie(p.x, p.y);
	}

	bool operator !=(const Point& p) const {
		return tie(x, y) != tie(p.x, p.y);
	}
};

Point operator -(const Point& p, const Point& q) {
	return {p.x - q.x, p.y - q.y};
}

long long vprod(const Point& p, const Point& q) {
	return 1ll * p.x * q.y - 1ll * p.y * q.x;
}

// __int128_t gcd(__int128_t x, __int128_t y) {
// 	if (x < 0) {
// 		x = -x;
// 	}
// 	if (y < 0) {
// 		y = -y;
// 	}
// 	while (y) {
// 		x %= y;
// 		swap(x, y);
// 	}
// 	return x;
// }

// struct Rational {
// 	__int128_t x, y;

// 	Rational(__int128_t c = 0): x(c), y(1) {}
// 	Rational(__int128_t _x, __int128_t _y): x(_x), y(_y) {
// 		if (y < 0) {
// 			x *= -1;
// 			y *= -1;
// 		}
// 		__int128_t g = gcd(x, y);
// 		x /= g;
// 		y /= g;
// 	}

// 	Rational operator +(const Rational& ot) const {
// 		return Rational(x * ot.y + y * ot.x, y * ot.y);
// 	}

// 	Rational& operator +=(const Rational& ot) {
// 		return *this = Rational(x * ot.y + y * ot.x, y * ot.y);
// 	}

// 	Rational operator -(const Rational& ot) const {
// 		return Rational(x * ot.y - y * ot.x, y * ot.y);
// 	}

// 	Rational& operator -=(const Rational& ot) {
// 		return *this = Rational(x * ot.y - y * ot.x, y * ot.y);
// 	}

// 	Rational operator *(const Rational& ot) const {
// 		return Rational(x * ot.x, y * ot.y);
// 	}

// 	Rational& operator *=(const Rational& ot) {
// 		return *this = Rational(x * ot.x, y * ot.y);
// 	}

// 	Rational operator /(const Rational& ot) const {
// 		return Rational(x * ot.y, y * ot.x);
// 	}

// 	Rational operator -() const {
// 		return Rational(-x, y);
// 	}

// 	bool operator <(const Rational& ot) const {
// 		return x * ot.y < y * ot.x;
// 	}

// 	bool operator ==(const Rational& ot) const {
// 		return x * ot.y == y * ot.x;
// 	}
// };

// string to_string(__int128_t x) {
// 	string res = "";
// 	if (x < 0) {
// 		res += '-';
// 		x = -x;
// 	}
// 	string q = "";
// 	while (x) {
// 		q += (char)('0' + x % 10);
// 		x /= 10;
// 	}
// 	if (q.empty()) {
// 		q = "0";
// 	}
// 	reverse(all(q));
// 	return res + q;
// }

// ostream& operator <<(ostream& ostr, const Rational& r) {
// 	return ostr << ((long long)(r.x / r.y) + (long double)(r.x % r.y) / r.y);
// }

// string to_string(const Rational& r) {
// 	if (r.y == 1) {
// 		return to_string(r.x);
// 	} else {
// 		return to_string(r.x) + "/" + to_string(r.y);
// 	}
// }

// using ld = Rational;
using ld = __float128;

#define Rational ld

struct Quad {
	ld a, b, c;

	ld at(ld x) const {
		return c + x * (b + x * a);
	}

	void operator +=(const Quad& ot) {
		a += ot.a;
		b += ot.b;
		c += ot.c;
	}

	void operator -=(const Quad& ot) {
		a -= ot.a;
		b -= ot.b;
		c -= ot.c;
	}

	Quad operator +(const Quad& ot) const {
		return {a + ot.a, b + ot.b, c + ot.c};
	}

	Quad operator -(const Quad& ot) const {
		return {a - ot.a, b - ot.b, c - ot.c};
	}
};

ostream& operator <<(ostream& ostr, const Point& p) {
	return ostr << "(" << p.x << ", " << p.y << ")";
}

ld get_x(const Point& low, const Point& high, ld y) {
	return Rational(high.x - low.x) / (high.y - low.y) * (y - low.y) + low.x;
}

pair<ld, ld> getLinear(const Point& p, const Point& q) {
	return {Rational(p.y - q.y) / (p.x - q.x), (Rational(p.x) / (p.x - q.x) * q.y - Rational(p.y) / (p.x - q.x) * q.x)};
}

struct SegTree {
	int n;
	vector<Quad> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.assign(n + n, {0, 0, 0});
	}

	void add(int v, int l1, int r1, int l, int r, const Quad& q) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v] += q;
			return;
		}
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, q);
		add(v + v + 1, m, r1, l, r, q);
	}

	void add(int l, int r, const Quad& q) {
		add(1, 0, n, l, r, q);
	}

	void pushall() {
		for (int i = 1; i < n; ++i) {
			a[i + i] += a[i];
			a[i + i + 1] += a[i];
		}
	}
};

const ld eps = 1e-11;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].x = nxt(), a[i].y = nxt();
	}
	vector<int> qrs(q);
	for (int& x : qrs) {
		x = nxt();
	}

	vector<ld> xs;
	vector<int> ys = {};
	for (auto p : a) {
		xs.push_back(p.x);
		ys.push_back(p.y);
	}
	make_unique(ys);

	long long S = 0;
	for (int i = 0; i < n; ++i) {
		S += vprod(a[i], a[(i + 1) % n]);
	}
	if (S < 0) {
		reverse(all(a));
		S = -S;
	}

	auto nx = [&](int i) {
		return i == n - 1 ? 0 : i + 1;
	};
	auto pr = [&](int i) {
		return i == 0 ? n - 1 : i - 1;
	};

	int idx = min_element(all(a), [&](const Point& p, const Point& q) {
		return make_pair(p.y, -p.x) < make_pair(q.y, -q.x);
	}) - a.begin();

	int r = idx;
	int l = idx;
	if (a[pr(l)].y == a[l].y) {
		l = pr(l);
	}

	int oldl = l, oldr = r;
	for (int i = 0; i < (int)ys.size() - 1; ++i) {
		int uy = ys[i + 1];
		int dy = ys[i];

		xs.push_back((get_x(a[r], a[nx(r)], dy) + get_x(a[l], a[pr(l)], dy)) / 2);
		xs.push_back((get_x(a[r], a[nx(r)], uy) + get_x(a[l], a[pr(l)], uy)) / 2);

		while (uy == a[pr(l)].y) {
			l = pr(l);
		}
		while (uy == a[nx(r)].y) {
			r = nx(r);
		}
	}
	l = oldl, r = oldr;
	make_unique(xs);
	const int sz = xs.size();

	// for (auto y : ys) {
	// 	cerr << y << " ";
	// }
	// cerr << "\n";

	// vector<Quad> qs(sz);
	SegTree st(sz);
	cerr << setprecision(14) << fixed;
	auto upd = [&](ld x1, ld x2, const Quad& q) {
		// cerr << "from " << (long double)x1 << " to " << (long double)x2 << ": (" << (long double)(q.a) << ", " << (long double)(q.b) << ", " << (long double)(q.c) << ")\n";
		st.add(lower_bound(all(xs), x1) - xs.begin(), lower_bound(all(xs), x2) - xs.begin(), q);
		// qs[lower_bound(all(xs), x1) - xs.begin()] += q;
		// qs[lower_bound(all(xs), x2) - xs.begin()] -= q;
	};
	auto addL = [&](int y1, int y2, const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
		ld dxl = get_x(p1, p2, y1);
		ld dxr = (get_x(p1, p2, y1) + get_x(p3, p4, y1)) / 2;
		ld uxl = get_x(p1, p2, y2);
		ld uxr = (get_x(p1, p2, y2) + get_x(p3, p4, y2)) / 2;

		vector<tuple<ld, int, ld, ld>> events;
		pair<ld, ld> low, high;
		if (dxl < uxl - eps) {
			low = {0, y1};
			high = getLinear(p1, p2);
			if (p2 != p4) {
				events.push_back({uxl, 1, 0, (ld)y2});
			}
		} else if (uxl < dxl - eps) {
			low = getLinear(p2, p1);
			high = {0, y2};
			if (p1 != p3) {
				events.push_back({dxl, -1, 0, (ld)y1});
			}
		} else {
			low = {0, y1};
			high = {0, y2};
		}
		if (dxr < uxr - eps) {
			events.push_back({dxr, -1, Rational(y2 - y1) / (uxr - dxr), dxr / (dxr - uxr) * y2 - uxr / (dxr - uxr) * y1});
			events.push_back({uxr, 0, 0, 0});
		} else if (uxr < dxr - eps) {
			events.push_back({uxr, 1, Rational(y2 - y1) / (uxr - dxr), dxr / (dxr - uxr) * y2 - uxr / (dxr - uxr) * y1});
			events.push_back({dxr, 0, 0, 0});
		} else {
			events.push_back({uxr, 0, 0, 0});
		}
		ld x = min(dxl, uxl);
		sort(all(events));
		auto [e, f] = getLinear({p1.y, p1.x}, {p2.y, p2.x});
		for (const auto& [xx, t, aa, bb] : events) {
			auto [a, b] = low;
			auto [c, d] = high;
			ld A = 0, B = 0, C = 0;
			A = e * (c - a) * (c + a) / 2;
			B = f * (c - a) + e * (c * d - a * b);
			C = (d - b) * (f + e * (d + b) / 2);
			upd(x, xx, {-A + c - a, -B + d - b, -C});
			if (t > 0) {
				high = {aa, bb};
			} else {
				low = {aa, bb};
			}
			x = xx;
		}
	};
	auto addR = [&](int y1, int y2, Point p3, Point p4, Point p1, Point p2) {
		p1.x *= -1;
		p2.x *= -1;
		p3.x *= -1;
		p4.x *= -1;

		ld dxl = get_x(p1, p2, y1);
		ld dxr = (get_x(p1, p2, y1) + get_x(p3, p4, y1)) / 2;
		ld uxl = get_x(p1, p2, y2);
		ld uxr = (get_x(p1, p2, y2) + get_x(p3, p4, y2)) / 2;

		vector<tuple<ld, int, ld, ld>> events;
		pair<ld, ld> low, high;
		if (dxl < uxl - eps) {
			low = {0, y1};
			high = getLinear(p1, p2);
			if (p2 != p4) {
				events.push_back({uxl, 1, 0, (ld)y2});
			}
		} else if (uxl < dxl - eps) {
			low = getLinear(p2, p1);
			high = {0, y2};
			if (p1 != p3) {
				events.push_back({dxl, -1, 0, (ld)y1});
			}
		} else {
			low = {0, y1};
			high = {0, y2};
		}
		if (dxr < uxr - eps) {
			events.push_back({dxr, -1, Rational(y2 - y1) / (uxr - dxr), dxr / (dxr - uxr) * y2 - uxr / (dxr - uxr) * y1});
			events.push_back({uxr, 0, 0, 0});
		} else if (uxr < dxr - eps) {
			events.push_back({uxr, 1, Rational(y2 - y1) / (uxr - dxr), dxr / (dxr - uxr) * y2 - uxr / (dxr - uxr) * y1});
			events.push_back({dxr, 0, 0, 0});
		} else {
			events.push_back({uxr, 0, 0, 0});
		}
		ld x = min(dxl, uxl);
		sort(all(events));
		auto [e, f] = getLinear({p1.y, p1.x}, {p2.y, p2.x});
		for (const auto& [xx, t, aa, bb] : events) {
			auto [a, b] = low;
			auto [c, d] = high;
			ld A = 0, B = 0, C = 0;
			A = e * (c - a) * (c + a) / 2;
			B = f * (c - a) + e * (c * d - a * b);
			C = (d - b) * (f + e * (d + b) / 2);
			upd(-xx, -x, {-A + c - a, -(-B + d - b), -C});
			if (t > 0) {
				high = {aa, bb};
			} else {
				low = {aa, bb};
			}
			x = xx;
		}
	};

	for (int i = 0; i < (int)ys.size() - 1; ++i) {
		int uy = ys[i + 1];
		int dy = ys[i];

		addL(dy, uy, a[l], a[pr(l)], a[r], a[nx(r)]);
		addR(dy, uy, a[l], a[pr(l)], a[r], a[nx(r)]);

		while (uy == a[pr(l)].y) {
			l = pr(l);
		}
		while (uy == a[nx(r)].y) {
			r = nx(r);
		}
	}
	st.pushall();
	// for (int i = 1; i < sz; ++i) {
	// 	qs[i] += qs[i - 1];
	// }

	cout << setprecision(10) << fixed;
	cout.sync_with_stdio(false);
	for (auto x : qrs) {
		int idx = upper_bound(all(xs), Rational(x)) - xs.begin() - 1;
		// auto tmp = qs[idx].at(x);
		auto tmp = st.a[st.n + idx].at(x);
		// cout << (long double)st.a[st.n + idx].a << " " << (long double)st.a[st.n + idx].b << " " << (long double)st.a[st.n + idx].c << " - ";
		// cout << (long double)xs[idx] << " " << (long double)xs[idx + 1] << " ";
		// cout <<              x << " " << (long double)tmp << " : ";
		cout << (long double)(S * 0.5 - tmp) << "\n";
	}

	return 0;
}