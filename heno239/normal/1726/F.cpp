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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
//mod should be <2^31
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
using ld = long double;
//typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-10;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 2000005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;
mP operator+(mP a, mP b) {
	return { a.first + b.first,a.second + b.second };
}
mP operator+=(mP& a, mP b) {
	a = a + b; return a;
}
mP operator-(mP a, mP b) {
	return { a.first - b.first,a.second - b.second };
}
mP operator-=(mP& a, mP b) {
	a = a - b; return a;
}
LP operator+(LP a, LP b) {
	return { a.first + b.first,a.second + b.second };
}
LP operator+=(LP& a, LP b) {
	a = a + b; return a;
}
LP operator-(LP a, LP b) {
	return { a.first - b.first,a.second - b.second };
}
LP operator-=(LP& a, LP b) {
	a = a - b; return a;
}

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

//
//1
//verified with https://codeforces.com/contest/1555/problem/F

template<typename T>
struct SegT {
private:
	int n;
	vector<T> node;
	T e;
	function<T(T, T)> f;
public:
	SegT(vector<T> ori, T _e, function<T(T, T)> _f) {
		int sz = ori.size();
		e = _e, f = _f;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, _e);
		rep(i, sz) {
			node[i + n - 1] = ori[i];
		}
	}
	SegT(int sz, T _e, function<T(T, T)> _f) {
		e = _e, f = _f;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, _e);
	}
	void eval(int k, int l, int r) {
		if (node[k] == e || l + 1 == r)return;
		node[2 * k + 1] = f(node[k], node[2 * k + 1]);
		node[2 * k + 2] = f(node[k], node[2 * k + 2]);
		node[k] = e;
	}
	void add(T x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			node[k] = f(x, node[k]);
			eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
		}
	}
	T query(int loc) {
		int k = 0, l = 0, r = n;
		while (r - l > 1) {
			eval(k, l, r);
			int m = (l + r) / 2;
			if (loc < m) {
				k = 2 * k + 1;
				r = m;
			}
			else {
				k = 2 * k + 2;
				l = m;
			}
		}
		return node[k];
	}
};

void solve() {
	int n, t; cin >> n >> t;
	vector<int> g(n), c(n);
	rep(i, n)cin >> g[i] >> c[i];
	vector<int> d(n-1);
	rep(i, n - 1)cin >> d[i];
	vector<ll> rd(n);
	rep(i, n - 1)rd[i + 1] = rd[i] + d[i];
	vector<int> vt;
	vt.push_back(0);
	vector<int> ls(n), rs(n);
	rep(i, n) {
		ll le = g[i];
		ll ri = t;
		le -= c[i] + rd[i];
		ri -= c[i] + rd[i];
		le %= t; if (le < 0)le += t;
		ri %= t; if (ri < 0)ri += t;
		ls[i] = le, rs[i] = ri;
		vt.push_back(le);
		vt.push_back(ri);
	}
	sort(all(vt));
	vt.erase(unique(all(vt)), vt.end());
	vector<int> ori(vt.size(),n);
	auto f = [&](int a, int b) {
		if (a < 0)return b;
		return a;
	};
	SegT<int> st(ori, -1, f);

	vector<int> nex(n+1);
	vector<ll> cost(n + 1);
	per(i, n) {
		int le = lower_bound(all(vt), ls[i]) - vt.begin();
		int ri = lower_bound(all(vt), rs[i]) - vt.begin();
		nex[i] = st.query(ri);
		if (le < ri)st.add(i, le, ri);
		else {
			st.add(i, le, vt.size());
			st.add(i, 0, ri);
		}
	}
	per(i, n) {
		int to = nex[i];
		if (to < n) {
			cost[i] = rs[to] - rs[i];
			if (cost[i] < 0)cost[i] += t;
			cost[i] += cost[to];
		}
	}
	ll ans = INF;
	rep(i, vt.size()) {
		int cur = vt[i];
		if (i + 1 == vt.size())cur = t - 1;
		else cur = vt[i + 1] - 1;
		int to = st.query(i);
		ll val = 0;
		if (to < n) {
			val = rs[to] - cur;
			if (val < 0)val += t;
		}
		chmin(ans, val + cost[to]+rd[n-1]);
	}
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init_f();
	//init();
	//expr();
	//while(true)
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}