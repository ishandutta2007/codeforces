#include <cmath>
#include <cstdio>

using namespace std;

typedef int num;

struct vec2i {
	num x, y;

	vec2i() {}

	vec2i(num x, num y) : x(x), y(y) {}

	num len() const {
		return sqrt(x * x + y * y);
	}

	vec2i rot90() const {
		return vec2i(-y, x);
	}

	vec2i rot90(const vec2i& v) const {
		return (*this - v).rot90() + v;
	}

	vec2i operator-() const {
		return vec2i(-x, -y);
	}

	vec2i operator+(const vec2i& v) const {
		return vec2i(x + v.x, y + v.y);
	}

	vec2i operator-(const vec2i& v) const {
		return vec2i(x - v.x, y - v.y);
	}

	vec2i operator+=(const vec2i& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2i operator-=(const vec2i& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2i operator*(num a) const {
		return vec2i(x * a, y * a);
	}

	vec2i operator/(num a) const {
		return vec2i(x / a, y / a);
	}

	num operator^(const vec2i& v) const {
		return x * v.x + y * v.y;
	}

	num operator*(const vec2i& v) const {
		return x * v.y - y * v.x;
	}

	friend vec2i operator*(num a, const vec2i& v) {
		return vec2i(a * v.x, a * v.y);
	}

	num angle(vec2i u, vec2i v) const {
		u -= *this;
		v -= *this;
		return acos((u / u.len()) ^ (v / v.len()));
	}

	friend vec2i intersect(const vec2i& p1, const vec2i& p2, const vec2i& q1, const vec2i& q2) {
		num a1 = (q1 - p1) * (q2 - q1), a2 = (p2 - q1) * (q2 - p2);
		return (p2 - p1) * a1 / (a1 + a2) + p1;
	}
};

const int N = 1010;

vec2i p[N];

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &p[i].x, &p[i].y);
	for (int i = 2; i < n; ++i)
		if ((p[i + 1] - p[i]) * (p[i] - p[i - 1]) < 0)
			++ans;
	printf("%d\n", ans);
	return 0;
}