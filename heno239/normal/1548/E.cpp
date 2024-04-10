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

//2DBIT
//[0,x),[0,y)
struct BIT {
private:
	vector<int> node; int n;
public:
	int f(int a, int b) {
		return a + b;
	}
	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//[0,a)
	int query(int a) {
		int ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret = f(ret, node[i]);
		return ret;
	}
	int query(int a, int b) {
		return query(b) - query(a);
	}
	void update(int a, int b) {
		for (int i = a; i < n; i |= i + 1)node[i] = f(node[i], b);
	}
};
struct BIT2 {
private:
	vector<BIT> node; int sz;
	vector<vector<int>> vy;
public:
	int f(int a, int b) {
		return a+b;
	}
	void init(int n) {
		sz = n; node.resize(n);
		vy.resize(n);
	}
	//
	void add(int x, int y) {
		for (int i = x; i < sz; i |= i + 1) {
			vy[i].push_back(y);
		}
	}
	//
	void complete() {
		rep(i, sz) {
			sort(vy[i].begin(), vy[i].end());
			vector<int> cop = vy[i];
			vy[i].erase(unique(vy[i].begin(), vy[i].end()), vy[i].end());
			int siz = vy[i].size();
			node[i].init(siz);
		}
	}
	int query(int x, int y) {
		int ret = 0;
		for (int i = x - 1; i >= 0; i = (i & (i + 1)) - 1) {
			int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
			ret = f(ret, node[i].query(idy));
		}
		return ret;
	}
	int query(int lx, int rx, int y) {
		return query(rx, y) - query(lx, y);
	}
	void update(int x, int y, int k) {
		for (int i = x; i < sz; i |= i + 1) {
			int idy = lower_bound(vy[i].begin(), vy[i].end(), y) - vy[i].begin();
			node[i].update(idy, k);
		}
	}
};


template<typename T>
struct SegT {
private:
	int sz; vector<T> node;
	T init_c;
	function<T(T, T)> f;
public:
	SegT(vector<T> v, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, T a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

using ar = array<int, 3>;


vector<ar> mk(vector<int>a,int x) {
	vector<ar> res;
	vector<P> ori;
	rep(i, a.size())ori.push_back({ a[i],i });
	auto f = [&](P a, P b) {return max(a, b); };
	SegT<P> st(ori, { -mod,-1 },f);
	auto g = [&](int a, int b) {return min(a, b); };
	SegT<int> stmi(a, { mod }, g);
	function<void(int, int)> yaru = [&](int l, int r) {
		if (l >= r)return;
		P p = st.query(l, r);
		ar z;
		z[0] = stmi.query(l, r);
		z[1] = p.first;
		int mi = x + 1;
		if (l > 0)mi = min(mi, a[l - 1]);
		if (r <a.size())mi = min(mi, a[r]);
		z[2] = mi;
		res.push_back(z);
		int id = p.second;
		yaru(l, id);
		yaru(id + 1, r);
	};
	yaru(0, a.size());
	return res;
}
void solve() {
	int n, m, x; cin >> n >> m >> x;
	vector<int> a(n); rep(i, n)cin >> a[i];
	vector<int> b(m); rep(i, m)cin >> b[i];
	auto va = mk(a, x);
	auto vb = mk(b, x);
	vector<P> qa, qb;
	rep(i, va.size()) {
		qa.push_back({ x-va[i][0],i });
	}
	rep(i, vb.size()) {
		qb.push_back({ vb[i][2],i });
	}
	sort(all(qa),greater<P>());
	sort(all(qb),greater<P>());
	BIT2 bt; bt.init(1 << 19);
	rep(i, vb.size()) {
		bt.add(vb[i][0], vb[i][1]);
	}
	bt.complete();
	int loc = 0;
	ll ans = 0;
	rep(i, qa.size()) {
		while (loc<qb.size() && qb[loc].first>qa[i].first) {
			int id = qb[loc].second; loc++;
			bt.update(vb[id][0], vb[id][1], 1);
			//cout << "hello\n";
		}
		int id = qa[i].second;
		int l = x - va[id][2] + 1; if (l < 0)l = 0;
		int r = x - va[id][1]+1;
		if (l < r) {
			int num = bt.query(l, r, x - va[id][0]+1);
			ans += num;
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}