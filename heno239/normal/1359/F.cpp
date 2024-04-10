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
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
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
const ld pi = acos(-1.0);

void chmin(int &a, int b) {
	a = min(a, b);
}
void chmax(int &a, int b) {
	a = max(a, b);
}
ll mod_pow(ll a, ll n, ll m = mod) {
	a %= m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 10001000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct Point {
	ld x, y;
};
struct Line {
	Point a, b;
};

bool intersect1d(ld l1, ld r1, ld l2, ld r2) {
	if (l1 > r1)
		swap(l1, r1);
	if (l2 > r2)
		swap(l2, r2);
	return max(l1, l2) <= min(r1, r2) + eps;
}

int vec(const Point& a, const Point& b, const Point& c) {
	ld s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return abs(s) < eps ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const Line& a, const Line& b)
{
	return intersect1d(a.a.x, a.b.x, b.a.x, b.b.x) &&
		intersect1d(a.a.y, a.b.y, b.a.y, b.b.y) &&
		vec(a.a, a.b, b.a) * vec(a.a, a.b, b.b) <= 0 &&
		vec(b.a, b.b, a.a) * vec(b.a, b.b, a.b) <= 0;
}

struct eve {
	ld x; int tp,id;
	eve(){}
	eve(ld x,int tp,int id):x(x),tp(tp),id(id){}
	bool operator<(const eve& e)const {
		if (abs(x - e.x) > eps)return x < e.x;
		return tp > e.tp;
	}
};


set<Line> s;
vector<set<Line>::iterator> itrs;

set<Line>::iterator aprev(set<Line>::iterator it) {
	return it == s.begin() ? s.end() : --it;
}
set<Line>::iterator anext(set<Line>::iterator it) {
	return ++it;
}

ld get_y(const Line &l, ld x) {
	if (abs(l.a.x-l.b.x) < eps)return l.a.y;
	return l.a.y + (l.b.y - l.a.y)*(x- l.a.x) / (l.b.x - l.a.x);
}
bool operator<(const Line &a, const Line &b) {
	ld x = max(min(a.a.x, a.b.x), min(b.a.x, b.b.x));
	return get_y(a, x) < get_y(b, x);
}

bool exist_intersect(vector<Line> &a){
	int n = a.size();
	vector<eve> e;
	rep(i, n) {
		e.push_back(eve{ min(a[i].a.x,a[i].b.x),1,i });
		e.push_back(eve{max(a[i].a.x,a[i].b.x),-1,i });
	}
	sort(all(e));
	s.clear();
	itrs.resize(n);

	rep(i, e.size()) {
		int id = e[i].id;
		if (e[i].tp > 0) {
			auto nxt = s.lower_bound(a[id]), prv = aprev(nxt);
			if (nxt != s.end() && intersect(*nxt, a[id]))return true;
			if (prv != s.end() && intersect(*prv, a[id]))return true;
			itrs[id] = s.insert(nxt, a[id]);
		}
		else {
			auto nxt = anext(itrs[id]), prv = aprev(itrs[id]);
			if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv)) {
				return true;
			}
			s.erase(itrs[id]);
		}
	}
	return false;
}

void solve() {
	int n; cin >> n;
	vector<ld> x(n), y(n), vx(n), vy(n), s(n);
	rep(i, n) {
		cin >> x[i] >> y[i] >> vx[i] >> vy[i] >> s[i];
		ld r = sqrtl(vx[i] * vx[i] + vy[i] * vy[i]);
		vx[i] *= s[i] / r;
		vy[i] *= s[i] / r;
	}
	ld le = 0, ri = 1e+10;

	bool exi = false;
	rep(aa, 60) {
		ld m = (le + ri) / 2.0;
		vector<Line> vl;
		rep(i, n) {
			Point pl = { x[i],y[i] };
			Point pr = { x[i] + vx[i] * m,y[i]+vy[i]*m };
			vl.push_back({ pl,pr });
		}
		if (exist_intersect(vl)) {
			exi = true;
			ri = m;
		}
		else {
			le = m;
		}
	}
	if (!exi) {
		cout << "No show :(" << "\n";
	}
	else {
		cout << ri << "\n";
	}
}

signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cout << fixed << setprecision(7);
	//init_f();
	//init();
	
	solve();
	stop
		return 0;
}