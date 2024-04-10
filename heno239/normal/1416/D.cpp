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

const int max_n = 1 << 19;
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

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
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

void solve() {
	int n, m, q; cin >> n >> m >> q;
	uf u(n);
	vector<int> p(n); rep(i, n)cin >> p[i];
	vector<int> a(m), b(m);
	rep(i, m) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
	}
	vector<int> t(q), v(q);
	rep(i, q) {
		cin >> t[i] >> v[i]; v[i]--;
	}
	vector<vector<int>> parent(2*n, vector<int>(19));
	rep(j, 2 * n)parent[j][0] = -1;
	vector<int> tm(2 * n,-1);
	vector<int> par(2*n);
	vector<vector<int>> G(2 * n);
	rep(i, 2 * n)par[i] = i;
	function<int(int)> find_par = [&](int x)->int {
		if (par[x] == x)return x;
		else return par[x] = find_par(par[x]);
	};
	int tmp = n;
	vector<bool> exi(m);
	rep(i, q) {
		if (t[i] == 2)exi[v[i]] = true;
	}
	rep(i, m)if (!exi[i]) {
		int le = a[i], ri = b[i];
		if (u.same(le, ri))continue;
		u.unite(le, ri);
		le = find_par(le);
		ri = find_par(ri);
		par[le] = tmp;
		par[ri] = tmp;
		parent[le][0] = tmp;
		parent[ri][0] = tmp;
		tm[le] = q; tm[ri] = q;
		G[tmp].push_back(le);
		G[tmp].push_back(ri);
		tmp++;
	}
	per(i, q) {
		if (t[i] == 2) {
			int le = a[v[i]], ri = b[v[i]];
			if (u.same(le, ri))continue;
			u.unite(le, ri);
			le = find_par(le);
			ri = find_par(ri);
			par[le] = tmp;
			par[ri] = tmp;
			parent[le][0] = tmp;
			parent[ri][0] = tmp;
			tm[le] = i; tm[ri] = i;
			G[tmp].push_back(le);
			G[tmp].push_back(ri);
			tmp++;
		}
	}
	rep(j, 18)rep(i, tmp) {
		if (parent[i][j] < 0)parent[i][j + 1] = -1;
		else {
			parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
	vector<int> invs(tmp);
	vector<int> trans(tmp);
	vector<int> ri(tmp);
	int loc = 0;
	function<void(int)> dfs = [&](int id) {
		trans[id] = loc; invs[loc] = id; loc++;
		for (int to : G[id])dfs(to);
		ri[id] = loc;
	};
	rep(i, tmp)if (parent[i][0] < 0) {
		dfs(i);
	}
	vector<P> ori(tmp, { 0,0 });
	rep(i, n) {
		ori[trans[i]] = { p[i],trans[i] };
	}
	auto f = [&](P a, P b) {
		return max(a, b);
	};
	SegT<P> st(ori, { 0,0 }, f);
	vector<int> ans;
	rep(i, q) {
		if (t[i] == 1) {
			int cur = v[i];
			per(j, 19) {
				if (parent[cur][j] < 0)continue;
				if (tm[parent[cur][j]] > i)cur = parent[cur][j];
			}
			if (tm[cur] > i)cur = parent[cur][0];
			assert(tm[cur] <= i);
			int l = trans[cur];
			int r = ri[cur];
			P p = st.query(l, r);
			if (p.first == 0) {
				ans.push_back(0);
			}
			else {
				ans.push_back(p.first);
				st.update(p.second, { 0,p.second });
			}
		}
	}
	rep(i, ans.size()) {
		cout << ans[i] << "\n";
	}
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