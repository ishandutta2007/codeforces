#include <bits/stdc++.h>
using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x_=0, T y_=0) : x(x_), y(y_) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}
template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}

using P = Point<double>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; double L; cin >> N >> L;
	vector<P> pts(2*N+1);
	for (int i = 0; i < N; i++) {
		cin >> pts[i].x >> pts[i].y;
	}

	for (int i = N; i <= 2*N; i++) {
		pts[i] = pts[i-N];
	}

	for (int i = 0; i < N; i++) {
		L -= (pts[i+1] - pts[i]).dist();
	}

	assert(L > 0);

	int lo = 0;
	int hi = 1;
	L += (pts[hi] - pts[lo]).dist();
	P cur_st;

	double ans = 0;
	while (lo <= N) {
		P center = (pts[lo] + pts[hi]) / 2;
		P dir = pts[lo] - pts[hi];
		double ang = dir.angle();
		double major = L / 2;
		double minor = sqrt(major * major - dir.dist2() / 4);
		auto transform_pt = [&](P p) -> P {
			p = p - center;
			p = p.rotate(-ang);
			p.x /= major;
			p.y /= minor;
			return p;
		};
		auto untransform_pt = [&](P p) -> P {
			p.y *= minor;
			p.x *= major;
			p = p.rotate(ang);
			p = p + center;
			return p;
		};
		auto untransform_area = [&](double d) -> double {
			return d * minor * major;
		};

		P plo = transform_pt(pts[lo]);
		P plo1 = transform_pt(pts[lo+1]);
		P phi = transform_pt(pts[hi]);
		P phi1 = transform_pt(pts[hi+1]);

		P cndlo = circleLine(P(0,0), 1, plo, plo1)[1];
		P cndhi = circleLine(P(0,0), 1, phi, phi1)[0];
		double alo = (cndlo*-1).perp().angle();
		double ahi = (cndhi*-1).perp().angle();

		bool do_lo = alo < ahi;
		P nxt_st = untransform_pt(do_lo ? cndlo : cndhi);
		if (lo > 0) {
			P st = transform_pt(cur_st);
			double ast = (st*-1).perp().angle();
			double cur_val = untransform_area(((do_lo ? alo : ahi) - ast) / 2);

			// y dx from a to b
			auto seg_val = [&](P a, P b) -> double {
				return (b.x - a.x) * (b.y + a.y) / 2;
			};

			cur_val += seg_val(nxt_st, center) + seg_val(center, cur_st);
			ans += cur_val;
		}
		cur_st = nxt_st;

		if (do_lo) {
			L -= (pts[lo+1] - pts[lo]).dist();
			lo++;
		} else {
			L += (pts[hi+1] - pts[hi]).dist();
			hi++;
		}
	}

	cout << fixed << setprecision(15) << ans << '\n';

	return 0;
}