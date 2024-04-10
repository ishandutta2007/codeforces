#include <cmath>
#include <cstdio>

using namespace std;

typedef double num;

struct vec2d {
	num x, y;

	vec2d() {}

	vec2d(num x, num y) : x(x), y(y) {}

	num len() const {
		return sqrt(x * x + y * y);
	}

	vec2d rot90() const {
		return vec2d(-y, x);
	}

	vec2d rot90(const vec2d& v) const {
		return (*this - v).rot90() + v;
	}

	vec2d operator-() const {
		return vec2d(-x, -y);
	}

	vec2d operator+(const vec2d& v) const {
		return vec2d(x + v.x, y + v.y);
	}

	vec2d operator-(const vec2d& v) const {
		return vec2d(x - v.x, y - v.y);
	}

	vec2d operator+=(const vec2d& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2d operator-=(const vec2d& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2d operator*(num a) const {
		return vec2d(x * a, y * a);
	}

	vec2d operator/(num a) const {
		return vec2d(x / a, y / a);
	}

	num operator^(const vec2d& v) const {
		return x * v.x + y * v.y;
	}

	num operator*(const vec2d& v) const {
		return x * v.y - y * v.x;
	}

	friend vec2d operator*(num a, const vec2d& v) {
		return vec2d(a * v.x, a * v.y);
	}

	num angle(vec2d u, vec2d v) const {
		u -= *this;
		v -= *this;
		return acos((u / u.len()) ^ (v / v.len()));
	}

	friend vec2d intersect(const vec2d& p1, const vec2d& p2, const vec2d& q1, const vec2d& q2) {
		num a1 = (q1 - p1) * (q2 - q1), a2 = (p2 - q1) * (q2 - p2);
		return (p2 - p1) * a1 / (a1 + a2) + p1;
	}
};

const num EPS = 1e-5, PI2 = 6.2831853072;

int main() {
	vec2d a, b, c, mid1, mid2, anc1, anc2, center;
	scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
	mid1 = (a + b) / 2;
	anc1 = b.rot90(mid1);
	mid2 = (b + c) / 2;
	anc2 = c.rot90(mid2);
	center = intersect(mid1, anc1, mid2, anc2);
	for (int n = 3; n <= 100; ++n) {
		num alpha = PI2 / n, t;
		t = center.angle(a, b) / alpha;
		if (fabs(t - round(t)) > EPS)
			continue;
		t = center.angle(b, c) / alpha;
		if (fabs(t - round(t)) > EPS)
			continue;
		num r = (center - a).len();
		printf("%.9lf\n", r * r * n * sin(alpha) / 2);
		break;
	}
	return 0;
}