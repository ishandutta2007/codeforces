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
constexpr ll mod = 998244353;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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
const int max_n = 1 << 1;
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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

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
Point operator-=(Point& a, const Point& b) {
	a = a - b; return a;
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
bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}
//2
bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}
//
bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}
//
bool isis_lp(Line l, Point p) {
	return (abs(cross(l.b - p, l.a - p)) < eps);
}
//
bool isis_sp(Line s, Point p) {
	return abs(cross(s.a - p, s.b - p))< eps;
	//return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
//2
bool isis_ss(Line s, Line t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}
//
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}
//
//
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
//
vector<Point> is_ss(Line s1, Line s2) {
	if (!isis_ss(s1, s2))return {};
	vector<Point> res;
	if (abs(cross(s1.b - s1.a, s2.b - s2.a)) < eps) {
		if (isis_sp(s1, s2.a)) res.push_back(s2.a);
		if (isis_sp(s1, s2.b)) res.push_back(s2.b);
		if (isis_sp(s2, s1.a)) res.push_back(s1.a);
		if (isis_sp(s2, s1.b)) res.push_back(s1.b);
	}
	else {
		res.push_back(is_ll(s1, s2));
	}
	return res;
}

//0:on polygon,1:in polygon,2:out of polygon
int is_in_polygon(vector<Point>& poly, Point p) {
	ld sum = 0;
	int n = poly.size();
	rep(i, n) {
		int ni = i + 1 == n ? 0 : i + 1;
		Point pl = poly[i];
		Point pr = poly[ni];
		Line e = { pl,pr };
		if (isis_sp(e, p))return 0;
		complex<ld> cl = { (pl - p).first,(pl - p).second };
		complex<ld> cr = { (pr - p).first,(pr - p).second };
		sum += arg(cl / cr);
	}
	if (abs(sum) < pi / 2)return 2;
	return 1;
}
using polygon = vector<Point>;
ld calc_edge(polygon& poly, Line l) {
	Point s = l.a, t = l.b;
	//if (is_in_polygon(poly, s) == 2 || is_in_polygon(poly, t) == 2)return false;
	vector<ld> ts;
	int n = poly.size();
	rep(i, n) {
		//cout << isis_sp(l, poly[i]) << "\n";
		int ni = i + 1 == n ? 0 : i + 1;
		int nni = ni + 1 == n ? 0 : ni + 1;
		int ii = i == 0 ? n - 1 : i - 1;
		Point pl = poly[i];
		Point pr = poly[ni];
		Line e = { pl,pr };
		if (isis_sp(l,pl) && isis_sp(l,pr)) {
			if (ccw(poly[ni], poly[i], poly[ii]) == -1) {
				Point p = poly[i];
				ts.push_back(abs(p - s) / abs(t - s));
			}
			if (ccw(poly[i], poly[ni], poly[nni]) == 1) {
				Point p = poly[ni];
				ts.push_back(abs(p - s) / abs(t - s));
			}
		}
		else if (!isis_sp(l, pl) && !isis_sp(l, pr)) {
			if (isis_ss(l, e)) {
				Point p = is_ll(l, e);
				ts.push_back(abs(p - s) / abs(t - s));
			}
		}
		if (isis_sp(l, pl) && !isis_sp(l, poly[ii]) && !isis_sp(l, poly[ni])) {
			if (ccw(s, t, poly[ii]) != ccw(s, t, poly[ni])) {
				Point p = poly[i];
				//cout << p.first<<" "<<p.second<<" "<<abs(p - s) / abs(t - s) << "\n";
				ts.push_back(abs(p - s) / abs(t - s));
			}
		}
	}
	sort(all(ts));
	//cout << "? " << ts.size() << "\n";
	ld res = 0;
	for (int i = 0; i < ts.size(); i += 2) {
		//cout << "? " << ts[i] << " " << ts[i + 1] << "\n";
		res += abs(t - s) * (ts[i + 1] - ts[i]);
	}
	return res;
}
ld scanld() {
	string s; cin >> s;
	rep(i, s.size())if (s[i] == '.') {
		ld res = stoi(s.substr(0, i));
		ld z = stoi(s.substr(i + 1, s.size() - (i + 1)));
		for (int j = i + 1; j < s.size(); j++)z /= 10.0;
		if (s[0] == '-')res -= z;
		else res += z;
		return res;
	}
	return stoi(s);
}
void solve() {
	int n, m; cin >> n >> m;
	vector<Point> poly(n);
	rep(i, n) {
		ld x, y;
		x = scanld();
		y = scanld();
		poly[i] = { x,y };
	}
	vector<bool> ban(n);
	rep(i, n) {
		int ii = i == 0 ? n - 1 : i - 1;
		int ni = i + 1 == n ? 0 : i + 1;
		if (isis_sp({ poly[ii],poly[ni] }, poly[i]))ban[i] = true;
	}
	vector<Point> np;
	rep(i, n)if (!ban[i])np.push_back(poly[i]);
	swap(poly, np);
	n = poly.size();

	ld sum = 0;
	rep(i, poly.size()) {
		int ni = i + 1 == n ? 0 : i + 1;
		ld dx = poly[ni].first - poly[i].first;
		ld dy = poly[ni].second + poly[i].second;
		sum -= dx * dy;
	}
	if (sum<0) {
		reverse(all(poly));
	}
	
	//cout << poly.size() << "\n";
	rep(i, m) {
		ld x1, y1, x2, y2;
		x1 = scanld();
		y1 = scanld();
		x2 = scanld();
		y2 = scanld();
		Line l = { {x1,y1},{x2,y2} };
		Point dif = l.b - l.a;
		ld len = abs(dif);
		ld coef = 150000 / len;
		l.a -= dif *coef;
		l.b = l.b + dif * coef;
		ld ans = calc_edge(poly, l);
		cout << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(8);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}