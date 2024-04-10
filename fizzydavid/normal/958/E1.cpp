#include <bits/stdc++.h>

using namespace std;
/*
 * author : King_George
 * passed problem : CF933C, UOJ277, CF32E, CF23D, CF54E
*/

namespace geometry {

#ifndef eps
#define eps 1e-3
#endif

#ifndef LINE
#define LINE 0
#endif
#ifndef SEG 
#define SEG 1
#endif
#ifndef RAY
#define RAY 2
#endif

#ifndef IN 
#define IN -1 
#endif
#ifndef ON 
#define ON 0
#endif
#ifndef OUT 
#define OUT 1
#endif

	const double pi = acos(-1);

	inline int sign(const double &x) {
		return x >= eps ? 1 : (x <= -eps ? -1 : 0);
	}

	inline bool is0(const double &x) {
		return sign(x) == 0;
	}

	inline double sqr(const double &x) {
		return x * x;
	}

	inline bool eql(const double &a, const double &b) {
		return is0(a - b);
	}

	struct point {
		double x, y;

		point() {}
		point(double x, double y): x(x), y(y) {}

		inline friend bool operator == (const point &a, const point &b) {
			return eql(a.x, b.x) && eql(a.y, b.y);
		}


		inline friend point operator + (const point &a, const point &b) {
			return point(a.x + b.x, a.y + b.y);
		}

		inline friend point operator - (const point &a, const point &b) {
			return point(a.x - b.x, a.y - b.y);
		}

		inline friend point operator - (const point &a) {
			return point(-a.x, -a.y);
		}

		inline friend point operator * (const point &a, const double &k) {
			return point(k * a.x, k * a.y);
		}

		inline friend point operator * (const double &k, const point &a) {
			return point(k * a.x, k * a.y);
		}

		inline friend point operator / (const point &a, const double &k) {
			return point(a.x / k, a.y / k);
		}

		inline double alpha() const {
			double ret = atan2(y, x);
			return eql(ret, -pi) ? pi : ret;
		}

		inline void in() {
			scanf("%lf%lf", &x, &y);
			return;
		}

		inline void out(int p = 0, char s = '\n') const {
			if(p >= 10) {
				char c[6];
				c[0] = '%';
				c[1] = '.';
				c[2] = p / 10 + '0';
				c[3] = p % 10 + '0';
				c[4] = 'f';
				c[5] = 0;
				printf(c, x);
				printf(" ");
				printf(c, y);
				putchar(s);
			}
			else {
				char c[5];
				c[0] = '%';
				c[1] = '.';
				c[2] = p + '0';
				c[3] = 'f';
				c[4] = 0;
				printf(c, x);
				printf(" ");
				printf(c, y);
				putchar(s);
			}
		}

		inline void debug(int p = 12, char s = '\n') const {
#ifdef DEBUG
			if(p >= 10) {
				char c[6];
				c[0] = '%';
				c[1] = '.';
				c[2] = p / 10 + '0';
				c[3] = p % 10 + '0';
				c[4] = 'f';
				c[5] = 0;
				fprintf(stderr, c, x);
				fprintf(stderr, " ");
				fprintf(stderr, c, y);
				fprintf(stderr, "%c", s);
			}
			else {
				char c[5];
				c[0] = '%';
				c[1] = '.';
				c[2] = p + '0';
				c[3] = 'f';
				c[4] = 0;
				fprintf(stderr, c, x);
				fprintf(stderr, " ");
				fprintf(stderr, c, y);
				fprintf(stderr, "%c", s);
			}
#endif
			return;
		}

		inline double abs2() const  {
			return sqr(x) + sqr(y);
		}

		inline double abs() const  {
			return sqrt(abs2());
		}

		inline point unit() const {
			return *this / abs();
		}

		inline point normal() const {
			return point(-y, x);
		}
	};

	inline point midpoint(const point &a, const point &b) {
		return (a + b) / 2.;
	}

	inline point reflection(const point &a, const point &b) { // the reflection point of a
		return 2. * b - a;
	}

	inline double dot(const point &a, const point &b) {
		return a.x * b.x + a.y * b.y;
	}

	inline double det(const point &a, const point &b) {
		return a.x * b.y - a.y * b.x;
	}

	inline point rotCW(const point &a, const double &alpha) {
		double sina = sin(alpha), cosa = cos(alpha);
		return point(sina * a.y + cosa * a.x, cosa * a.y - sina * a.x);
	}

