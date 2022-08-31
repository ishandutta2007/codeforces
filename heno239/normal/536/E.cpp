//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
const int max_n = 1 << 15;
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

vector<int> val;
struct Data {
	bool isall;
	int cl, cr, score;
};
Data f(Data a, Data b) {
	Data res;
	if (a.isall && b.isall) {
		res.isall = true;
		res.cl = a.cl + b.cl;
		res.cr = a.cr + b.cr;
		res.score = a.score + b.score;
	}
	else if (!a.isall && !b.isall) {
		res.isall = false;
		res.cl = a.cl;
		res.cr = b.cr;
		res.score = a.score + b.score + val[a.cr + b.cl];
	}
	else if (a.isall) {
		res.isall = false;
		res.cl = a.cl + b.cl;
		res.cr = b.cr;
		res.score = a.score + b.score;
	}
	else {
		res.isall = false;
		res.cl = a.cl;
		res.cr = a.cr+b.cr;
		res.score = a.score + b.score;
	}
	return res;
}
Data init_c = { true,0,0,0 };
struct SegT {
private:
	int sz; vector<Data> node;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, Data a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	Data query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			Data vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			Data vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
struct edge {
	int to;
};
using edges = vector<edge>;
using Graph = vector<edges>;
struct HLDecomposition {
	struct Chain {
		int depth;
		P parent;//chain number,index
		vector<P> child;//child chain number,parent index
		vector<int> mapfrom;
		SegT stree;

		//Chain() { ; }
		Chain(int n) :stree(n) { ; }
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;//raw index->chain number &index
	vector<vector<int>> mapfrom;//chain number & index ->raw index

