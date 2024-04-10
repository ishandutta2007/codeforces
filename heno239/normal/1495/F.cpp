#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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

using ar = array<ll, 3>;

struct SegT {
private:
	int n; vector<pair<int,ar>> node;
	vector<int> lazy;
	const pair<int, ar> init_c = { mod,{0,0,0} };
public:
	SegT(vector<ar> ori) {
		int sz = ori.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = { 0,ori[i] };
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	pair<int, ar> f(pair<int, ar> a, pair<int, ar> b) {
		if (a.first != b.first)return min(a, b);
		else {
			ar res = { 0,0,0 };
			rep(i, 3)res[i] += a.second[i] + b.second[i];
			return { a.first,res };
		}
	}
	void eval(int k, int l, int r) {
		node[k].first += lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	pair<int,ar> query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			pair<int,ar> vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			pair<int,ar> vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
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

		Chain(vector<ar> v) :stree(v) { ; }
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;//raw index->chain number &index
	vector<vector<int>> mapfrom;//chain number & index ->raw index

	HLDecomposition() { ; }
	vector<ar> ori;
	HLDecomposition(const Graph& g,vector<ar> _ori,int root) {
		ori = _ori;
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		int start = root;
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
		vector<ar> sori;
		for (int id : seq)sori.push_back(ori[id]);
		chains.push_back(Chain(sori));
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


	ar vertice_add(int u, int v, int a) {
		ar res = { 0,0,0 };
		vector<pair<int, P>> vs = all_vertice(u, v);
		rep(i, vs.size()) {
			int id = vs[i].first;
			int l = vs[i].second.first; int r = vs[i].second.second;
			pair<int,ar>val = chains[id].stree.query(l, r);
			if (val.first == 0) {
				rep(i, 3)res[i] -= val.second[i];
			}
			chains[id].stree.add(a, l, r);
			val = chains[id].stree.query(l, r);
			if (val.first == 0) {
				rep(i, 3)res[i] += val.second[i];
			}
		}
		return res;
	}
};

void solve() {
	int n; cin >> n;
	int q; cin >> q;
	vector<int> p(n);
	rep(i, n)cin >> p[i];
	vector<ll> a(n), b(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	vector<int> ri(n);
	vector<P> vs;
	rep(i, n) {
		while (vs.size() && vs.back().first < p[i]) {
			ri[vs.back().second] = i;
			vs.pop_back();
		}
		vs.push_back({ p[i],i });
	}
	while (vs.size()) {
		ri[vs.back().second] = n;
		vs.pop_back();
	}
	vector<vector<int>> G(n+1);
	vector<int> par(n+1);
	rep(i, n) {
		int cur = i + 1;
		while (cur < ri[i]) {
			G[i].push_back(cur);
			cur = ri[cur];
		}
	}
	int loc = 0;
	while (loc < n) {
		G[n].push_back(loc);
		loc = ri[loc];
	}
	int root = n;
	rep(i, n+1)for (int to : G[i])par[to] = i;
	par[root] = -1;
	vector<ar> val(n+1);
	a.push_back(0); b.push_back(INF);
	function<void(int)> dfs = [&](int id) {
		val[id] = { a[id],0,a[id] };
		for (int to : G[id]) {
			dfs(to);
			val[id][0] += val[to][0];
			val[id][1] += val[to][0];
		}
		val[id][0] = min(val[id][0], b[id]);
	};
	dfs(root);
	Graph g(n+1);
	rep(i, n+1)for (int to : G[i])g[i].push_back({ to });
	HLDecomposition hld(g, val,root);
	ar cur = { 0,0,0 };
	ll suma = 0;
	rep(i, n+1) {
		rep(j, 3)cur[j] += val[i][j];
		suma += val[i][2];
	}
	//cout << "?? " << val[n][0] << "\n";
	//rep(i, n)cout << par[i] << "\n";
	//cout << cur[0] << " " << cur[1] << " " << cur[2] << "\n";
	vector<bool> exi(n);
	rep(i, q) {
		int x; cin >> x; x--;
		int ad = 1;
		if (exi[x]) {
			exi[x] = false;
			ad = -1;
		}
		else {
			exi[x] = true;
		}
		int p = par[x];
		ar val = hld.vertice_add(root, p, ad);
		rep(j, 3)cur[j] += val[j];
		ll ans = 0;
		ans = cur[0] - cur[1] + (suma - cur[2]);
		//cout << "ans is ";
		cout << ans << "\n";
		//cout << cur[0] << " " << cur[1] << " " << cur[2] << "\n";
	}

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