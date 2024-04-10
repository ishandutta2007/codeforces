#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
constexpr ll mod = 1000000009;
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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	SegT(vector<int> v) {
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
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void findall(vector<int>& v, int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return;
		else if (a <= l && r <= b){
			if (node[k] != x)return;
			if (k >= sz - 1) {
				v.push_back(k - (sz - 1)); return;
			}
			findall(v, x, a, b, k * 2 + 1, l, (l + r) / 2);
			findall(v, x, a, b, k * 2 + 2, (l + r) / 2, r);
		}
		else {
			findall(v, x, a, b, k * 2 + 1, l, (l + r) / 2);
			findall(v, x, a, b, k * 2 + 2, (l + r) / 2, r);
		}
	}
};


struct Seg2T {
private:
	vector<int> node; int sz;
	vector<int> vy;
	const int init_c = -mod;
public:
	int f(int a, int b) {
		return max(a, b);
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
	void update(int k, int c) {
		k = lower_bound(vy.begin(), vy.end(), k) - vy.begin();
		k += sz - 1;
		node[k] = f(node[k], c);
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int query(int a, int b) {
		a = lower_bound(vy.begin(), vy.end(), a) - vy.begin();
		b = lower_bound(vy.begin(), vy.end(), b) - vy.begin();
		return query(a, b, 0, 0, sz);
	}
};

struct SegTree {
private:
	int sz;
	vector<Seg2T> node;
	const int init_c =-mod;
public:
	int f(int a, int b) {
		return max(a, b);
	}
	SegTree(vector<P> v, int n) {
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
	void update(int x, int y, int c) {
		x += sz - 1;
		node[x].update(y, c);
		while (x) {
			x = (x - 1) / 2;
			node[x].update(y, c);
		}
	}
	int query(int a, int b, int x, int y, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k].query(x, y);
		else {
			int vl = query(a, b, x, y, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, x, y, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> vx;
	rep(i, n) {
		vx.push_back(a[i]);
	}
	sort(all(vx));
	vx.erase(unique(all(vx)), vx.end());
	rep(i, n) {
		a[i] = lower_bound(all(vx), a[i]) - vx.begin();
	}
	SegT st(a);
	struct ste {
		int x, y, val;
	};
	vector<ste> ps;
	//[l,r)
	function<void(int, int)> dfs = [&](int l, int r) {
		if (l >= r)return;
		//cout << "ee " << l << " " << r << "\n";
		int mi = st.query(l, r);
		ps.push_back({ r - l,l,mi });
		vector<int> nx;
		st.findall(nx,mi, l, r);
		int le = l;
		for (int id : nx) {
			dfs(le, id);
			le = id + 1;
		}
		dfs(le, r);
	};
	dfs(0, n);
	struct qste {
		int x, yl, yr, id;
	};

	vector<P> ori;
	for (ste s : ps) {
		ori.push_back({ s.x,s.y });
		//ad[s.x].push_back({ s.y,s.val });
	}
	SegTree stq(ori,n+1);

	vector<qste> vq;
	int q; cin >> q; rep(i, q) {
		int l, r, w; cin >> l >> r >> w; l--; r--;
		vq.push_back({ w,l,r - w + 1,i });
	}
	vector<int> ans(q, 0);

	vector<vector<ste>> ads(2 * n + 5);
	vector<vector<qste>> querys(2 * n + 5);
	for (ste s : ps) {
		ads[s.x + s.y].push_back({ s.x,s.y,s.val });
	}
	for (qste s: vq) {
		querys[s.x + s.yl].push_back({ s.x,s.yl,s.yr,s.id });
	}
	for (int i = 2 * n + 4; i >= 0; i--) {
		for (ste s : ads[i]) {
			stq.update(s.x, s.y, s.val);
		}
		for (qste s : querys[i]) {
			int val = stq.query(s.x, n + 1, 0, s.yr + 1);
			if (val < 0)val = 0;
			ans[s.id] = val;
		}
	}

	rep(i, q)cout << vx[ans[i]] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}