	inline point rotCCW(const point &a, const double &alpha) {
		double sina = sin(alpha), cosa = cos(alpha);
		return point(cosa * a.x - sina * a.y, sina * a.x + cosa * a.y);
	}

	inline double dist(const point &a, const point &b) {
		return hypot(a.x - b.x, a.y - b.y);
	}

	inline double dist2(const point &a, const point &b) {
		return sqr(a.x - b.x) + sqr(a.y - b.y);
	}

	struct line {
		int typ;
		point a, b;

		line() {}
		line(point a, point b): a(a), b(b) {
			typ = LINE;
		}
		line(point a, point b, int typ): a(a), b(b), typ(typ) {}

		inline void in(int T = LINE) {
			a.in();
			b.in();
			typ = T;
			return;
		}

		inline point dir() const {
			return b - a;
		}
	};

	inline bool on(const point &p, const line &l) {
		bool f = is0(det(p - l.a, l.b - l.a));
		if(!f) {
			return 0;
		}
		if(l.typ == LINE) {
			return 1;
		}
		if(l.typ == SEG) {
			return sign(dot(l.a - p, l.b - p)) <= 0;
		}
		return sign(dot(p - l.a, l.b - l.a)) >= 0;
	}

	inline vector<point> inter(const line &l1, const line &l2) {
		if(is0(det(l1.dir(), l2.dir()))) {
			return vector<point>();
		}
		double s1 = det(l2.a - l1.a, l2.b - l1.a), s2 = det(l2.b - l1.b, l2.a - l1.b);
		point t = l1.a + (l1.b - l1.a) * (s1 / (s1 + s2));
		return on(t, l1) && on(t, l2) ? vector<point>(1, t) : vector<point>();
	}

	inline line midpointnormal(const line &l) {
		point a = midpoint(l.a, l.b), b = l.dir().normal() + a;
		return line(a, b);
	}

	inline point projection(const point &p, const line &l) {
		point un = l.dir().unit();
		return l.a + dot(p - l.a, un) * un;
	}

	inline point reflection(const point &p, const line &l) {
		return reflection(p, projection(p, l));
	}

	struct circle {
		point o;
		double r;

		circle() {}
		circle(point o, double r): o(o), r(r) {}

		inline void in() {
			o.in();
			scanf("%lf", &r);
			return;
		}
	};

	inline int pos(const point &p, const circle &c) {
		return sign(dist2(p, c.o) - sqr(c.r));
	}

	inline bool on(const point &p, const circle &c) {
		return pos(p, c) == 0;
	}

	inline vector<point> inter(const line &l, const circle &c) {
		vector<point> ret;
		point p = projection(c.o, l);
		int t = pos(p, c);
		if(t > 0) {
			return ret;
		}
		if(t == 0) {
			return on(p, l) ? vector<point>(1, p) : ret;
		}
		point a = p + (l.a - l.b).unit() * sqrt(sqr(c.r) - dist2(c.o, p)), b = p * 2 - a;
		if(on(a, l)) {
			ret.push_back(a);
		}
		if(on(b, l)) {
			ret.push_back(b);
		}
		return ret;
	}

	inline vector<point> inter(const circle &c, const line &l) {
		return inter(l, c);
	}

	inline vector<point> inter(const circle &c1, const circle &c2) {
		vector<point> ret;
		if(c1.o == c2.o) {
			return ret;
		}
		point p = c1.o + (c2.o - c1.o).unit() * ((sqr(c1.r) - sqr(c2.r) + dist2(c1.o, c2.o)) / (2. * dist(c1.o, c2.o)));
		vector<point> foo = inter(line(p, p + (c2.o - c1.o).normal()), c1);
		for (const auto &x: foo) {
			if(on(x, c1) && on(x, c2)) {
				ret.push_back(x);
			}
		}
		return ret;
	}

	inline vector<line> tangent(const point &p, const circle &c) {
		int sgn = pos(p, c);
		if(sgn == IN) {
			return vector<line>();
		}
		if(sgn == ON) {
			return vector<line>(1, line(p, (c.o - p).normal() + p));
		}
		circle C = circle(midpoint(p, c.o), dist(p, c.o) / 2.);
		vector<point> t = inter(c, C);
		vector<line> ret;
		for (auto &o: t) {
			ret.push_back(line(p, o));
		}
		return ret;
	}

