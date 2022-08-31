#pragma GCC target("avx2")
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
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
namespace std {
	bool operator<(const Point& lhs, const Point& rhs) {
		return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
	}
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
bool isis_ll(Line l, Line m) {
	return !eq(cross(l.b - l.a, m.b - m.a), 0);
}
bool isis_sp(Line s, Point p) {
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a; Point tv = t.b - t.a;
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
typedef vector<Point> polygon;
polygon ConvexHull(polygon p) {
	int n = p.size();
	int k = 0;
	sort(p.begin(), p.end());
	polygon ch(2 * n);
	for (int i = 0; i < n; ch[k++] = p[i++]) {
		while (k >= 2 && ccw(ch[k - 2], ch[k - 1], p[i]) <= 0)--k;
	}
	for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
		while (k >= t && ccw(ch[k - 2], ch[k - 1], p[i]) <= 0)--k;
	}
	ch.resize(k - 1);
	return ch;
}

void solve(){
	int n; cin >> n;
	int p, q; cin >> p >> q;
	vector<Point> vp(n);
	rep(i, n) {
		int a, b; cin >> a >> b;
		vp[i] = { (ld)a,(ld)b };
	}
	ld ans = INF;
	rep(i, n) {
		ld x = real(vp[i]);
		ld y = imag(vp[i]);
		ans = min(ans, max(p / x, q / y));
	}
	if (n == 1) {
		cout << ans << "\n";
		return;
	}
	polygon pg = ConvexHull(vp);
	Line z = { {(ld)0,(ld)0},{(ld)p,(ld)q} };
	ld dist = (ld)p * p + (ld)q * q;
	dist = sqrtl(dist);
	rep(i, pg.size()) {
		Line l = { pg[i],pg[(i + 1) % pg.size()] };
		if (isis_ll(l, z)) {
			Point c = is_ll(l, z);
			if (isis_sp(l, c)) {
				ld d = sqrtl(norm(c));
				//cout << real(c) << " " << imag(c) << " "<<d<<"\n";
				ans = min(ans, dist / d);
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}