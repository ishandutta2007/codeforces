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

ll mod_pow(ll x, ll n,ll m) {
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
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
	int find_par(int a, int b) {
		int l = lca(a, b);
		if (l != a)return parent[a][0];
		else {
			int d = depth[b] - depth[a];
			d--;
			int res = b;
			rep(i, tmp)if (d & (1 << i)) {
				res = parent[res][i];
			}
			return res;
		}
	}
	int query(int len,int b, int na) {
		int l = lca(b, na);
		if (depth[na] - depth[l] < len) {
			int d = depth[na] + depth[b] - 2 * depth[l];
			d = d - len;
			int res = b;
			rep(i, tmp)if (d & (1 << i)) {
				res = parent[res][i];
			}
			return res;
		}
		else {
			int res = na;
			rep(i, tmp)if (len & (1 << i)) {
				res = parent[res][i];
			}
			return res;
		}
	}
};

const int mn = 1 << 18;
struct edge {
	int to; ll cost;
};
using Data = P;
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
int root;

Data merge(Data a, Data b) {
	Data res;
	//
	res = max(a, b);
	//
	return res;
}

map<P, P> mp;
Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res = { 0,id };
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
	}
	mp[{id, fr}] = res;
	//
	//update for return
	res.first++;
	//
	return res;
}
bool isgod[mn];
int ablen;
void invdfs(int id, int fr, Data pre) {
	vector<Data> v;
	for (Data d : memo[id])v.push_back(d);
	if (fr >= 0)v.push_back(pre);
	int len = v.size();
	//
	//calcurate id's ans
	int cnt = 0;
	for (Data d: v) {
		if (d.first >= ablen)cnt++;
	}
	if (cnt >= 3)isgod[id] = true;
	else isgod[id] = false;
	//
	vector<Data> le(len + 1);
	vector<Data> ri(len + 1);
	//
	Data init_c = { 0,id };
	//
	le[0] = init_c;
	rep(i, len) {
		le[i + 1] = merge(le[i], v[i]);
	}
	ri[len] = init_c;
	per(i, len) {
		ri[i] = merge(ri[i + 1], v[i]);
	}
	rep(i, ids[id].size()) {
		int to = ids[id][i];
		Data d = merge(le[i], ri[i + 1]);

		mp[{id, to}] = d;
		//
		//update for return
		d.first++;
		//
		invdfs(to, id, d);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, { -1,-1 });
}

void solve(){
	int n, a, b; cin >> n >> a >> b; a--; b--;
	rep(i, n) {
		G[i].clear();
		ids[i].clear();
		memo[i].clear();
	}
	mp.clear();

	lcagraph lg(n);
	rep(i, n - 1) {
		int x, y; cin >> x >> y; x--; y--;
		G[x].push_back({ y });
		G[y].push_back({ x });

		lg.add_edge(x, y);
	}
	lg.complete();

	ablen = lg.dist(a, b);
	yaru();

	rep(i, 2*ablen + 2) {
		int p = lg.find_par(a,b);
		int na = mp[{a, p}].second;
		int nb = lg.query(ablen, b, na);
		a = na, b = nb;

		swap(a, b);
		//cout << "! " << p<<" "<<a << " " << b << "\n";
	}
	vector<bool> can(n, false);
	int p = lg.find_par(a, b);
	queue<P> que;
	que.push({ a,p });
	while (!que.empty()) {
		P p = que.front(); que.pop();
		can[p.first] = true;
		for (edge e : G[p.first]) {
			if (e.to == p.second)continue;
			que.push({ e.to,p.first });
		}
	}
	string ans = "NO";
	rep(i, n)if (can[i] && isgod[i])ans = "YES";
	cout << ans << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//cout << grandy(2, 3, false, false) << "\n";
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}