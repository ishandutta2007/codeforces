#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

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
	int pre, id;
	ll dist;
	Edge(int p, int i, ll d): pre(p), id(i), dist(d) {}
};

const int N = 1e5+1;
vector<Edge> adj[N];

////////////////////////////////////////////////////////////////////////
// Disjoint Set Union -- O(a(n)) per query, (inverse ackermann)
// Usage: 
// 1. dsu(n) to create n disjoint sets from 0 to n-1
// 2. dsu.link(i,j) to combine sets containing i and j
// 3. dsu.find(i) to find the root of the set containing i
//*!
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
//*/

////////////////////////////////////////////////////////////////////////
// Range Minimum Query -- O(nlogn) to build, O(1) to query
// Maximum query is also possible
// The code is 0-indexed, change the loops in build to make it 1-indexed
// Query range is inclusive
// USAGE:
//  1. RMQ rmq(n);
//  2. rmq.build(vector containing the values);
//  3. rmq.query(l,r);  // range inclusive [l,r]
//*!
template <class T> struct RMQ {
    int lg;
    vector<vector<T>> rmq;
    RMQ(int n) {
        lg = 32 - __builtin_clz(n);
        rmq.resize(n, vector<T>(lg));
    }
    void set(int i, const T& v) {
        rmq[i][0] = v;
    }
    void build() {
        for (int j = 1; j < lg; j++)
            for (int i = 0; i+(1<<j)-1 < rmq.size(); i++)
                rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
    T query(int l, int r) {
        if (l > r) swap(l, r);
        int j = 31 - __builtin_clz(r-l+1);
        return min(rmq[l][j], rmq[r-(1<<j)+1][j]);
    }
};
//*/

////////////////////////////////////////////////////////////////////////
// Lowest Common Ancestor -- Using RMQ
// Nodes are 1-indexed
// USAGE:
//  1. LCA lca(numNodes);
//  2. lca.build(root);
//  3. lca.query(u,v);
//*!
struct LCA : RMQ<pii> {
    vector<int> depth, segpos;
	vector<ll> len;
    int lcanum = 0;
    LCA(int n): RMQ<pii>(2*n) {
        lcanum = 0;
        depth.resize(n);
        segpos.resize(n);
		len.resize(n);
		len[0] = depth[0] = 0;
    }
    void build(int root) {
        build(root, 0, 0);
        RMQ::build();
    }
    void build(int cur, int par, ll dist) {
        depth[cur] = depth[par] + 1;
		len[cur] = len[par] + dist;
        segpos[cur] = lcanum;
        RMQ::rmq[lcanum++][0] = pii(depth[cur], cur);
        for (Edge& x : adj[cur]) {
            if (x.id != par) {
                build(x.id, cur, x.dist);
                RMQ::rmq[lcanum++][0] = pii(depth[cur], cur);
            }
        }
    }
    ll query(int a, int b) {
        int c = RMQ::query(segpos[a],segpos[b]).second;
		return len[a]+len[b]-2*len[c];
    }
};
//*/

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m, a, b, c;
	cin >> n >> m;

	vector<Edge> edges;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		edges.push_back(Edge(a,b,c));
	}

	DSU dsu(n+1);
	unordered_set<int> seen;
	vector<Edge> cross;
	for (const Edge& e : edges) {
		if (dsu.link(e.pre, e.id)) {
			adj[e.pre].push_back(Edge(e.pre, e.id, e.dist));
			adj[e.id].push_back(Edge(e.id, e.pre, e.dist));
		} else {
			cross.push_back(e);
			seen.insert(e.pre);
			seen.insert(e.id);
		}
	}

	LCA lca(n+1);
	lca.build(1);

	vector<int> node;
	unordered_map<int,int> nid;
	for (int i : seen) {
		nid[i] = node.size();
		node.push_back(i);
	}
	m = node.size();

	ll trivial[m][m];
	memset(trivial, INF, sizeof trivial);
	for (const Edge& e : cross) {
		trivial[nid[e.pre]][nid[e.id]] = trivial[nid[e.id]][nid[e.pre]] = e.dist;
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			trivial[i][j] = min(trivial[i][j], lca.query(node[i],node[j]));
		}
	}
	for (int k=0; k<m; k++) {
		for (int i=0; i<m; i++) {
			for (int j=0; j<m; j++) {
				trivial[i][j] = min(trivial[i][j], trivial[i][k]+trivial[k][j]);
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		cin >> a >> b;
		ll ans = lca.query(a, b);
		for (int i=0; i<m; i++) {
			for (int j=0; j<m; j++) {
				ans = min(ans, lca.query(a,node[i])+lca.query(b,node[j])+trivial[i][j]);
			}
		}
		cout << ans << nl;
	}

	return 0;
}