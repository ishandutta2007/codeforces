#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

constexpr double pi_val() {
	return atan(1) * 4;
}
template<class Type>
struct Point {
	Type x, y;
	Point(const Type &x, const Type &y): x(x), y(y) {}
	Point(const Type &x): x(x), y(0) {}
	Point(): x(0), y(0) {}
	template<class Type2>
	Point(const Point<Type2> &o): x(o.x), y(o.y) { }
	template<class Type2>
	Point(const Point<Type2> &A, const Point<Type2> &B) {
		*this = B - A;
	}
	Type distanceSq(const Point &p) const {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
	long double distance(const Point &p) const {
		return sqrtl((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	long double abs() const {
		return sqrtl(x * x + y * y);
	}
	Type absSq() const {
		return x * x + y * y;
	}
	Point operator+(const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point &operator+=(const Point &a) {
		x += a.x;
		y += a.y;
		return *this;
	}
	Point operator-(const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator-() const {
		return Point(-x, -y);
	}
	Point &operator-=(const Point &a) {
		x -= a.x;
		y -= a.y;
		return *this;
	}
	Point operator*(const Point &a) const {
		return Point(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	Point &operator*=(const Point &a) {
		Type xx = x;
		Type yy = y;
		x = xx * a.x - yy * a.y;
		y = xx * a.y + yy * a.x;
		return *this;
	}
	Point operator*(const Type &a) const {
		return Point(x * a, y * a);
	}
	Point operator*=(const Type &a) {
		x = x * a;
		y = y * a;
		return *this;
	}
	Point conjugate() const {
		return Point(x, -y);
	}
	Point<long double> normalized() const {
		return *this * ( 1 / abs());
	}
	bool operator==(const Point &a)const {
		return x == a.x and y == a.y;
	}
	Type dot(const Point &a)const {
		return x * a.x + y * a.y;
	}
	Type cross(const Point &a)const {
		return x * a.y - y * a.x;
	}
	long double angle() const {
		long double angl = atan2(y, x);

		if (angl < 0) {
			angl += 2 * pi_val();
		}

		return angl;
	}
	long double angle(const Point &a) const {
		long double angl = a.angle() - angle();

		if (angl < 0) {
			angl += 2 * pi_val();
		}

		return angl;
	}
	Point rotate(long double ang) {
		return *this * Point(cos(ang), sin(ang));
	}
	bool operator<(const Point &a) const {
		if (x == a.x) {
			return y < a.y;
		}

		return x < a.x;
	}
};
template<class Type>
ostream &operator<<(ostream &out, const Point<Type> &p) {
	out << p.x << " " << p.y;
	return out;
}
template<class Type>
istream &operator>>(istream &in, Point<Type> &p) {
	in >> p.x >> p.y;
	return in;
}
typedef Point<long long> point;
typedef Point<long double> pointd;
pair<long double, long double> solve_q(long double a, long double b, long double c) {
	// ax^2 + by + c
	if (abs(a) <= 1e-6) {
		long double x = -c / b;
		return {x, x};
	}

	long double d = (b * b - 4 * a * c);

	if (abs(d) <= 1e-6) {
		long double x = -b / 2 / a;
		return {x, x};
	}
	else if (d < 0) {
		return {NAN, NAN};
	}
	else {
		d = sqrt(d);
		long double x1 = (-b + d) / 2 / a;
		long double x2 = (-b - d) / 2 / a;

		if (a < 0) {
			swap(x2, x1);
		}

		return {x1, x2};
	}
}
/*input
0 0 10
60 0 10
30 30 10
*/
pointd a, b, c;

bool first = true;

pointd betw(long double ra, pointd b, long double rb, long double y) {
	auto t = solve_q(1 / rb / rb - 1 / ra / ra, -2 * b.x / rb / rb, (y * y + b.x * b.x) / rb / rb - y * y / ra / ra);
	// debug(t, y);

	if (first)
		return {t.first, y};
	else {
		return {t.second, y};
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long double ra, rb, rc;
	cin >> a >> ra >> b >> rb >> c >> rc;
	b -= a;
	c -= a;
	pointd ob = b;
	c = c.rotate(-ob.angle());
	b = b.rotate(-ob.angle());

	debug(a, b, c);


	long double mi = 0, ma = 0;

	if (c.y > 0) {
		long double fr = 0, t = c.y;

		for (int i = 0; i < 100; ++i) {
			long double mid = (fr + t) / 2;
			pointd t1 = betw(ra, b, rb, mid);

			if (isnan(t1.x)) {
				t = mid;
			}
			else {
				fr = mid;
			}
		}

		ma = (fr + t) / 2;
	}
	else {
		long double fr = c.y, t = 0;

		for (int i = 0; i < 100; ++i) {
			long double mid = (fr + t) / 2;
			pointd t1 = betw(ra, b, rb, mid);

			if (isnan(t1.x)) {
				fr = mid;
			}
			else {
				t = mid;
			}
		}

		mi = (fr + t) / 2;
	}

	debug(mi, ma);

	// if (c.y > 0) {
	// 	mi = 0, ma = c.y;
	// }
	// else {
	// 	mi = c.y, ma = 0;
	// }

	for (int i = 0; i < 100; ++i) {
		long double mid1 = (2 * mi + ma) / 3;
		long double mid2 = (mi + 2 * ma) / 3;
		pointd t1 = betw(ra, b, rb, mid1);
		pointd t2 = betw(ra, b, rb, mid2);

		if (pow(t1.distance(b) / rb * rc - t1.distance(c), 2) < pow(t2.distance(b) / rb * rc - t2.distance(c), 2)) {
			ma = mid2;
		}
		else {
			mi = mid1;
		}
	}

	debug(mi, ma);
	pointd t = betw(ra, b, rb, (mi + ma) / 2);
	debug(pow(t.distance(b) / rb - t.distance(c) / rc, 2));

	if (pow(t.distance(b) / rb - t.distance(c) / rc, 2) < 0.000001) {
		t = t.rotate(ob.angle());
		t += a;
		cout << fixed << setprecision(6) << t << endl;
	}
	else {
		first = false;
	long double mi = 0, ma = 0;

	if (c.y > 0) {
		long double fr = 0, t = c.y;

		for (int i = 0; i < 100; ++i) {
			long double mid = (fr + t) / 2;
			pointd t1 = betw(ra, b, rb, mid);

			if (isnan(t1.x)) {
				t = mid;
			}
			else {
				fr = mid;
			}
		}

		ma = (fr + t) / 2;
	}
	else {
		long double fr = c.y, t = 0;

		for (int i = 0; i < 100; ++i) {
			long double mid = (fr + t) / 2;
			pointd t1 = betw(ra, b, rb, mid);

			if (isnan(t1.x)) {
				fr = mid;
			}
			else {
				t = mid;
			}
		}

		mi = (fr + t) / 2;
	}


		debug(mi, ma);

		// if (c.y > 0) {
		// 	mi = 0, ma = c.y;
		// }
		// else {
		// 	mi = c.y, ma = 0;
		// }

		for (int i = 0; i < 100; ++i) {
			long double mid1 = (2 * mi + ma) / 3;
			long double mid2 = (mi + 2 * ma) / 3;
			pointd t1 = betw(ra, b, rb, mid1);
			pointd t2 = betw(ra, b, rb, mid2);

			if (pow(t1.distance(b) / rb * rc - t1.distance(c), 2) < pow(t2.distance(b) / rb * rc - t2.distance(c), 2)) {
				ma = mid2;
			}
			else {
				mi = mid1;
			}
		}

		debug(mi, ma);
		pointd t = betw(ra, b, rb, (mi + ma) / 2);
		debug(pow(t.distance(b) / rb - t.distance(c) / rc, 2));

		if (pow(t.distance(b) / rb - t.distance(c) / rc, 2) < 0.000001) {
			t = t.rotate(ob.angle());
			t += a;
			cout << fixed << setprecision(6) << t << endl;
		}
	}

}