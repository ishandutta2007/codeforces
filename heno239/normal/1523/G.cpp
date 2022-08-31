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

struct Seg2T {
private:
	vector<ll> node; int sz;
	vector<int> vy;
	const ll init_c = INF;
public:
	ll f(ll a, ll b) {
		return min(a, b);
	}
	void add(int y) {
		vy.push_back(y);
	}
	void complete() {
		sort(vy.begin(), vy.end());
		vy.erase(unique(vy.begin(), vy.end()), vy.end());
		int n = vy.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, ll c) {
		k = lower_bound(vy.begin(), vy.end(), k) - vy.begin();
		k += sz - 1;
		node[k] = f(node[k], c);
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	ll query(int a, int b) {
		a = lower_bound(vy.begin(), vy.end(), a) - vy.begin();
		b = lower_bound(vy.begin(), vy.end(), b) - vy.begin();
		return query(a, b, 0, 0, sz);
	}
};

struct SegT {
private:
	int sz;
	vector<Seg2T> node;
	const ll init_c = INF;
public:
	ll f(ll a, ll b) {
		return min(a, b);
	}
	SegT(vector<P> v, int n) {
		sz = 1; while (sz < n)sz *= 2; node.resize(sz * 2 - 1);
		rep(i, v.size()) {
			int k = v[i].first, y = v[i].second;
			k += sz - 1;
			node[k].add(y);
			while (k > 0) {
				k = (k - 1) / 2;
				node[k].add(y);
			}
		}
		rep(i, 2 * sz - 1)node[i].complete();
	}
	void update(int x, int y, ll c) {
		x += sz - 1;
		node[x].update(y, c);
		while (x) {
			x = (x - 1) / 2;
			node[x].update(y, c);
		}
	}
	ll query(int a, int b, int x, int y, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k].query(x, y);
		else {
			ll vl = query(a, b, x, y, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, x, y, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

struct BIT {
private:
	vector<ll> node, node2; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0); node2.resize(n, 0);
	}
	//0-indexed
	void add(int a, int b, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += -a * w;
		for (int i = b; i < n; i |= i + 1)node[i] += b * w;
		for (int i = a; i < n; i |= i + 1)node2[i] += w;
		for (int i = b; i < n; i |= i + 1)node2[i] += -w;
	}
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += a * node2[i];
		return ret;
	}
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}

};
void solve() {
	int n, m; cin >> n >> m;
	vector<int> l(m), r(m);
	rep(i, m) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	vector<P> ori(m);
	rep(i, m) {
		ori[i] = { l[i],r[i] };
	}
	SegT st(ori,n);
	vector<vector<int>> ids(n + 1);
	rep(i, m) {
		ids[r[i] - l[i] + 1].push_back(i);
	}
	BIT bt(n);
	vector<int> ans(n + 1);
	for (int c = n; c >= 1; c--) {
		for (int id : ids[c]) {
			st.update(l[id], r[id], id);
		}
		vector<int> mem;
		priority_queue<ll, vector<ll>, greater<ll>> q;
		q.push(st.query(0, n, 0, n));
		set<int> rs, ls;
		rs.insert(-1);
		ls.insert(n);
		while (!q.empty()) {
		    ll id = q.top(); q.pop();
			if (id == INF)continue;
			if (bt.sum(l[id], r[id] + 1) > 0)continue;
			bt.add(l[id], r[id] + 1, 1);
			mem.push_back(id);
			auto itrl = rs.lower_bound(l[id]);
			itrl--;
			int le = *itrl; le++;
			if (le < l[id]) {
				q.push(st.query(le, n, 0, l[id]));
			}
			auto itrr = ls.lower_bound(r[id]);
			int ri = *itrr;
			if (r[id] + 1 < ri) {
				q.push(st.query(r[id] + 1, n, 0, ri));
			}
			ls.insert(l[id]);
			rs.insert(r[id]);
		}
		ans[c] = bt.sum(0, n);
		for (int id : mem) {
			bt.add(l[id], r[id] + 1, -1);
		}
	}
	rep1(i, n)cout << ans[i] << "\n";
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