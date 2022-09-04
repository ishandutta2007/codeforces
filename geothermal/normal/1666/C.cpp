#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

struct segment {
	ll x1, y1, x2, y2;
	bool operator<(const segment& rhs) const {
		return false;
	}
};

ll len(vector<segment> v) {
	ll r = 0;
	for (auto s: v) {
		r += abs(s.x1 - s.x2) + abs(s.y1 - s.y2);
	}
	return r;
}

vector<segment> from_points(array<ll, 2> a, array<ll, 2> b) {
	if (a[0] == b[0] || a[1] == b[1]) {
		return {{a[0], a[1], b[0], b[1]}};
	}
	else {
		array<ll, 2> c = {a[0], b[1]};
		return {{a[0], a[1], c[0], c[1]},
			    {c[0], c[1], b[0], b[1]}};
	}
}

pair<ll, vector<segment>> f(array<ll, 2> a, array<ll, 2> b, array<ll, 2> c) {
	vector<segment> ret;
	for (auto v: from_points(a, b)) {
		ret.push_back(v);
	}
	for (auto v: from_points(a, c)) {
		ret.push_back(v);
	}
	return {len(ret), ret};
}

vector<pair<ll, vector<segment>>> g(array<ll, 2> a, array<ll, 2> b, array<ll, 2> c) {
	if (a[0] <= b[0] && b[0] <= c[0]) {
		vector<segment> t1 = {
			{a[0], a[1], a[0], c[1]},
			{a[0], c[1], c[0], c[1]},
			{b[0], b[1], b[0], c[1]}
		};
		vector<segment> t2 = {
			{a[0], a[1], c[0], a[1]},
			{c[0], a[1], c[0], c[1]},
			{b[0], b[1], b[0], a[1]}
		};
		return {{len(t1), t1}, {len(t2), t2}};
	}
	else if (a[1] <= b[1] && b[1] <= c[1]) {
		vector<segment> t1 = {
			{a[0], a[1], c[0], a[1]},
			{c[0], a[1], c[0], c[1]},
			{b[0], b[1], c[0], b[1]}
		};
		vector<segment> t2 = {
			{a[0], a[1], a[0], c[1]},
			{a[0], c[1], c[0], c[1]},
			{b[0], b[1], a[0], b[1]}
		};
		return {{len(t1), t1}, {len(t2), t2}};
	}
	else return {};
}

pair<ll, vector<segment>> h(vector<pair<ll, vector<segment>>> v) {
	pair<ll, vector<segment>> ret = {1e18, {}};
	for (auto p: v) {
		ret = min(ret, p);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	array<ll, 2> a, b, c;
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];

	pair<ll, vector<segment>> ans = {1e18, {}};
	ans = min(ans, f(a, b, c));
	ans = min(ans, f(b, a, c));
	ans = min(ans, f(c, b, a));

	ans = min(ans, h(g(a, b, c)));
	ans = min(ans, h(g(a, c, b)));
	ans = min(ans, h(g(b, c, a)));
	ans = min(ans, h(g(b, a, c)));
	ans = min(ans, h(g(c, a, b)));
	ans = min(ans, h(g(c, b, a)));

	vector<segment> r;
	for (auto s: ans.second) {
		if (s.x1 != s.x2 || s.y1 != s.y2) {
			r.push_back(s);
		}
	}
	cout << sz(r) << '\n';
	for (auto s: r) {
		cout << s.x1 << ' ' << s.y1 << ' ' << s.x2 << ' ' << s.y2 << '\n';
	}
}