	inline vector<line> tangent(const circle &c, const point &p) {
		return tangent(p, c);
	}

	inline vector<line> ext_common_tangent(const circle &c1, const circle &c2) {
		vector<line> ret;
		int sgn = sign(c1.r - c2.r);
		if(!sgn) {
			if(c1.o == c2.o) {
				return ret;
			}
			line l = line(c1.o, c2.o);
			point dir = l.dir().normal().unit() * c1.r;
			ret.push_back(line(l.a + dir, l.b + dir));
			ret.push_back(line(l.a - dir, l.b - dir));
			return ret;
		}
		if(sgn > 0) {
			return ext_common_tangent(c2, c1);
		}
		circle c = circle(c2.o, c2.r - c1.r);
		vector<line> tmp = tangent(c1.o, c);
		for (auto &l: tmp) {
			point dir = l.dir().normal().unit() * c1.r;
			line nl = line(l.a + dir, l.b + dir);
			if(inter(nl, c2).size() == 1) {
				ret.push_back(nl);
			}
			else {
				ret.push_back(line(l.a - dir, l.b - dir));
			}
		}
		return ret;
	}

	inline vector<line> int_common_tangent(const circle &c1, const circle &c2) {
		vector<line> ret;
		circle c = circle(c2.o, c2.r + c1.r);
		vector<line> tmp = tangent(c1.o, c);
		for (auto &l: tmp) {
			point dir = l.dir().normal().unit() * c1.r;
			line nl = line(l.a + dir, l.b + dir);
			if(inter(nl, c2).size() == 1) {
				ret.push_back(nl);
			}
			else {
				ret.push_back(line(l.a - dir, l.b - dir));
			}
		}
		return ret;
	}

	inline vector<line> common_tangent(const circle &c1, const circle &c2) {
		auto ret = ext_common_tangent(c1, c2);
		auto foo = int_common_tangent(c1, c2);
		ret.insert(ret.end(), foo.begin(), foo.end());
		return ret;
	}

	inline vector<circle> circumcircle(const point &a, const point &b, const point &c) {
		if(on(a, line(b, c))) {
			return vector<circle>();
		}
		line x = midpointnormal(line(a, b)), y = midpointnormal(line(b, c));
		auto t = inter(x, y);
		return vector<circle>(1, circle(t[0], dist(t[0], a)));
	}

	inline vector<circle> circumcircle(const vector<point> &polygon) {
		if(polygon.size() < 3) {
			return vector<circle>();
		}
		auto ret = circumcircle(polygon[0], polygon[1], polygon[2]);
		if(!ret.size()) {
			return ret;
		}
		circle &c = ret[0];
		for (int i = 3; i < polygon.size(); ++i) {
			if(!on(polygon[i], c)) {
				return vector<circle>();
			}
		}
		return vector<circle>(1, c);
	}

	inline bool convex(const vector<point> &polygon, bool same_line = 0) {
		int cnt[3] = {0, 0, 0};
		int n = polygon.size();
		for (int i = 0; i < n; ++i) {
			++cnt[sign(det(polygon[i] - polygon[(i + n - 1) % n], polygon[(i + 1) % n] - polygon[i])) + 1];
		}
		if(cnt[0] && cnt[2]) {
			return 0;
		}
		return same_line || !cnt[1];
	}
}

using namespace geometry;

bool f[11][11][11][11];
point a[11], b[11];
int ord[11];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		a[i].in();
	}
	for (int i = 1; i <= m; ++i) {
		b[i].in();
	}
	if(n == m) {
		for (int a1 = 1; a1 <= n; ++a1) {
			for (int a2 = 1; a2 <= n; ++a2) {
				for (int b1 = 1; b1 <= m; ++b1) {
					for (int b2 = 1; b2 <= m; ++b2) {
						line l1 = line(a[a1], b[b1], SEG);
						line l2 = line(a[a2], b[b2], SEG);
						auto t = inter(l1, l2);
						if(!t.size()) {
							f[a1][b1][a2][b2] = 1;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			ord[i] = i;
		}
		do {
			bool ok = 1;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j < i; ++j) {
					if(!f[i][ord[i]][j][ord[j]]) {
						ok = 0;
						break;
					}
				}
				if(!ok) {
					break;
				}
			}
			if(ok) {
				puts("Yes");
				return 0;
			}
		} while(next_permutation(ord + 1, ord + n + 1));
	}
	puts("No");
	return 0;
}