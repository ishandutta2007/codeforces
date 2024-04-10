#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;
const int M = 5e5+1;

namespace BCC {
	int vcompNum,ecompNum,I,m;
	int first[N],low[N],vis[N],ecomp[N];
	int nxt[2*M],ep[2*M],vcomp[2*M];
	stack<int> edges, verts;
	void init(int n) { m = 0; fill(first, first+n, -1); }
	void add_edge(int a, int b) {
		nxt[m] = first[ep[m] = a], first[ep[m]] = m, ++m;
		nxt[m] = first[ep[m] = b], first[ep[m]] = m; ++m; }
	void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I; verts.push(u);
		for (int e = first[u]; e != -1; e = nxt[e]) { v = ep[e^1];
			if (!vis[v]) { edges.push(e); biconnected(v,e); low[u] = min(low[u],low[v]);
				if (vis[u] <= low[v]) { // u is a cut vertex unless it's a one-child root
					do { E = edges.top(); edges.pop(); vcomp[E] = vcomp[E^1] = vcompNum; }
					while (e != E && e != (E^1)); ++vcompNum; }}
			else if (vis[v] < vis[u] && e != (par^1)) {
				low[u] = min(low[u], vis[v]); edges.push(e); }
			else if (v == u) vcomp[e] = vcomp[e^1] = vcompNum++; } // e is a self-loop
			if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
				do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
				while (v != u); ++ecompNum; }
	}
	void get_bcc(int n) { memset(vis,0,sizeof vis); vcompNum=ecompNum=I=0;
		for (int i=0; i<n; ++i) if (!vis[i]) biconnected(i, -1);
	}
	// tree-independent criteria for identifying articulation points and bridges
	bool isCutVertex(int u) { for (int e = first[u]; e != -1; e = nxt[e])
		if (vcomp[e] != vcomp[first[u]]) return true; return false; }
	bool isCutEdge(int e) { return ecomp[ep[e]] != ecomp[ep[e^1]]; }
}

vector<int> adj[N];
int dist[N];
int count(int n, int s, int t) {
	fill(dist, dist+n, -1);
	deque<int> bfs;
	bfs.push_front(s);
	dist[s] = 0;
	int res = 0;
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop_front();
		res += (dist[u] == 1);
		for(int v:adj[u]) {
			if(dist[v] != -1) continue;
			dist[v] = dist[u] + (v == t);
			if(dist[v] == 0) bfs.push_front(v);
			else bfs.push_back(v);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while(T--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		BCC::init(n+1);
		for(int i=1; i<=n; i++) {
			adj[i].clear();
		}
		for(int i=0; i<m; i++) {
			int a, b;
			cin >> a >> b;
			BCC::add_edge(a,b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		BCC::get_bcc(n+1);

		int st = count(n+1, s, t);
		int ts = count(n+1, t, s);
		if(!st || !ts || !BCC::isCutVertex(s) || !BCC::isCutVertex(t)) {
			cout << 0 << nl;
		} else {
			cout << (ll) (st-1) * (ts-1) << nl;
		}
	}

	return 0;
}