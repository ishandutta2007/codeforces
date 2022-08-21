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
const int max_n = 1 << 1;
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
struct BIT {
private:
	vector<ll> node; int n;
public:
	void init(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

struct SegT {
private:
	int n; vector<LP> node;
	vector<ll> lazy;
public:
	void init(vector<LP> ori) {
		int sz = ori.size();
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, LP{ INF,-1 });
		lazy.resize(2 * n - 1, 0);
		rep(i, sz)node[i + n - 1] = ori[i];
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	/*SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, LP{ INF,-1 });
		lazy.resize(2 * n - 1, 0);
	}*/
	LP f(LP a, LP b) {
		return min(a, b);
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
	LP query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return { INF,-1 };
		if (a <= l && r <= b)return node[k];
		else {
			LP vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			LP vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int loc, LP x) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k, l, r);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k, l, r);
		st.push({ l,r });
		node[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			st.pop();
			l = st.top().first, r = st.top().second;
			eval(2 * k + 1, l, (l + r) / 2);
			eval(2 * k + 2, (l + r) / 2, r);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};


vector<ll> curval;
vector<vector<int>> vv;
vector<int> vloc;
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
		BIT bt;

		//Chain() { ; }
		//Chain(int n) :stree(n) { ; }
		Chain(vector<int> seq) {
			vector<LP> ori(seq.size());
			rep(i, seq.size()) {
				ori[i] = { curval[seq[i]],seq[i] };
			}
			stree.init(ori);
			bt.init(seq.size());
		}
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
		chains.push_back(seq);
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
	vector<int> szs;
	vector<int> tra;
	void init() {
		szs.resize(chains.size());
		rep(i, baseG.size()) {
			szs[mapto[i].first]++;
		}
		tra.resize(chains.size());
	}
	ll pre_add(int u) {
		ll res = 0;
		while (u > 0) {
			int r = chains[u].parent.second;
			u = chains[u].parent.first;
			res += chains[u].bt.sum(r + 1);
		}
		return res;
	}
	vector<int> vertice_query(int u, int v,int k) {
		vector<pair<int, P>> p = all_vertice(u, v);
		vector<ll> ads(p.size());
		rep(i, p.size()) {
			ads[i] = pre_add(p[i].first);
			tra[p[i].first] = i;
		}
		priority_queue<LP, vector<LP>, greater<LP>>q;
		rep(i, p.size()) {
			int id = p[i].first;
			int l = p[i].second.first;
			int r = p[i].second.second;
			LP val = chains[id].stree.query(l, r);
			if (val.second < 0)continue;
			val.first += ads[i];
			//cout << "ee " << val.first << " " << val.second << "\n";
			q.push(val);
		}
		vector<int> res;
		rep(_, k) {
			if (q.empty())break;
			LP pp = q.top(); q.pop();
			if (pp.first >= INF)break;
			int id = pp.second;
			//cout <<"? "<< pp.first << " " << pp.second << "\n";
			//cout << "??? " << id << " " << vloc[id] << "\n";
			res.push_back(vv[id][vloc[id]]);
			vloc[id]++;
			LP nval = { INF,-1 };
			int loc = tra[mapto[id].first];
			if (vloc[id] < vv[id].size()) {
				nval.first = vv[id][vloc[id]] - vv[id][vloc[id] - 1] + pp.first;
				nval.first -= ads[loc];
				nval.second = id;
			}
			int iid = mapto[id].first;
			int idk = mapto[id].second;
			chains[iid].stree.update(idk, nval);
			int l = p[loc].second.first;
			int r = p[loc].second.second;
			LP val = chains[iid].stree.query(l, r);
			if (val.second < 0)continue;
			val.first += ads[loc];
			q.push(val);
		}
		return res;
	}
	void vertice_add(int u, ll x) {
		chains[mapto[u].first].bt.add(mapto[u].second, x);
		//cout << "? " << mapto[u].second << " " << szs[mapto[u].first] << "\n";
		chains[mapto[u].first].stree.add(x, mapto[u].second, szs[mapto[u].first]);
	}
};




void solve() {
	int n, m, q; cin >> n >> m >> q;
	curval.resize(n, INF);
	Graph g(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back({ b });
		g[b].push_back({ a });
	}
	vloc.resize(n, 0);
	vv.resize(n);
	rep(i, m) {
		int c; cin >> c; c--;
		curval[c] = min(curval[c], (ll)i);
		vv[c].push_back(i);
	}
	//rep(i, n)cout << "? " << curval[i] << "\n";
	HLDecomposition hld(g);
	hld.init();
	rep(_, q) {
		int typ; cin >> typ;
		if (typ == 1) {
			int a, b, k; cin >> a >> b >> k; a--; b--;
			vector<int> ans = hld.vertice_query(a, b, k);
			cout << ans.size();
			rep(i, ans.size()) {
				cout << " " << ans[i] + 1;
			}
			cout << "\n";
		}
		else {
			int v, w; cin >> v >> w; v--;
			hld.vertice_add(v, w);
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
		solve();
	return 0;
}