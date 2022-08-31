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
//constexpr ll mod = 998244353;
constexpr ll mod = 1000000007;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
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

mt19937 mt(time(0));

const string drul = "DRUL";
string senw = "SENW";
//DRUL,or SENW
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

struct lcagraph {
private:
	int n;
	vector<vector<int>> G;
	vector<vector<int>> parent;
	vector<int> depth;
	int root;
	int tmp;
public:
	lcagraph(int n_) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = 0;
	}
	lcagraph() {}
	void init(int n_) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = 0;
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void dfs(int id, int fr, int d) {
		parent[id][0] = fr;
		depth[id] = d;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (to == fr)continue;
			dfs(to, id, d + 1);
		}
	}
	void sub_complete(int r) {
		dfs(r, -1, 0);
	}
	void complete() {
		rep(j, tmp - 1)rep(i, n) {
			if (parent[i][j] < 0)parent[i][j + 1] = -1;
			else parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
	int lca(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int k = 0; k < tmp; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[v][k];
			}
		}
		if (u == v)return u;
		for (int k = tmp - 1; k >= 0; k--) {
			if (parent[u][k] != parent[v][k]) {
				u = parent[u][k];
				v = parent[v][k];
			}
		}
		return parent[u][0];
	}
	int dep(int x) {
		return depth[x];
	}
	int dist(int x, int y) {
		int l = lca(x, y);
		return depth[x] + depth[y] - 2 * depth[l];
	}
	//from a to b
	int proc_d(int a, int b, int d) {
		int l = lca(a, b);
		int res;
		if (dep(a) - dep(l) >= d) {
			res = a;
			rep(i, tmp) {
				if (d & (1 << i))res = parent[res][i];
			}
		}
		else {
			d = dep(a) + dep(b) - 2 * dep(l) - d;
			res = b;
			rep(i, tmp) {
				if (d & (1 << i))res = parent[res][i];
			}
		}
		return res;
	}
};


//
//1
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
		if (node[k] == e||l+1==r)return;
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
		while (r-l>1) {
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

struct edge {
	int to, cost;
};
void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(q), b(q), x(q);
	rep(i, q) {
		cin >> a[i] >> b[i] >> x[i];
		a[i]--; b[i]--;
	}
	vector<bool> intree(q);
	uf u(n);
	vector<vector<edge>> G(n);
	lcagraph lc(n);
	rep(i, q) {
		if (!u.same(a[i], b[i])) {
			intree[i] = true;
			G[a[i]].push_back({ b[i],x[i] });
			G[b[i]].push_back({ a[i],x[i] });
			u.unite(a[i], b[i]);
			lc.add_edge(a[i], b[i]);
		}
	}
	vector<bool> used(n);
	vector<int> trans(n);
	vector<int> ri(n);
	int tmp = 0;
	vector<int> dep(n);
	vector<int> d(n);
	vector<int> par(n);
	rep(i, n)if (!used[i]) {
		function<void(int, int)> dfs = [&](int id, int fr) {
			par[id] = fr;
			used[id] = true;
			trans[id] = tmp; tmp++;
			for (edge e : G[id]) {
				if (e.to == fr)continue;
				d[e.to] = d[id] ^ e.cost;
				dep[e.to] = dep[id]+1;
				dfs(e.to, id);
			}
			ri[id] = tmp;
		};
		dfs(i, -1);
		lc.sub_complete(i);
	}
	lc.complete();

	auto f = [&](int a, int b) {
		return max(a, b);
	};
	SegT<int> st(n, 0, f);
	rep(i, q) {
		if (intree[i]) {
			cout << "YES\n";
		}
		else {
			int dd = d[a[i]] ^ d[b[i]] ^ x[i];
			if (dd == 0) {
				cout << "NO\n";
			}
			else {
				int l = lc.lca(a[i], b[i]);
				int da = st.query(trans[a[i]]);
				int db = st.query(trans[b[i]]);
				if (dep[l] >= da && dep[l] >= db) {
					int cur = a[i];
					while (cur != l) {
						st.add(dep[cur], trans[cur], ri[cur]);
						cur = par[cur];
					}
					cur = b[i];
					while (cur != l) {
						st.add(dep[cur], trans[cur], ri[cur]);
						cur = par[cur];
					}
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}