	HLDecomposition() { ; }
	HLDecomposition(const Graph& g) {
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		int start = 0;
		//int start = -1;
		//rep(i, n)if (baseG[i].size() <= 1) { start = i; break; }
		//assert(start != -1);
		size_check_bfs(start, sz);
		decomposition(start, start, 0, 0, 0, sz);
	}
	int depth(int t) {
		return chains[mapto[t].first].depth;
	}

private:
	void size_check_bfs(int start, vector<int>& sz) {
		const int n = baseG.size();
		queue<P> que;
		que.push({ start,start });
		int cnt = 0; vector<int> ord(n, -1);
		while (!que.empty()) {
			int from, parent;
			tie(from, parent) = que.front(); que.pop();
			ord[cnt++] = from;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				que.push({ e.to,from });
			}
		}
		//assert(cnt == n);
		reverse(all(ord));
		rep(i, n) {
			int from = ord[i];
			sz[from] = 1; for (edge e : baseG[from])sz[from] += sz[e.to];
		}
	}
	int decomposition(int from, int parent, int depth, int pnumber, int pindex, const vector<int>& sz) {
		vector<int> seq;
		bfs(from, parent, seq, sz);
		const int c = chains.size();
		chains.push_back(Chain((int)seq.size()));
		//chains.push_back(Chain());
		chains[c].depth = depth;
		chains[c].parent = { pnumber,pindex };
		rep(i, seq.size()) {
			mapto[seq[i]] = { c,i };
			chains[c].mapfrom.push_back(seq[i]);
		}
		mapfrom.push_back(chains[c].mapfrom);
		rep(i, seq.size()) {
			for (edge e : baseG[seq[i]]) {
				if (mapto[e.to].first != -1)continue;
				int nc = decomposition(e.to, seq[i], depth + 1, c, i, sz);
				chains[c].child.push_back({ nc,i });
			}
		}
		return c;
	}
	void bfs(int from, int parent, vector<int>& seq, const vector<int>& sz) {
		for (;;) {
			seq.push_back(from);
			int best = -1, next = -1;
			for (edge e : baseG[from]) {
				if (e.to == parent)continue;
				if (best < sz[e.to]) {
					best = sz[e.to]; next = e.to;
				}
			}
			if (next == -1)break;
			parent = from; from = next;
		}
	}
	vector<pair<int, P>> all_edge(int u, int v) {
		vector<pair<int, P>> res;
		if (depth(u) > depth(v))swap(u, v);
		while (depth(v) > depth(u)) {
			res.push_back({ mapto[v].first,{ 0,mapto[v].second + 1 } });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		while (mapto[v].first != mapto[u].first) {
			res.push_back({ mapto[v].first,{ 0,mapto[v].second + 1 } });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
			res.push_back({ mapto[u].first,{ 0,mapto[u].second + 1 } });
			par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		P p = minmax(mapto[v].second, mapto[u].second);
		res.push_back({ mapto[v].first,{ p.first + 1,p.second + 1 } });
		return res;
	}

public:
	int lca(int a, int b) {
		if (depth(a) > depth(b))swap(a, b);
		while (depth(a) < depth(b)) {
			P par = chains[mapto[b].first].parent;
			b = mapfrom[par.first][par.second];
		}
		while (mapto[a].first != mapto[b].first) {
			P par = chains[mapto[a].first].parent;
			a = mapfrom[par.first][par.second];
			par = chains[mapto[b].first].parent;
			b = mapfrom[par.first][par.second];
		}
		int mi = min(mapto[a].second, mapto[b].second);
		return mapfrom[mapto[a].first][mi];
	}
	void update(int u,bool f) {
		Data d = { false,0,0,0 };
		if (f)d = { true,1,1,0 };
		chains[mapto[u].first].stree.update(mapto[u].second, d);
	}
	int query(int u, int v) {
		Data cu = init_c, cv = init_c;
		if (depth(u) > depth(v))swap(u, v);
		while (depth(u) < depth(v)) {
			cv = f(chains[mapto[v].first].stree.query(0, mapto[v].second + 1), cv);
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		while (mapto[u].first != mapto[v].first) {
			cv = f(chains[mapto[v].first].stree.query(0, mapto[v].second + 1), cv);
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
			cu = f(chains[mapto[u].first].stree.query(0, mapto[u].second + 1), cu);
			par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		int idu = mapto[u].second;
		int idv = mapto[v].second;
		int id = mapto[u].first;
		if (idu > idv) {
			cu = f(chains[id].stree.query(idv + 1, idu + 1),cu);
		}
		else if (idu < idv) {
			cv = f(chains[id].stree.query(idu + 1, idv + 1), cv);
		}
		swap(cu.cl, cu.cr);
		cu = f(cu, cv);
		int res = cu.score;
		res += val[cu.cl];
		if(!cu.isall)res += val[cu.cr];
		//cout << cu.isall<<" "<<cu.cl << " " << cu.cr << " " << cu.score << "\n";
		return res;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	val.resize(n);
	rep1(i, n - 1)cin >> val[i];
	vector<vector<int>> G(n);
	Graph g(n);
	vector<P> es;
	vector<P> vc;
	rep(i, n - 1) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		g[a].push_back({ b });
		g[b].push_back({ a });
		es.push_back({ a,b });
		vc.push_back({ c,i });
	}
	HLDecomposition hld(g);
	rep1(i, n - 1)hld.update(i, false);
	vector<int> depth(n);
	function<void(int, int)> dfs = [&](int id, int fr) {
		for (int to : G[id])if (to != fr) {
			depth[to] = depth[id] + 1;
			dfs(to, id);
		}
	};
	dfs(0,-1);
	vector<int> trans(n - 1);
	rep(i, n - 1) {
		int a = es[i].first;
		int b = es[i].second;
		if (depth[a] > depth[b])swap(a, b);
		trans[i] = b;
	}
	sort(all(vc),greater<P>());
	
	vector<P> qs;
	vector<P> qc;
	rep(i, q) {
		int u, v, c; cin >> u >> v >> c; u--; v--;
		qs.push_back({ u,v });
		qc.push_back({ c,i });
	}
	sort(all(qc),greater<P>());
	
	int loc = 0;
	vector<int> ans(q);
	rep(i, qc.size()) {
		while (loc < vc.size() && vc[loc].first >= qc[i].first) {
			int id = vc[loc].second;
			hld.update(trans[id],true);
			loc++;
		}
		int id = qc[i].second;
		//cout << id << "\n";
		ans[id] = hld.query(qs[id].first, qs[id].second);
	}
	rep(i, q)cout << ans[i] << "\n";
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