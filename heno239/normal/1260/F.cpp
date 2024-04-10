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
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}
ll mod_inv(ll a, ll m) {
	return mod_pow(a, m - 2, m);
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 500;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct SegT {
private:
	int n; vector<modint> node, lazy;
	const modint init_c = 0;
public:
	SegT() { ; }
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	modint f(modint a, modint b) {
		return a + b;
	}
	void eval(int k, int l, int r) {
		node[k] += lazy[k]*(modint)(r-l);
		if (r - l > 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(modint x, int a, int b, int k = 0, int l = 0, int r = -1) {
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
	modint query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			modint vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			modint vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
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

		Chain() { ; }
		Chain(int n):stree(n){;}
	};
	Graph baseG;
	vector<Chain> chains;
	vector<P> mapto;//raw index->chain number &index
	vector<vector<int>> mapfrom;//chain number & index ->raw index

	HLDecomposition() { ; }
	HLDecomposition(const Graph &g) {
		baseG = g;
		const int n = baseG.size();
		mapto = vector<P>(n, P{ -1,-1 });
		mapfrom.clear();
		vector<int> sz(n, 0);
		int start = 0;
		//rep(i, n)if (baseG[i].size() <= 1) { start = i; break; }
		//assert(start != -1);
		size_check_bfs(start, sz);
		decomposition(start, start, 0, 0, 0, sz);
	}
	int depth(int t) {
		return chains[mapto[t].first].depth;
	}

private:
	void size_check_bfs(int start, vector<int> &sz) {
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
	int decomposition(int from, int parent, int depth, int pnumber, int pindex, const vector<int> &sz) {
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
	void bfs(int from, int parent, vector<int> &seq, const vector<int> &sz) {
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
			res.push_back({ mapto[v].first,{0,mapto[v].second+1} });
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
		res.push_back({ mapto[v].first,{p.first + 1,p.second + 1 }});
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

	void edge_add(int u, int v,int a) {
		vector<pair<int, P>> es = all_edge(u, v);
		rep(i, es.size()) {
			int id = es[i].first;
			int l = es[i].second.first; int r = es[i].second.second;
			chains[id].stree.add(a, l, r);
		}
	}
	ll edge_sum(int u, int v) {
		vector<pair<int, P>> es = all_edge(u, v);
		ll res = 0;
		rep(i, es.size()) {
			int id = es[i].first;
			int l = es[i].second.first; int r = es[i].second.second;
			res+=chains[id].stree.query(l, r);
		}
		return res;
	}

	void vertice_add(int u, int v, int a) {
		vector<pair<int, P>> vs = all_vertice(u, v);
		rep(i, vs.size()) {
			int id = vs[i].first;
			int l = vs[i].second.first; int r = vs[i].second.second;
			chains[id].stree.add(a, l, r);
		}
	}
	modint vertice_sum(int u, int v) {
		vector<pair<int, P>> vs = all_vertice(u, v);
		modint res = 0;
		rep(i, vs.size()) {
			int id = vs[i].first;
			int l = vs[i].second.first; int r = vs[i].second.second;
			res += chains[id].stree.query(l, r);
		}
		return res;
	}
};

vector<int> ad[1 << 17];
vector<int> de[1 << 17];

int depth[1 << 17];
void init_dep(int id, int fr,Graph& G) {
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		depth[e.to] = depth[id] + 1;
		init_dep(e.to, id,G);
	}
}
void solve() {
	int n; cin >> n;

	vector<int> l(n), r(n);
	rep(i, n) {
		cin >> l[i] >> r[i];
	}
	Graph G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b });
		G[b].push_back({ a });
	}
	init_dep(0, -1, G);
	HLDecomposition hld(G);

	rep(i, n) {
		ad[l[i]].push_back(i);
		de[r[i]].push_back(i);
	}
	vector<modint> len(n);
	rep(i, n) {
		len[i] = r[i] - l[i] + 1;
	}
	modint pro = 1;
	rep(i, n) {
		pro *= len[i];
	}
	modint ca=0, cb=0, cc=0,cd=0;
	modint ans = 0;
	rep1(i, 100000) {
		for (int id : ad[i]) {
			modint g = (modint)1 / (modint)len[id];
			//cout << "add " << id << " " << hld.vertice_sum(0, id) << " " << hld.vertice_sum(0, 0) << endl;
			ca += (modint)depth[id]*g;
			cb += g;
			cc += (modint)depth[id]*g*g;
			cd += g*hld.vertice_sum(0, id); cd -= g*hld.vertice_sum(0, 0);
			hld.vertice_add(0, id, (modint)1 / (modint)len[id]);
		}
		modint sum = pro * ca*cb - pro * cc - (modint)2 * pro*cd;
		ans += sum;
		for (int id : de[i]) {
			modint g = (modint)1 / (modint)len[id];
			ca -= (modint)depth[id]*g;
			cb -= g;
			cc -= (modint)depth[id]*g*g;
			hld.vertice_add(0, id, (modint)-1 / (modint)len[id]);
			//cout << "erase " << id << " " << hld.vertice_sum(0, id) << " " << hld.vertice_sum(0, 0) << endl;
			cd -= g*hld.vertice_sum(0, id); cd += g*hld.vertice_sum(0, 0);
		}
	}
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f(); init();
	//int t; cin >> t; rep(i, t)solve();
	//while (cin >> n, n)solve();
	solve();
	stop
		return 0;
}