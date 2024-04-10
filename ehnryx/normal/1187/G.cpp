#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int T = 99;
const int C = 12;
namespace Flow {
	const int N = 50*T + 2;
	const int M = 2*N*C + N + 7;
	// data structures and helper functions common to all flow routines
	int par[N], first[N], nxt[2*M], ep[2*M], m;
	ll flo[2*M], cap[2*M], cost[2*M];
	void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
	void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
		nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m] =  p, ++m;
		nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m] = -p, ++m; }
	// Minimum cost maximum flow, assuming there are no negative cost cycles
	// USAGE: 1) init(); 2) add edges, 3) mcf_pot_init(numV) and 4)
	// ll price=0,flow=0; while (ll df = mcf_update(s, t, price, numV)) flow += df;
	//! for sparse graphs, may help to change Dijkstra from O(N^2) to O(M*lgN)
	bool vis[N]; ll pot[N], dist[N];
	void mcf_pot_init(int n) { memset(pot, 0, sizeof pot);
		// if all edge costs >= 0, we can safely return before the Bellman-Ford here
		for (int k = 1; k < n; ++k) for (int e = 0; e < m; ++e)
			if (cap[e]) pot[ep[e^1]] = min(pot[ep[e^1]], pot[ep[e]] + cost[e]); }
	ll mcf_update(int s, int t, ll& price, int n) {
		memset(vis, 0, sizeof vis); memset(dist, INF, sizeof dist); dist[s] = 0;
		priority_queue<pair<ll,int>> dk; dk.push({0,s});
		while(!dk.empty()) {
			int u = dk.top().second; dk.pop(); if(vis[u]) continue; vis[u] = true;
			for (int e = first[u]; e != -1; e = nxt[e]) { int v = ep[e^1];
				if (flo[e] < cap[e] && dist[v] > dist[u] + pot[u] - pot[v] + cost[e]) {
					dist[v] = dist[u] + pot[u] - pot[v] + cost[e]; par[v] = e;
					dk.push({-dist[v], v}); } } }
		if (dist[t] >= INF) return 0; ll df = INF;
		for (int e, i = t; i != s; i = ep[e])
			e = par[i], df = min(df, cap[e] - flo[e]);
		for (int e, i = t; i != s; i = ep[e])
			e = par[i], flo[e] += df, flo[e^1] -= df, price += df*cost[e];
		for (int i = 0; i < n; ++i) pot[i] = min(INF, dist[i] + pot[i]);
		return df; }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n,m,k,c,d;
	cin>>n>>m>>k>>c>>d;

	const int source = 0;
	const int sink = n*T+1;
	Flow::init();

	for(int i=0;i<k;i++) {
		int a;
		cin>>a;
		Flow::add_edge(source, a, 1, 0);
	}
	for(int t=0;t<T;t++) {
		Flow::add_edge(1+t*n, sink, INF, 0);
		if(t>0) {
			for(int i=1;i<=n;i++) {
				Flow::add_edge(i+(t-1)*n, i+t*n, INF, c);
			}
		}
	}

	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		for(int j=0;j<C;j++) {
			int cost = (j+1)*(j+1) - j*j;
			for(int t=1;t<T;t++) {
				Flow::add_edge(a+(t-1)*n, b+t*n, 1, cost*d + c);
				Flow::add_edge(b+(t-1)*n, a+t*n, 1, cost*d + c);
			}
		}
	}

	//Flow::mcf_pot_init(Flow::N);
	ll price = 0;
	ll flow = 0;
	while (ll df = Flow::mcf_update(source, sink, price, Flow::N)) flow += df;
	assert(flow==k);
	cout << price << nl;

	return 0;
}