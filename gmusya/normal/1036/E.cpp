#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

using ll = long long;
using ld = long double;

const ld EPS = 1e-6;

namespace {
	bool AreSignsOpposite(ll x, ll y) {
		if (x == 0 || y == 0) {
			return true;
		}
		return (x > 0 && y < 0) || (x < 0 && y > 0);
	}
}

struct Point {
	ll x;
	ll y;

	bool operator==(const Point& point) const {
		return (x == point.x && y == point.y);
	}

	bool operator<(const Point& point) const {
		if (x != point.x) {
			return x < point.x;
		}
		return y < point.y;
	}

	Point operator-(const Point& point) const {
		return {x - point.x, y - point.y};
	}

	Point operator+(const Point& point) const {
		return {x + point.x, y + point.y};
	}

	Point operator*(const ll& k) const {
		return {k * x, k * y};
	}

	ll operator%(const Point& point) const {
		return x * point.y - y * point.x;
	}

	Point Normal(ll& gcd) const {
		gcd = __gcd(abs(x), abs(y));
		return {x / gcd, y / gcd};
	}

	friend istream& operator>>(istream& in, Point& point) {
		return in >> point.x >> point.y;
	}
};

struct Segment {
	Point a;
	Point b;

	friend istream& operator>>(istream& in, Segment& segment) {
		return in >> segment.a >> segment.b;
	}

	ll GetIntegerPoints() const {
		return __gcd(abs(a.x - b.x), abs(a.y - b.y)) + 1;
	}

	static bool IsCollinear(const Segment& l, const Segment& r) {
		return (l.a - l.b) % (r.a - r.b) == 0;
	}

	ll Evaluate(const Point& point) const {
		return (b - a) % (point - a);
	}

	static bool DoIntersect(const Segment& l, const Segment& r) {
		if (!AreSignsOpposite((l.b - l.a) % (r.a - l.a), (l.b - l.a) % (r.b - l.a))) {
			return false;
		}
		if (!AreSignsOpposite((r.b - r.a) % (l.a - r.a), (r.b - r.a) % (l.b - r.a))) {
			return false;
		}
		return true;
	}

	static pair<bool, Point> Intersection(const Segment& l_seg, const Segment& r_seg) {
		if (l_seg.a == r_seg.a || l_seg.a == r_seg.b) {
			return {true, l_seg.a};
		}
		if (l_seg.b == r_seg.a || l_seg.b == r_seg.b) {
			return {true, l_seg.b};
		}
		if (IsCollinear(l_seg, r_seg) || !DoIntersect(l_seg, r_seg)) {
			return {false, {}};
		}
		ll gcd;
		Point normal_vector = (l_seg.b - l_seg.a).Normal(gcd);
		ll val = r_seg.Evaluate(l_seg.a);
		ll l = 0, r = gcd;
		while (l != r) {
			ll m = (l + r) / 2;
			ll val_for_m = r_seg.Evaluate(l_seg.a + normal_vector * m);
			if (!val_for_m) {
				return {true, l_seg.a + normal_vector * m};
			}
			if (AreSignsOpposite(val_for_m, val)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		if (r_seg.Evaluate(l_seg.a + normal_vector * l) == 0) {
			return {true, l_seg.a + normal_vector * l};
		} else {
			return {false, {}};
		}
	}
};

// n * (n - 1) / 2 = x
// n * (n - 1) = 2 * x


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Segment> segments(n);
	for (int i = 0; i < n; ++i) {
		cin >> segments[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += segments[i].GetIntegerPoints();
	}
	map<Point, int> cnt;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			auto intersection_point = Segment::Intersection(segments[i], segments[j]);
			if (intersection_point.first) {
				++cnt[intersection_point.second];
			}
		}
	}
	for (auto& now : cnt) {
		ans -= floor(sqrt(2 * now.second) + EPS);
	}
	cout << ans;
	return 0;
}