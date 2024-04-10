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

struct Edge {
	int v;
	vector<ll> c;
	Edge(int i, ll a, ll b): v(i) {
		c = { b, a };
	}
};

struct Node {
	int v; ll d;
	bool operator < (const Node& o) const {
		return d > o.d;
	}
};

const int N = 3e5+1;
const int L = 20;
vector<Edge> adj[N];
vector<Node> graph[N];
ll cross[N];

int cpar[N], cdepth[N], sz[N];
bool vis[N];

ll dist[2][L][2*N];

void dijkstra(int s, int layer) {
	//cerr<<"run dijkstra from "<<s<<nl;
	auto& d = dist[s%2][layer];
	assert(d[s] == -1);
	priority_queue<Node> dijk;
	dijk.push({s,0});
	while(!dijk.empty()) {
		auto [u,cd] = dijk.top();
		dijk.pop();
		if(d[u] != -1) continue;
		d[u] = cd;
		//cerr<<"set "<<s<<" -> "<<u<<" = "<<cd<<nl;
		int id = (u+1)/2;
		int op = 2*id - (u+1)%2;
		if(d[op] == -1) {
			dijk.push({op, cd + cross[id]});
		}
		for(const auto& [j,ed]:adj[id]) {
			int v = 2*j - u%2;
			if(vis[j] || d[v] != -1) continue;
			dijk.push({v, cd + ed[u%2]});
		}
	}
}

int dfs(int u, int p, vector<int>& seen) {
	seen.push_back(u);
	sz[u] = 1;
	for(const auto& [v,_]:adj[u]) {
		if(v == p || vis[v]) continue;
		sz[u] += dfs(v, u, seen);
	}
	return sz[u];
}

int centroid(int u, int layer) {
	vector<int> seen;
	int s = dfs(u, 0, seen);
	for(int v:seen) {
		bool ok = true;
		for(const auto& [w,_]:adj[v]) {
			if(vis[w]) continue;
			if(2*sz[v]<s || (sz[v]>sz[w] && 2*sz[w]>s)) {
				ok = false;
				break;
			}
		}
		if(ok) {
			dijkstra(2*v, layer);
			dijkstra(2*v-1, layer);
			return v;
		}
	}
	assert(false);
}

int decompose(int u, int layer) {
	int c = centroid(u, layer);
	cdepth[c] = layer;
	vis[c] = true;
	for(const auto& [v,_]:adj[c]) {
		if(vis[v]) continue;
		int nc = decompose(v, layer+1);
		cpar[nc] = c;
	}
	return c;
}

ll query(int a, int b) {
	int u = (a+1)/2;
	int v = (b+1)/2;
	if(cdepth[u] < cdepth[v]) swap(u,v);
	while(cdepth[u] > cdepth[v]) {
		u = cpar[u];
	}
	while(u != v) {
		u = cpar[u];
		v = cpar[v];
	}
	assert(u == v && u > 0);
	//cerr<<a<<" "<<b<<" -> "<<u<<" w/ depth "<<cdepth[u]<<nl;
	int layer = cdepth[u];
	ll ab0 = dist[0][layer][a] + dist[0][layer][b];
	ll ab1 = dist[1][layer][a] + dist[1][layer][b];
	return min(ab0, ab1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> cross[i];
		graph[0].push_back({i, cross[i]});
	}
	for(int i=1; i<n; i++) {
		int a, b;
		ll c, d;
		cin >> a >> b >> c >> d;
		adj[a].push_back(Edge(b,c,d));
		adj[b].push_back(Edge(a,c,d));
		graph[a].push_back({b, c+d});
		graph[b].push_back({a, c+d});
	}

	memset(cross, -1, sizeof cross);
	priority_queue<Node> dijk;
	dijk.push({0,0});
	while(!dijk.empty()) {
		auto [u,d] = dijk.top();
		dijk.pop();
		if(cross[u] != -1) continue;
		cross[u] = d;
		for(const auto& [v,ed]:graph[u]) {
			if(cross[v] != -1) continue;
			dijk.push({v, d+ed});
		}
	}

	memset(dist, -1, sizeof dist);
	decompose(1, 0);

	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		cout << query(a,b) << nl;
	}

	return 0;
}