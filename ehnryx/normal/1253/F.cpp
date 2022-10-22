#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
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
	int i; ll d;
	bool operator < (const Edge& o) const {
		return d > o.d;
	}
};

struct MSTE {
	int a, b; ll c;
	bool operator < (const MSTE& o) const {
		return c < o.c;
	}
};

const int N = 1e5+1;
ll dist[N];
vector<Edge> graph[N];
vector<Edge> adj[N];

int dsu[N];
int find(int i) {
	if(dsu[i]==0) return i;
	return dsu[i] = find(dsu[i]);
}
int link(int i, int j) {
	if(find(i)==find(j)) return 0;
	dsu[find(i)] = find(j);
	return 1;
}

const int L = 17;
int depth[N];
int anc[N][L];
ll maxv[N][L];

void build(int u, int p, ll c) {
	depth[u] = depth[p]+1;
	anc[u][0] = p;
	maxv[u][0] = c;
	for(int i=1;i<L;i++) {
		anc[u][i] = anc[anc[u][i-1]][i-1];
		maxv[u][i] = max(maxv[u][i-1], maxv[anc[u][i-1]][i-1]);
	}
	for(const Edge& e:adj[u]) {
		if(e.i == p) continue;
		build(e.i, u, e.d);
	}
}

ll query(int a, int b) {
	ll res = 0;
	if(depth[a] < depth[b]) swap(a,b);
	for(int j=L-1;j>=0;j--) {
		if(depth[a] - (1<<j) >= depth[b]) {
			res = max(res, maxv[a][j]);
			a = anc[a][j];
		}
	}
	if(a == b) return res;
	for(int j=L-1;j>=0;j--) {
		if(anc[a][j] == anc[b][j]) continue;
		res = max(res, maxv[a][j]);
		res = max(res, maxv[b][j]);
		a = anc[a][j];
		b = anc[b][j];
	}
	res = max(res, maxv[a][0]);
	res = max(res, maxv[b][0]);
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<MSTE> edges;
	for(int i=0;i<m;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
		edges.push_back({a,b,c});
	}

	priority_queue<Edge> dijk;
	for(int i=1;i<=k;i++) {
		dijk.push({i,0});
	}
	for(int i=k+1;i<=n;i++) {
		dist[i] = INFLL;
	}
	while(!dijk.empty()) {
		Edge cur = dijk.top();
		dijk.pop();
		if(cur.d > dist[cur.i]) continue;
		for(const Edge& e:graph[cur.i]) {
			if(e.d + cur.d < dist[e.i]) {
				dist[e.i] = e.d + cur.d;
				dijk.push({e.i, dist[e.i]});
			}
		}
	}

	for(MSTE& e : edges) {
		e.c += dist[e.a] + dist[e.b];
	}
	sort(edges.begin(), edges.end());

	for(const MSTE& e : edges) {
		if(link(e.a, e.b)) {
			adj[e.a].push_back({e.b,e.c});
			adj[e.b].push_back({e.a,e.c});
		}
	}

	build(1,0,0);

	for(int i=0;i<q;i++) {
		int a,b;
		cin>>a>>b;
		cout<<query(a,b)<<nl;
	}

	return 0;
}