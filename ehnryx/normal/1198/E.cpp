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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

namespace Dinic {
	const int N = 200+2;
	const int M = N*N*50;
	int par[N], first[N], nxt[2*M], ep[2*M], m;
	ll flo[2*M], cap[2*M], cost[2*M];
	void init() { m = 0; memset(first,-1,sizeof first); memset(flo,0,sizeof flo); }
	void add_edge(int a, int b, ll c=1, ll p=0) { //a,b - nodes, c, p - cap, price
		nxt[m] = first[ep[m]=a], first[ep[m]] = m, cap[m] = c, cost[m] =  p, ++m;
		nxt[m] = first[ep[m]=b], first[ep[m]] = m, cap[m] = 0, cost[m] = -p, ++m; }
	// Dinic's fast maximum flow: tested on NAIPC 2015 F but not theoretically
	// proven to be floating-point-safe.
	// USAGE: 1) init(); 2) add edges
	// 3) ll flow=0; while (bfs(S, T)) flow += dfs(S, T, INF);
	// V^2E in general, min(V^(2/3),sqrt(E))E on unit caps, sqrt(V)E on bipartite
	int L[N], cur[N];
	bool bfs(int s, int t) {
		memset(L, INF, sizeof L);
		queue<int> q; q.push(s); L[s] = 0;
		while (!q.empty()) { int u = q.front(); q.pop();
			for (int v, e = cur[u] = first[u]; e != -1; e = nxt[e])
				if (L[v=ep[e^1]] == INF && flo[e] < cap[e])
					q.push(v), L[v] = L[u]+1;
		} return L[t] < INF; }
	ll dfs(int u, int t, ll f) {
		if (u == t) return f;
		ll cf, df = 0;
		for (int v, e = cur[u]; e != -1 && df < f; cur[u] = e = nxt[e])
			if (flo[e] < cap[e] && L[v=ep[e^1]] == L[u]+1) {
				cf = dfs(v, t, min(cap[e]-flo[e], f-df));
				flo[e] += cf; flo[e^1] -= cf; df += cf;
			} return df; }
}

struct Rectangle {
	int a, b, x, y;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	int source = 2*2*m;
	int sink = source+1;

	vector<Rectangle> rect;
	set<int> h, v;
	For(i,m) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		h.insert(a-1); h.insert(x);
		v.insert(b-1); v.insert(y);
		rect.push_back({a,b,x,y});
	}

	Dinic::init();
	{
		int p = -1;
		int i = 0;
		for (int x : h) {
			if (p != -1) {
				Dinic::add_edge(source, i, x-p);
			}
			p = x;
			i++;
		}
	}
	{
		int p = -1;
		int i = 0;
		for (int x : v) {
			if (p != -1) {
				Dinic::add_edge(i+2*m, sink, x-p);
			}
			p = x;
			i++;
		}
	}

	for (const Rectangle& r : rect) {
		int ix = 0;
		for (int x : h) {
			int iy = 0;
			for (int y : v) {
				if (r.a<=x && x<=r.x && r.b<=y && y<=r.y) {
					Dinic::add_edge(ix, iy+2*m, INF);
				}
				iy++;
			}
			ix++;
		}
	}

	int ans = 0;
	while (Dinic::bfs(source, sink)) {
		ans += Dinic::dfs(source, sink, INF);
	}
	cout << ans << nl;

	return 0;
}