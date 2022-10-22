#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#pragma GCC Optimize("O3")

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Edge {
	int a, b, c;
	Edge(){}
	Edge(int a, int b, int c): a(a), b(b), c(c) {}
	bool operator < (const Edge& v) const {
		return c < v.c;
	}
};

const int N = 1<<19;
const int L = 20;
vector<int> adj[N];

struct DSU {
	vector<int> root;
	vector<int> sz;

	DSU(int n) {
		root.resize(n, -1);
		sz.resize(n, 1);
	}

	int find(int i) {
		if (root[i] == -1) return i;
		return root[i] = find(root[i]);
	}

	// returns true if we combine two sets
	bool link(int i, int j) {
		i = find(i);
		j = find(j);
		if (i == j) return false;
		if (sz[i] < sz[j]) swap(i,j);
		root[j] = i;
		sz[i] += sz[j];
		return true;
	}
};
DSU dsu(5e5+1);

struct SegTree {
	int n; int *segt;

	SegTree(int len) {
		n = 1<<(32-__builtin_clz(len));
		segt = new int [2*n]; fill(segt, segt+2*n, INF);
	}

	void update(int l, int r, int v) {
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) {
				assert(0<=l && l<2*n);
				segt[l] = min(segt[l], v);
				l++;
			}
			if (r&1) {
				--r;
				assert(0<=r && r<2*n);
				segt[r] = min(segt[r], v);
			}
		}
	}

	int query(int x) {
		int res = INF;
		for (x += n; x > 0; x /= 2) {
			res = min(res, segt[x]);
		}
		return res;
	}
};

namespace HLD {
  SegTree* segt[N];
  int d[N], par[N], sub[N], sz[N], root[N], ch[N], pos[N]; int dn, cn;
  int dfs(int u, int p) { d[u] = d[par[u]=p]+1; sub[u] = 1;
    for (int x:adj[u]) if (x!=p) sub[u] += dfs(x,u); return sub[u]; }
  void hld(int u, int p) { if (dn == cn) { root[cn]=u; sz[cn++]=0; }
    pos[u] = sz[ch[u]=dn]++; int b=-1, c=-1;
    for (int x:adj[u]) if (x!=p && sub[x]>b) b=sub[c=x]; if (c!=-1) hld(c,u);
    for (int y:adj[u]) if (y!=p && y!=c) { dn++; hld(y,u); } }
  void build(int r) { d[0] = dn = cn = 0; dfs(r,0); hld(r,0);
    for (int i=0; i<cn; i++) segt[i] = new SegTree(sz[i]); }
  // Returns LCA of path ab, MODIFY for insert_node, query_path, query_node
  int insert_path(int a, int b, int v) { // please expand this when typing
    while (ch[a] != ch[b]) { if (d[root[ch[a]]] < d[root[ch[b]]]) swap(a,b);
      segt[ch[a]]->update(0, pos[a], v); a = par[root[ch[a]]]; }
    if (pos[a] != pos[b]) { if (d[a] < d[b]) swap(a,b);
      segt[ch[a]]->update(pos[b]+1, pos[a], v); } return b; } // returns lca
	int query_node(int a) { return segt[ch[a]]->query(pos[a]); }
}

namespace std {
	template<> struct hash<pii> {
		size_t operator () (const pii& v) const {
			return hash<int>()(v.first) ^ hash<int>()(v.second<<11);
		}
	};
}
unordered_set<pii> orig;

ll answer(int cur) {
	ll res = 0;
	if (orig.count(pii(cur, HLD::par[cur]))) {
		int v = HLD::query_node(cur);
		if (v == INF) return -1;
		res += v;
	}

	for (int x : adj[cur]) {
		if (x != HLD::par[cur]) {
			ll v = answer(x);
			if (v == -1) return -1;
			res += v;
		}
	}
	return res;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, k, m, a, b, c;
	cin >> n >> k >> m;

	int root = -1;
	int groups = n;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		root = a;
		adj[a].push_back(b);
		adj[b].push_back(a);
		orig.insert(pii(a,b));
		orig.insert(pii(b,a));
		groups -= dsu.link(a,b);
	}

	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge(a,b,c));
	}
	sort(edges.begin(), edges.end());

	for (const Edge& e : edges) {
		if (groups == 1) break;
		if (dsu.link(e.a, e.b)) {
			adj[e.a].push_back(e.b);
			adj[e.b].push_back(e.a);
			groups--;
		}
	}
	HLD::build(root);

	for (const Edge& e : edges) {
		HLD::insert_path(e.a, e.b, e.c);
	}

	cout << answer(root) << nl;

	return 0;
}