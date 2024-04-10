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
constexpr ll mod = 998244353;
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

struct sparse_table {
private:
	int n;
	int tmp;
	vector<int> ori;
	vector<vector<int>> nodel,noder;
public:
	sparse_table(vector<int> _ori) {
		ori = _ori;
		n = ori.size();
		int cop = n;
		tmp = 0;
		while (cop > 0) {
			tmp++; cop >>= 1;
		}
		nodel.resize(n);
		noder.resize(n);
		rep(i, n) {
			nodel[i].resize(tmp);
			noder[i].resize(tmp);
		}
		rep(i, n) {
			nodel[i][0] = ori[i];
			noder[i][0] = ori[i];
		}
		rep(j, tmp - 1) {
			rep(i, n) {
				if (i + (1 << j) < n) {
					nodel[i][j + 1] = min(nodel[i][j], nodel[i + (1 << j)][j]);
				}
				if (i - (1 << j) >= 0) {
					noder[i][j + 1] = min(noder[i][j], noder[i - (1 << j)][j]);
				}
			}
		}
	}
	//[l,r)
	int query(int l, int r) {
		if (r - l == 0)return mod;
		int len = r - l;
		int x = 1;
		int cnt = 0;
		while (x * 2 <= len) {
			x *= 2;
			cnt++;
		}
		return min(nodel[l][cnt], noder[r-1][cnt]);
	}
};

