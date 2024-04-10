#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;

mt19937 rnd((uint) chrono::steady_clock::now().time_since_epoch().count());

struct point {
	ld x, y;

	point(ld x, ld y) : x(x), y(y) {}

	bool operator<(const point &other) const {
		return x < other.x;
	}
};

struct line {
	ld k, b;

	line(ld k, ld b): k(k), b(b) {}

	ld y(const ld x) const {
		return k * x + b;
	}

	point intersect(const line &other) const {
		ld x = (other.b - b) / (k - other.k);
		return point(x, y(x));
	}
};

struct ConvexHull {
	vector<line> hull;
	vector<point> inter;

	ConvexHull() {
		inter.emplace_back(-1e18, -1e18);
	}

	void add(const line &l) {
		while (szof(hull) > 1 && l.intersect(hull.back()) < inter.back()) {
			hull.pop_back();
			inter.pop_back();
		}
		if (!hull.empty())
			inter.push_back(l.intersect(hull.back()));
		hull.push_back(l);
	}

	ld get(ld x) {
		int i = --upper_bound(all(inter), point(x, 1e18)) - inter.begin();
		return hull[i].y(x);
	}
} cht;

void run() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a) {
		cin >> x;
	}
	for (int &x : b) {
		cin >> x;
	}
	vector<ll> dp(n, numeric_limits<ll>::max());
	dp[0] = 0;
	cht.add({(ld) b[0], (ld) dp[0]});
	for (int i = 1; i < n; i++) {
		dp[i] = (ll) cht.get(a[i]);
		cht.add({(ld) b[i], (ld) dp[i]});
	}
	cout << dp.back() << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	return 0;
}