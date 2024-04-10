#include <cstdio>
#include <cmath>

#include <algorithm>

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

const double EPS = 1e-6;

bool check(const vec2d& A, const vec2d& B, const vec2d& C);

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vec2d A, B, C;
		scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
		if ((B - A) * (C - B) < 0)
			swap(B, C);
		if (check(A, B, C))
			continue;
		if (check(B, C, A))
			continue;
		if (check(C, A, B))
			continue;
		puts("NO\n");
	}
	return 0;
}

bool check(const vec2d& A, const vec2d& B, const vec2d& C) {
	vec2d midAB, midBC, hAB, hBC, P, Q, kA, kB, kC, kD;
	midAB = (A + B) / 2;
	midBC = (B + C) / 2;
	hAB = B.rot90(midAB);
	hBC = C.rot90(midBC);
	P = B * 2 - midAB;
	Q = B * 2 - hAB;
	kC = intersect(midBC, hBC, P, Q);
	kA = intersect(midAB, hAB, B, kC);
	kB = A * 2 - kA;
	kD = C * 2 - kC;
	if (isnan(kA.x) || isnan(kB.x) || isnan(kC.x) || isnan(kD.x))
		return false;
	if ((((kB - kA) * (kD - kB) < EPS) ||
	    ((kD - kB) * (kC - kD) < EPS) ||
		((kC - kD) * (kA - kC) < EPS) ||
		((kA - kC) * (kB - kA) < EPS)) && 
	   (((kD - kB) * (kB - kA) < EPS) ||
	    ((kC - kD) * (kD - kB) < EPS) ||
		((kA - kC) * (kC - kD) < EPS) ||
		((kB - kA) * (kA - kC) < EPS)))
		return false;
	printf("YES\n%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", kA.x, kA.y, kB.x, kB.y, kD.x, kD.y, kC.x, kC.y);
	return true;
}