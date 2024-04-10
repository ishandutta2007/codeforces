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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

struct LowLink {
private:
	vector<vector<int>> G;
	vector<int> used, ord, low;
	vector<int> art;

	//make graph with bridge
	vector<vector<int>> fG;
	vector<vector<int>> ori;
	vector<int> trans;
public:
	LowLink(int n) {
		G.resize(n);
		used.resize(n, 0);
		ord.resize(n, 0);
		low.resize(n, 0);
	}
	void add_edge(int a, int b) {
		if (a == b)return;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int dfs(int id, int k, int par) {
		used[id] = true;
		ord[id] = k++;
		low[id] = ord[id];
		bool is_art = false;
		int cnt = 0;
		for (auto&& to : G[id]) {
			if (!used[to]) {
				++cnt;
				k = dfs(to, k, id);
				low[id] = min(low[id], low[to]);
				if (~par && low[to] >= ord[id])is_art = true;
			}
			else if (to != par) {
				low[id] = min(low[id], ord[to]);
			}
		}
		if (par == -1 && cnt > 1)is_art = true;
		if (is_art)art.push_back(id);
		return k;
	}
	void complete() {
		int k = 0;
		rep(i, G.size()) {
			if (!used[i]) {
				k = dfs(i, k, -1);
			}
		}

	}
	vector<int> arts() {
		return art;
	}
	vector<bool> isart;
	int dfs2(int id, int par, int nm, int& tmp) {
		trans[id] = nm;
		ori[nm].push_back(id);
		used[id] = true;
		int memo = nm;
		if (isart[id]) {
			if (par >= 0) {
				fG[id].push_back(nm);
				fG[nm].push_back(id);
				nm = tmp; tmp++;
				ori[nm].push_back(id);
			}
			for (int to : G[id])if (!used[to]) {
				if (low[to] < ord[id]) {
					dfs2(to, id, memo, tmp);
				}
				else {
					fG[id].push_back(nm);
					fG[nm].push_back(id);
					int memo2 = nm;
					nm = tmp; tmp++;
					ori[nm].push_back(id);
					dfs2(to, id, memo2, tmp);
				}
			}
		}
		else {
			for (int to : G[id])if (!used[to]) {
				dfs2(to, id, nm, tmp);
			}
		}
		return memo;
	}
	//root is n
	//number of vertice is less than N+2*M
	void makegraph_vertice(int sz) {
		int n = G.size();
		fG.resize(sz);
		ori.resize(sz);
		trans.resize(n);
		fill(all(used), false);
		isart.resize(n);
		for (int id : art)isart[id] = true;
		int tmp = n + 1;
		dfs2(0, -1, n, tmp);
		rep(i, n)if (isart[i]) {
			trans[i] = i; ori[i] = { i };
		}
	}
	vector<vector<int>> get_graph() {
		return fG;
	}
	vector<int> get_trans() {
		return trans;
	}
	vector<vector<int>> get_ori() {
		return ori;
	}
	void debug() {
		rep(i, ori.size()) {
			cout << "hai " << i << "\n";
			for (int id : ori[i])cout << id << " ";
			cout << "\n";
		}
		cout << "trans\n";
		rep(i, trans.size())cout << trans[i] << " ";
		cout << "\n";
	}
};


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
};

vector<int> cori;
using edges = vector<int>;
using Graph = vector<edges>;
struct HLDecomposition {
	struct Chain {
		int depth;
		P parent;//chain number,index
		vector<P> child;//child chain number,parent index
		vector<int> mapfrom;
		SegT stree;

		//Chain() { ; }
		Chain(vector<int> ori) :stree(ori) { ; }
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;//raw index->chain number &index
	vector<vector<int>> mapfrom;//chain number & index ->raw index

