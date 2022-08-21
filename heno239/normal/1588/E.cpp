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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

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
const ld eps = 1e-4;
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
/*typedef complex<ld> Point;
ld dot(Point a, Point b) { return real(conj(a) * b); }
ld cross(Point a, Point b) { return imag(conj(a) * b); }
namespace std {
	bool operator<(const Point& lhs, const Point& rhs) {
		return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
	}
}*/
typedef pair<ld, ld> Point;
ld dot(Point a, Point b) { return a.first * b.first + a.second * b.second; }
ld cross(Point a, Point b) { return a.first * b.second - a.second * b.first; }
ld norm(Point a) { return a.first * a.first + a.second * a.second; }
ld arg(Point a) { return atan2(a.second, a.first); }
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
	return sqrt(norm(a));
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
int ccw(Point a, Point b, Point c) {
	b -= a; c -= a;
	if (cross(b, c) > eps)return 1;//counter clockwise
	if (cross(b, c) < -eps)return -1;//clock wise
	if (dot(b, c) < 0)return 2;//c--a--b on line
	if (norm(b) < norm(c))return -2;//a--b--c on line
	return 0; //a--c--b on line
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

//
bool isis_sp(Line s, Point p) {
	//isis_lpisis_lp
	return (abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps);
}
//
Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b)*t;
}
//
ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(p - r) : min(abs(p - s.a), abs(p - s.b));
}

void solve() {
	int n; ld r; cin >> n >> r;
	vector<Point> p(n);
	rep(i, n) {
		ld a, b; cin >> a >> b;
		p[i] = { a,b };
	}
	if (n == 1) {
		cout << 0 << "\n"; return;
	}
	polygon vp = p;
	vp = ConvexHull(vp);
	vector<pair<ld, int>> ts;
	rep(i, vp.size()) {
		int ni = i + 1 == vp.size() ? 0 : i + 1;
		//int prei = i - 1 < 0 ? vp.size() - 1 : i - 1;
		ld t = arg(vp[ni] - vp[i]);
		ts.push_back({ t,i });
		ts.push_back({ t - 2 * pi,i });
		ts.push_back({ t + 2 * pi,i });
	}
	sort(all(ts));
	auto getps = [&](ld theta) {
		vector<int> res;
		rep(i, 4) {
			int loc = lower_bound(all(ts), pair<ld, int>{ theta, -1 }) - ts.begin();
			res.push_back(ts[loc].second);
			theta += pi/2;
			while (theta >= pi)theta -= 2 * pi;
		}
		return res;
	};
	vector<bool> valid(n, true);
	vector<vector<int>> vneed(n);

	vector<bool> inr(2*vp.size());
	rep(i, n) {
		int cnt = 0;
		rep(j, vp.size()) {
			ld dist = abs(vp[j] - p[i]);
			inr[j] = inr[j+vp.size()]= (dist <= r);
			if (inr[j])cnt++;
		}
		rep(j, vp.size())if (!inr[j]) {
			while (j+1 < inr.size() && !inr[j+1])j++;
			if (j+1 < inr.size()) {
				vneed[i].push_back(j%vp.size());
				int cur = j + 1;
				while (cur + 1 < inr.size() && inr[cur + 1])cur++;
				vneed[i].push_back((cur + 1) % vp.size());
				int le = j + 1;
				if (cnt != cur - le + 1)valid[i] = false;
			}
		}
	}
	int ans = 0;
	rep(i, n)Rep(j, i + 1, n) {
		if (!valid[i] || !valid[j])continue;
		ld t = arg(p[j] - p[i]);
		Line l = { p[i],p[j] };
		vector<int> vv = getps(t);
		for (int id : vneed[i])vv.push_back(id);
		for (int id : vneed[j])vv.push_back(id);
		bool valid = true;
		rep(k, vv.size()) {
			Point z = vp[vv[k]];
			ld dist = dist_sp(l, z);
			//cout << i << " " << j << " " << z.first << " " << z.second << " " << dist << "\n";
			//cout << proj(l, z).first << " " << proj(l, z).second << "\n";
			if (dist > r)valid = false;
		}
		//cout << i << " " << j << " " << valid << "\n";
		if (valid)ans++;
	}
	cout << ans << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}