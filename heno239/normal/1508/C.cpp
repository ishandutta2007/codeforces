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
	void complete(int r = 0) {
		root = r;
		dfs(root, -1, 0);
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

const int b = 700;
int cost[b][b];

struct edge {
	int to, cost;
};
void solve() {
	int n, m; cin >> n >> m;
	if (n <= b) {
		int x = 0;
		rep(i, m) {
			int a, b, c; cin >> a >> b >> c; a--; b--;
			cost[a][b] = cost[b][a] = c;
			x ^= c;
		}
		vector<pair<int, P>> vp;
		rep(i, n)Rep(j, i + 1, n) {
			vp.push_back({ cost[i][j],{i,j} });
		}
		sort(all(vp));
		ll sum = 0;
		uf u(n);
		bool exi0 = false;
		vector<vector<edge>> G(n);
		vector<bool> used(vp.size());
		rep(i, vp.size()) {
			int a = vp[i].second.first;
			int b = vp[i].second.second;
			if (u.same(a, b)) {
				if (vp[i].first == 0)exi0 = true;
			}
			else {
				used[i] = true;
				sum += vp[i].first;
				u.unite(a, b);
				G[a].push_back({ b,vp[i].first });
				G[b].push_back({ a,vp[i].first });
			}
		}
		if (exi0) {
			cout << sum << "\n"; return;
		}
		vector<int> num(n);
		function<void(int, int)> dfs = [&](int id, int fr) {
			for (edge e : G[id])if (e.to != fr) {
				num[e.to] = num[id];
				if (e.cost == 0)num[e.to]++;
				dfs(e.to, id);
			}
		};
		dfs(0, -1);
		lcagraph lc(n);
		rep(i, n)for (edge e : G[i])if (i < e.to)lc.add_edge(i, e.to);
		lc.complete();
		ll ans = x + sum;
		rep(i, vp.size()) {
			if (!used[i]) {
				int a = vp[i].second.first;
				int b = vp[i].second.second;
				int l = lc.lca(a, b);
				int cnt = num[a] + num[b] - 2 * num[l];
				if (cnt > 0) {
					ans = min(ans, sum + vp[i].first);
				}
			}
		}
		cout << ans << "\n";
	}
	else {
		vector<vector<edge>> G(n);
		rep(i, m) {
			int a, b, c; cin >> a >> b >> c; a--; b--;
			G[a].push_back({ b,c });
			G[b].push_back({ a,c });
		}
		int mi = mod;
		int chk = -1;
		rep(i, n) {
			if (G[i].size() < mi) {
				mi = G[i].size();
				chk = i;
			}
		}
		vector<int> rs;
		vector<bool> used(n);
		for (edge e : G[chk]) {
			used[e.to] = true;
		}
		rep(i, n)if (!used[i]) {
			rs.push_back(i);
		}
		vector<int> cnt(n);
		vector<int> micost(n, 2*mod);
		for (int id : rs) {
			for (edge e : G[id]) {
				cnt[e.to]++;
				micost[e.to] = min(micost[e.to], e.cost);
			}
		}
		vector<int> vs;
		rep(i, n)if (used[i])vs.push_back(i);
		vs.push_back(chk);
		vector<int> trans(n);
		rep(j, vs.size())trans[vs[j]] = j;
		rep(i, vs.size()-1) {
			for (edge e : G[vs[i]]) {
				if (used[e.to]) {
					cost[i][trans[e.to]] = cost[trans[e.to]][i] = e.cost;
				}
			}
		}
		rep(i, vs.size()-1) {
			int c = micost[vs[i]];
			if (cnt[vs[i]] < rs.size())c = 0;
			cost[i][vs.size() - 1] = cost[vs.size() - 1][i] = c;
		}
		uf u(vs.size());
		vector<pair<int, P>> es;
		rep(i, vs.size())Rep(j, i + 1, vs.size()) {
			es.push_back({ cost[i][j],{i,j} });
		}
		sort(all(es));
		ll ans = 0;
		rep(i, es.size()) {
			int a = es[i].second.first;
			int b = es[i].second.second;
			if (u.same(a, b))continue;
			ans += es[i].first;
			u.unite(a, b);
		}
		cout << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}