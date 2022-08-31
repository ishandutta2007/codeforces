#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-16;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 10;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

typedef pair<ld, ld> Point;
ld dot(Point a, Point b) { return a.first * b.first + a.second * b.second; }
ld cross(Point a, Point b) { return a.first * b.second - a.second * b.first; }
ld norm(Point a) { return sqrtl(a.first * a.first + a.second * a.second); }

Point operator+(const Point& a, const Point& b) {
	return { a.first + b.first,a.second + b.second };
}
Point operator-(const Point& a, const Point& b) {
	return { a.first - b.first,a.second - b.second };
}
Point operator-=(Point& a, const Point b) {
	a = a - b;
	return a;
}
ld abs(Point a) {
	return norm(a);
}
Point operator*(const Point& a, const ld& b) {
	return { a.first * b,a.second * b };
}
Point operator/(const Point& a, const ld& b) {
	return { a.first / b,a.second / b };
}

struct Line {
	Point a, b;
};
struct Circle {
	Point p; ld r;
};
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps)return 1;//counter clockwise
	if (cross(b, c) < -eps)return -1;//clock wise
	if (dot(b, c) < 0)return 2;//c--a--b on line
	if (norm(b) < norm(c))return -2;//a--b--c on line
	return 0; //a--c--b on line
}

void solve() {
	int n; cin >> n;
	vector<Point> p(n);
	rep(i, n) {
		int x, y; cin >> x >> y;
		p[i] = { 1 / (ld)x,1 / (ld)y };
	}
	vector<Point> cop = p;
	sort(all(p));
	vector<Point> vp;
	rep(i, p.size()) {
		if (i > 0 && p[i - 1].first == p[i].first)continue;
		if (vp.size() && vp.back().second <= p[i].second)continue;
		int len = vp.size();
		while (len >= 2 && ccw(vp[len - 2], vp[len - 1], p[i]) == -1) {
			vp.pop_back(); len--;
		}
		vp.push_back(p[i]);
	}
	vector<int> ans;
	rep(i, cop.size()) {
		int id = lower_bound(all(vp), cop[i]) - vp.begin();
		if (id < vp.size() && vp[id] == cop[i]) {
			ans.push_back(i);
		}
	}
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i]+1;
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}