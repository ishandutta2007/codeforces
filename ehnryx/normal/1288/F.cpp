//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace Flow {
	const int N = 500;

	struct Edge { int v, r; ll f, c, p; };
	vector<Edge> adj[N]; int sz[N];
	vector<Edge> mcf_edges; // for mcf on large graphs with negative costs
	vector<pair<int,int>> rem_edges;
	void init(int n=N) {
		fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
	void add_edge(int a, int b, ll c=1, ll p=0, bool rem=false) {
		if(rem) rem_edges.emplace_back(a, sz[a]);
		mcf_edges.push_back({b,a,0,c,p});
		adj[a].push_back({b,sz[b]++,0,c,p});
		adj[b].push_back({a,sz[a]++,0,0,-p});
	}

	bool vis[N]; int par[N]; ll pot[N], dist[N];
	void pot_init(int n) { fill(pot, pot+n, 0);
		// if all edge costs >= 0, we don't need to run the Bellman-Ford here
		for(int i=1; i<n; i++) for(const Edge& e:mcf_edges)
			if(e.c) pot[e.v] = min(pot[e.v], pot[e.r] + e.p); }
	ll mcf(int s, int t, ll& price, int n, bool sparse) {
		fill(vis, vis+n, 0); fill(dist, dist+n, INF); dist[s] = 0;
		// only need one of the branches below
		if(sparse) {  // replace priority_queue with queue for SPFA
			priority_queue<pair<ll,int>> dk; dk.push({0,s}); while(!dk.empty()){
				int u = dk.top().second; dk.pop(); if(vis[u]) continue;
				for(const Edge& e:adj[u]) { // BUBL;BUBL;BUBL;BUBL;BUBL;BUBL;BUBL;
					if (e.f < e.c && dist[e.v] > dist[u] + pot[u] - pot[e.v] + e.p){
						dist[e.v] = dist[u] + pot[u] - pot[e.v] + e.p; par[e.v] = e.r;
						dk.push({-dist[e.v], e.v}); } } }
		} else {  // dense
			for(int u = s; u != -1; ) { vis[u] = 1; for(const Edge& e: adj[u]) {
				if (e.f < e.c && dist[e.v] > dist[u] + pot[u] - pot[e.v] + e.p) {
					dist[e.v]=dist[u] + pot[u] - pot[e.v] + e.p; par[e.v] = e.r; } }
			u = -1; ll best = INF;
			for(int i=0; i<n; i++) if(!vis[i] && dist[i]<best) best=dist[u=i]; }
		}  // end branches
		if (dist[t] >= INF) { return 0; } ll df = INF;
		for(int u = t; u != s; ) { const Edge& r = adj[u][par[u]];
			df = min(df, adj[r.v][r.r].c - adj[r.v][r.r].f); u = r.v; }
		for(int u = t; u != s; ) { Edge& r=adj[u][par[u]], &e=adj[r.v][r.r];
			e.f += df; r.f -= df; price += df*e.p; u = r.v; }
		for(int i=0;i<n;i++) { pot[i]=min(INF, dist[i]+pot[i]); } return df; }
	ll min_cost_flow(int s, int t, ll& price, int n=N, bool sparse=false) {
		pot_init(n); ll flow = price = 0;
		while(ll df=mcf(s,t,price,n,sparse)) { flow += df; } return flow; }
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n1, n2, m, red, blue;
	cin >> n1 >> n2 >> m >> red >> blue;

	string left, right;
	cin >> left >> right;

	const int oldS = 0;
	const int oldT = n1+n2 + 1;
	const int S = oldT + 1;
	const int T = S + 1;
	Flow::add_edge(oldT, oldS, INF, 0);

	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		Flow::add_edge(a, b+n1, 1, red, true);
		Flow::add_edge(b+n1, a, 1, blue, true);
	}

	int goal = 0;

	for(int i=1; i<=n1; i++) {
		if(left[i-1] == 'R') {
			Flow::add_edge(oldS, i, INF, 0);
			Flow::add_edge(S, i, 1, 0);
			Flow::add_edge(oldS, T, 1, 0);
			goal++;
		} else if(left[i-1] == 'B') {
			Flow::add_edge(i, oldT, INF, 0);
			Flow::add_edge(S, oldT, 1, 0);
			Flow::add_edge(i, T, 1, 0);
			goal++;
		} else {
			Flow::add_edge(oldS, i, INF, 0);
			Flow::add_edge(i, oldT, INF, 0);
		}
	}

	for(int i=1; i<=n2; i++) {
		if(right[i-1] == 'R') {
			Flow::add_edge(i+n1, oldT, INF, 0);
			Flow::add_edge(S, oldT, 1, 0);
			Flow::add_edge(i+n1, T, 1, 0);
			goal++;
		} else if(right[i-1] == 'B') {
			Flow::add_edge(oldS, i+n1, INF, 0);
			Flow::add_edge(S, i+n1, 1, 0);
			Flow::add_edge(oldS, T, 1, 0);
			goal++;
		} else {
			Flow::add_edge(oldS, i+n1, INF, 0);
			Flow::add_edge(i+n1, oldT, INF, 0);
		}
	}

	ll cost = 0;
	ll flow = Flow::min_cost_flow(S, T, cost, T+1, true);
	if(flow < goal) {
		cout << -1 << nl;
		return 0;
	}

	cout << cost << nl;
	for(int i=0; i<m; i++) {
		auto [rv, ri] = Flow::rem_edges[2*i];
		auto [bv, bi] = Flow::rem_edges[2*i+1];
		if(Flow::adj[rv][ri].f > 0) cout << 'R';
		else if(Flow::adj[bv][bi].f > 0) cout << 'B';
		else cout << 'U';
	}
	cout << nl;

	return 0;
}