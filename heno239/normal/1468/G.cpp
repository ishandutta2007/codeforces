//#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

const int max_n = 1 << 2;
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


typedef complex<ld> Point;
ld dot(Point a, Point b) { return real(conj(a) * b); }
ld cross(Point a, Point b) { return imag(conj(a) * b); }
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
bool eq(ld x,ld y) {
	return abs(x - y) < eps;
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
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
//
bool isis_ss(Line s, Line t) {
	return(cross(s.b - s.a, t.a - s.a) * cross(s.b - s.a, t.b - s.a) < -eps && cross(t.b - t.a, s.a - t.a) * cross(t.b - t.a, s.b - t.a) < -eps);
}
//
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}
//
//
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

ld dist(ld x1, ld y1, ld x2, ld y2) {
	ld dx = abs(x2 - x1);
	ld dy = abs(y2 - y1);
	return sqrtl(dx * dx + dy * dy);
}
void solve() {
	int inh;
	int n;
	cin >> n >> inh; ld h = inh;
	vector<ld> x(n), y(n);
	vector<int> inx(n), iny(n);
	rep(i, n)cin >> inx[i] >> iny[i];
	rep(i, n) {
		x[i] = inx[i], y[i] = iny[i];
	}
	ld ans = 0;
	Line l = { Point{x[n - 1],y[n - 1] + h},Point{x[n - 2],y[n - 2]} };
	ans += dist(x[n - 2], y[n - 2], x[n - 1], y[n - 1]);
	for (int i = n - 3; i >= 0; i--) {
		//[i,i+1]
		Point p = { x[i + 1],y[i + 1] };
		Point q = { x[i],y[i] };
		Line z = { q,p };
		if (!isis_ll(l, z)) {
			if (isis_lp(l, p)) {
				ans += dist(x[i], y[i], x[i + 1], y[i + 1]);
			}
			continue;
		}
		int t = ccw(Point{ x[n - 1],y[n - 1] + h }, p,q);
		if (t == -1) {
			Point c = is_ll(l, z);
			ld px = real(c);
			if (px >= x[i] && x[i + 1] + eps >= px) {
				ans += abs(c - q);
				l = { q,{x[n - 1],y[n - 1] + h} };
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}