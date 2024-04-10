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
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

#define ftt function<T(T, T)>
#define ftu function<T(T,U,int,int)>
#define fuu function<U(U,U)>

template<typename T, typename U>
struct SegT {
private:
	int n;
	vector<T> node;
	vector<U> lazy;
	T et; U eu;
	ftt f;
	ftu g;
	fuu h;
public:
	SegT(vector<T> ori, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		int sz = ori.size();
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
		rep(i, sz) {
			node[i + n - 1] = ori[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int sz, T _et, U _eu, ftt _f, ftu _g, fuu _h) {
		et = _et, eu = _eu; f = _f, g = _g, h = _h;
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, et);
		lazy.resize(2 * n - 1, eu);
	}
	void eval(int k, int l, int r) {
		if (lazy[k] == eu)return;
		node[k] = g(node[k], lazy[k], l, r);
		if (r - l > 1) {
			lazy[2 * k + 1] = h(lazy[k], lazy[2 * k + 1]);
			lazy[2 * k + 2] = h(lazy[k], lazy[2 * k + 2]);
		}
		lazy[k] = eu;
	}
	void add(U x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = h(x, lazy[k]);
			eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return et;
		if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int searchloc(ll x) {
		int k = 0, l = 0, r = n;
		eval(k, l, r);
		if (node[k] < x)return n;
		while (k < n - 1) {
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			if (node[2 * k + 1] >= x) {
				k = 2 * k + 1; r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2; l = (l + r) / 2;
			}
		}
		return k - (n - 1);
	}
};

struct BIT {
private:
	vector<ll> node, node2,node3; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0); node2.resize(n, 0),node3.resize(n,0);
	}
	//0-indexed
	void add(int a, int b, LP w) {
		for (int i = a; i < n; i |= i + 1)node[i] += -a * w.first;
		for (int i = b; i < n; i |= i + 1)node[i] += b * w.first;
		for (int i = a; i < n; i |= i + 1)node2[i] += w.first;
		for (int i = b; i < n; i |= i + 1)node2[i] += -w.first;
		for (int i = a; i < n; i |= i + 1)node[i] += -(ll)a*(a-1)/2 * w.second;
		for (int i = b; i < n; i |= i + 1)node[i] += (ll)b*(b-1)/2 * w.second;
		for (int i = a; i < n; i |= i + 1)node3[i] += w.second;
		for (int i = b; i < n; i |= i + 1)node3[i] += -w.second;
	}
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += a * node2[i];
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += (ll)a*(a-1)/2 * node3[i];
		return ret;
	}
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

using speP = pair<int, ll>;
void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	vector<ll> b(m); rep(i, m)cin >> b[i];
	auto h = [&](speP a, speP b)->speP {
		return { a.first+b.first,a.second+b.second };
	};
	vector<ll> mem(m + 1);
	BIT bt(m);
	rep(i, m) {
		bt.add(i, i + 1, { b[i],0 });
	}
	auto ff = [&](ll a, ll b) {
		return max(a, b);
	};
	auto gg = [&](ll a, int b, int l, int r) {
		return a + b;
	};
	auto hh = [&](int a, int b) {
		return a + b;
	};
	vector<ll> difs(m - 1);
	rep(i, m - 1) {
		difs[i] = b[i + 1] - b[i];
	}
	SegT<ll, int> stma(difs, INF, 0, ff, gg, hh);
	auto query = [&]() {
		ll res = 0;
		int cy = 0;
		rep(i, n - 1) {
			ll dif = a[i + 1] - a[i];
			int loc = stma.searchloc(dif);
			cy = min(cy, m - 1);
			//[cy,loc]
			res += bt.sum(cy, loc + 1);
			res += a[i] * (loc - cy + 1);
			cy = loc;
		}
		res += bt.sum(cy, m);
		res += a[n - 1] * (m - cy);
		return res;
	};
	rep(i, q) {
		int typ; cin >> typ;
		int k; ll d; cin >> k >> d;
		if (typ == 1) {
			for (int j = n - k; j < n; j++) {
				a[j] += d * (j - (n - k - 1));
			}
		}
		else {
			bt.add(m - k, m, { -d * (m - k - 1),d });
			int mk = min(k, m - 1);
			stma.add(d, m - 1 - mk, m - 1);
		}
		cout << query() << "\n";
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}