	HLDecomposition() { ; }
	HLDecomposition(const Graph& g,int root) {
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		int start = root;
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
			for (int to : baseG[from]) {
				if (to == parent)continue;
				que.push({ to,from });
			}
		}
		//assert(cnt == n);
		reverse(all(ord));
		rep(i, n) {
			int from = ord[i];
			if (from < 0)continue;
			sz[from] = 1; for (int to : baseG[from]) {
				sz[from] += sz[to];
			}
		}
	}
	int decomposition(int from, int parent, int depth, int pnumber, int pindex, const vector<int>& sz) {
		vector<int> seq;
		bfs(from, parent, seq, sz);
		const int c = chains.size();
		vector<int> ori;
		for (int id : seq)ori.push_back(cori[id]);
		chains.push_back(Chain(ori));
		//chains.push_back(Chain());
		chains[c].depth = depth;
		chains[c].parent = { pnumber,pindex };
		rep(i, seq.size()) {
			mapto[seq[i]] = { c,i };
			chains[c].mapfrom.push_back(seq[i]);
		}
		mapfrom.push_back(chains[c].mapfrom);
		rep(i, seq.size()) {
			for (int to : baseG[seq[i]]) {
				if (mapto[to].first != -1)continue;
				int nc = decomposition(to, seq[i], depth + 1, c, i, sz);
				chains[c].child.push_back({ nc,i });
			}
		}
		return c;
	}
	void bfs(int from, int parent, vector<int>& seq, const vector<int>& sz) {
		for (;;) {
			seq.push_back(from);
			int best = -1, next = -1;
			for (int to : baseG[from]) {
				if (to == parent)continue;
				if (best < sz[to]) {
					best = sz[to]; next = to;
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
	vector<pair<int, P>> all_vertice(int u, int v) {
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
		res.push_back({ mapto[v].first,{ p.first,p.second + 1 } });
		return res;
	}

public:

	void vertice_update(int v, int a) {
		int loc = mapto[v].first, id = mapto[v].second;
		chains[loc].stree.update(id, a);
	}
	int vertice_query(int u, int v) {
		vector<pair<int, P>> vs = all_vertice(u, v);
		int res = mod;
		rep(i, vs.size()) {
			int id = vs[i].first;
			int l = vs[i].second.first; int r = vs[i].second.second;
			res = min(res,chains[id].stree.query(l, r));
		}
		return res;
	}
};
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

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vector<int> w(n);
	rep(i, n)cin >> w[i];
	LowLink lt(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		lt.add_edge(a, b);
	}
	lt.complete(); lt.makegraph_vertice(n+2*m);
	vector<vector<int>> g = lt.get_graph();
	vector<int> arts = lt.arts();
	if (arts.empty()) {
		multiset<int> st;
		rep(i, n) {
			st.insert(w[i]);
		}
		rep(i, q) {
			char c; cin >> c;
			if (c == 'C') {
				int v, val; cin >> v >> val; v--;
				st.erase(st.find(w[v]));
				st.insert(val);
				w[v] = val;
			}
			else {
				int l, r; cin >> l >> r; l--; r--;
				if (l == r) {
					cout << w[l] << "\n";
				}
				else {
					cout << (*st.begin()) << "\n";
				}
			}
		}

		return;
	}
	vector<bool> isart(n,false);
	for (int id : arts)isart[id] = true;
	vector<int> trans = lt.get_trans();
	vector<vector<int>> invtrans = lt.get_ori();
	vector<multiset<int>> vs(g.size());
	rep(i, n) {
		int loc = trans[i];
		vs[loc].insert(w[i]);
	}
	int root = -1;
	rep(i, g.size())if (g[i].size())root = i;
	vector<int> par(n + 2 * m,-1);
	//cout << n + 2 * m <<" "<< g.size() << "\n";
	function<void(int, int)> dfs = [&](int id, int fr) {
		//cout << id << "\n";
		par[id] = fr;
		for (int to : g[id])if(to!=fr) {
			dfs(to, id);
		}
	}; dfs(root, -1);
	cori.resize(n + 2 * m,mod);
	vector<multiset<int>> chs(n + 2 * m);
	rep(i, n + 2 * m) {
		if (vs[i].empty())cori[i] = mod;
		else cori[i] = (*vs[i].begin());
	}
	rep(i, n)if (isart[i]) {
		int loc = trans[i];
		if (par[loc] >= 0) {
			chs[par[loc]].insert(w[i]);
		}
	}
	rep(i, n + 2 * m) {
		if (chs[i].size()) {
			cori[i] = min(cori[i], (*chs[i].begin()));
		}
	}
	HLDecomposition hld(g,root);
	lcagraph lc(n + 2 * m);
	rep(i, g.size())for (int to : g[i])if (i < to)lc.add_edge(i, to);
	lc.complete(root);
	rep(i, q) {
		char c; cin >> c;
		if (c == 'C') {
			int v, val; cin >> v >> val; v--;
			int loc = trans[v];
			if (isart[v]) {
				hld.vertice_update(loc, val);
				if (par[loc] >= 0) {
					int p = par[loc];
					chs[p].erase(chs[p].find(w[v]));
					chs[p].insert(val);
					int mi = mod;
					mi = min(mi, *chs[p].begin());
					if (vs[p].size())mi = min(mi, *vs[p].begin());
					hld.vertice_update(p, mi);
				}
			}
			else {
				vs[loc].erase(vs[loc].find(w[v]));
				vs[loc].insert(val);
				int p = loc;
				int mi = mod;
				if(chs[p].size())mi = min(mi, *chs[p].begin());
				if (vs[p].size())mi = min(mi, *vs[p].begin());
				hld.vertice_update(p, mi);
			}

			w[v] = val;
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			if (l == r) {
				cout << w[l] << "\n"; continue;
			}
			l = trans[l], r = trans[r];
			int ans = hld.vertice_query(l, r);
			int t = lc.lca(l, r);
			bool can = true;
			if (par[t] < 0)can = false;
			if (invtrans[t].size() == 1) {
				int z = invtrans[t][0];
				if (isart[z])can = false;
			}
			//cout << l << " " << r << " " << t << " " << "\n";
			//cout << ans << "\n";
			if (can) {
				int p = par[t];
				p = invtrans[p][0];
				ans = min(ans, w[p]);
			}
			cout << ans << "\n";
		}
	}
	//cout << root << "\n";
	/*rep(i, n + 2 * m) {
		if (invtrans[i].size()) {
			cout << i << "\n";
			for (int id : invtrans[i])cout << id << " ";
			cout << "\n";
		}
	}*/
	//rep(i, n + 2 * m)for (int to : g[i])cout << i << " " << to << "\n";
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