string s;
string init_s;
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
		int cl, len;

		Chain(int s, int n) :cl(s), len(n) { ; }
		//Chain() { ; }
		//Chain(int n) :stree(n) { ; }
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
		chains.push_back(Chain(s.size(), seq.size()));
		rep(j, seq.size())s.push_back(init_s[seq[j]]);
		per(j, seq.size())s.push_back(init_s[seq[j]]);
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
	/*vector<pair<int, P>> all_edge(int u, int v) {
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
	}*/

	struct ste {
		bool isdown;
		int id, le, ri;
	};
	//from u to v
	//
	vector<ste> le, ri, sres;
	vector<ste> all_vertice_d(int u, int v) {

		le.clear(); ri.clear(); sres.clear();
		while (depth(u) < depth(v)) {
			ri.push_back({ true,mapto[v].first,0,mapto[v].second + 1 });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		while (depth(u) > depth(v)) {
			le.push_back({ false,mapto[u].first,0,mapto[u].second + 1 });
			P par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		while (mapto[v].first != mapto[u].first) {
			ri.push_back({ true,mapto[v].first,0,mapto[v].second + 1 });
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
			le.push_back({ false,mapto[u].first,0,mapto[u].second + 1 });
			par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		sres.resize(le.size() + 1 + ri.size());
		int cur = 0;
		for (ste s : le)sres[cur++] = s;
		if (mapto[u].second < mapto[v].second) {
			sres[cur++] = { true,mapto[v].first,mapto[u].second,mapto[v].second + 1 };
		}
		else {
			sres[cur++] = { false, mapto[v].first, mapto[v].second, mapto[u].second + 1 };
		}
		reverse(all(ri));
		for (ste s : ri)sres[cur++] = s;
		return sres;
	}

public:

	/*void edge_add(int u, int v, int a) {
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
			res += chains[id].stree.query(l, r);
		}
		return res;
	}*/

	/*void vertice_add(int u, int v, int a) {
		vector<pair<int, P>> vs = all_vertice(u, v);
		rep(i, vs.size()) {
			int id = vs[i].first;
			int l = vs[i].second.first; int r = vs[i].second.second;
			chains[id].stree.add(a, l, r);
		}
	}*/
	vector<P> vertice_seq_d(int u, int v) {
		vector<ste> vs = all_vertice_d(u,v);
		vector<P> res;
		for (ste s : vs) {
			if (!s.isdown) {
				int l = chains[s.id].cl+2 * chains[s.id].len - s.ri;
				int len = s.ri - s.le;
				res.push_back({ l,len });
			}
			else {
				int l = chains[s.id].cl + s.le;
				int len = s.ri - s.le;
				res.push_back({ l,len });
			}
		}
		//cout << "start " << u << " " << v << "\n";
		//for (P p : res)cout << p.first << " " << p.second << "\n";
		//cout << "end\n";
		return res;
	}
	int dist(int u, int v) {
		int res = 0;
		if (depth(u) > depth(v))swap(u, v);
		while (depth(u) < depth(v)) {
			res += mapto[v].second + 1;
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
		}
		while (mapto[v].first != mapto[u].first) {
			res += mapto[v].second + 1;
			P par = chains[mapto[v].first].parent;
			v = mapfrom[par.first][par.second];
			res += mapto[u].second + 1;
			par = chains[mapto[u].first].parent;
			u = mapfrom[par.first][par.second];
		}
		res += abs(mapto[u].second - mapto[v].second);
		return res;
	}

};


struct SuffixArray {
	struct SAComp {
		const int h;
		const vector<int>& g;
		SAComp(int h, vector<int>& g) : h(h), g(g) { ; }
		bool operator() (int a, int b) {
			return a != b && (g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h]);
		}
	};
	int n;
	string str;
	vector<int> sa, lcp;
	SuffixArray(const string& t) : n(t.size()), sa(n + 1), lcp(n + 1) {
		str = t;
		// build SA
		vector<int> g(n + 1, 0), b(n + 1, 0);
		rep(i, n + 1) { sa[i] = i; g[i] = str[i]; }
		sort(begin(sa), end(sa), SAComp(0, g));
		for (int h = 1; b[n] != n; h *= 2) {
			SAComp comp(h, g);
			sort(sa.begin(), sa.end(), comp);
			rep(i, n) b[i + 1] = b[i] + comp(sa[i], sa[i + 1]);
			rep(i, n + 1) g[sa[i]] = b[i];
		}
		// build LCP
		int h = 0;
		rep(i, n + 1) b[sa[i]] = i;
		rep(i, n + 1) {
			if (b[i]) {
				for (int j = sa[b[i] - 1]; j + h < n && i + h < n && str[j + h] == str[i + h]; ++h);
				lcp[b[i]] = h;
			}
			else {
				lcp[b[i]] = -1;
			}
			if (h > 0) --h;
		}
	}
	~SuffixArray() { str.clear(); }
	/*int find(string t) {
	int m = t.size();
	string p;
	p = t;
	int left = -1, right = n + 1;
	while (left + 1 < right) {
	int mid = (left + right) / 2;
	if (strncmp(str + sa[mid], p, m) < 0) left = mid;
	else right = mid;
	}
	return strncmp(str + sa[right], p, m) == 0 ? sa[right] : -1;
	}*/
};


void solve() {
	int n; cin >> n >> init_s;
	Graph g(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back({ b });
		g[b].push_back({ a });
	}
	HLDecomposition hld(g);
	//cout << s << "\n";
	SuffixArray sa(s); 
	sparse_table st(sa.lcp);
	//rep(i, sa.lcp.size())cout << sa.lcp[i] << " "; cout << "\n";
	
	vector<int> trans(s.size());
	rep1(i, s.size()) {
		trans[sa.sa[i]] = i;
	}
	auto lcpquery = [&](int s1, int s2)->int {
		//cout << s.size() << " " << s1 << " " << s2 << "\n";
		s1 = trans[s1]; s2 = trans[s2];
		if (s1 > s2)swap(s1, s2);
		//cout << s1 + 1 << " " << s2 + 1 << " " << st.query(s1 + 1, s2 + 1) << "\n";
		return st.query(s1 + 1, s2 + 1);
	};
	auto query = [&](int s1, int t1, int s2, int t2) {
		int res = 0;
		vector<P> vl = hld.vertice_seq_d(s1, t1);
		vector<P> vr = hld.vertice_seq_d(s2, t2);
		int idl = 0, idr = 0;
		int locl = 0, locr = 0;
		while (idl<vl.size()&&idr<vr.size()) {
			int cl = vl[idl].second - locl;
			int cr = vr[idr].second - locr;
			int sl = vl[idl].first + locl;
			int sr = vr[idr].first + locr;
			int clen = lcpquery(sl, sr);
			if (cl == cr) {
				if (clen < cl) {
					res += clen; break;
				}
				else {
					res += cl;
					idl++; idr++; locl = 0; locr = 0;
				}
			}
			else if (cl < cr) {
				if (clen < cl) {
					res += clen; break;
				}
				else {
					res += cl;
					idl++; locl = 0; locr += cl;
				}
			}
			else {
				if (clen < cr) {
					res += clen; break;
				}
				else {
					res += cr;
					idr++; locr = 0; locl += cr;
				}
			}
		}
		return res;
	};
	int q; cin >> q;
	rep(i, q) {
		int s1, t1, s2, t2; cin >> s1 >> t1 >> s2 >> t2; s1--; t1--; s2--; t2--;

		int ans = query(s1, t1, s2, t2);
		cout << ans << "\n";
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