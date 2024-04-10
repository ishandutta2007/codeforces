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
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Edge {
	int v, id;
	bool operator < (const Edge& o) const {
		return id < o.id;
	}
};

const int N = 2e5+1;
vector<Edge> adj[N];
int order[N], maxc[N], minc[N], par[N];

void dfs(int u, int p) {
	par[u] = p;
	for(const Edge& e:adj[u]) {
		if(e.v == p) continue;
		order[e.v] = e.id;
		maxc[u] = max(maxc[u], e.id);
		minc[u] = min(minc[u], e.id);
		dfs(e.v, u);
	}
	if(minc[u] == 0) minc[u] = INF;
}

ll dp[5][N];

ll solve_left(int);
ll solve_par(int);
ll solve_child(int);
ll solve_child_before(int);
ll solve_child_after(int);

ll solve_left(int u) {
	if(dp[0][u] != -1) return dp[0][u];

	ll res = 1;
	for(const Edge& e : adj[u]) {
		if(e.v == par[u]) continue;
		res = res * (solve_child_before(e.v) + solve_par(e.v)) % MOD;
	}
	//cerr<<"solve_left "<<u<<" -> "<<res<<nl;
	return dp[0][u] = res;
}

ll solve_par(int u) {
	if(dp[1][u] != -1) return dp[1][u];

	ll res = 1;
	for(const Edge& e:adj[u]) {
		if(e.v == par[u]) continue;
		if(e.id < order[u]) {
			res = res * (solve_child_before(e.v) + solve_par(e.v)) % MOD;
		} else {
			res = res * (solve_child(e.v) + solve_left(e.v)) % MOD;
		}
	}
	//cerr<<"solve_par "<<u<<" -> "<<res<<nl;
	return dp[1][u] = res;
}

ll solve_child(int u) {
	if(dp[2][u] != -1) return dp[2][u];

	ll left = 1;
	ll taken = 0;
	for(const Edge& e:adj[u]) {
		if(e.v == par[u]) continue;
		ll nleft = left * (solve_par(e.v) + solve_child_before(e.v)) % MOD;
		ll ntaken = taken * (solve_left(e.v) + solve_child(e.v)) % MOD;
		ntaken = (ntaken + left * (solve_left(e.v) + solve_child_after(e.v))) % MOD;
		left = nleft;
		taken = ntaken;
	}
	return dp[2][u] = taken;
}

ll solve_child_before(int u) {
	if(dp[3][u] != -1) return dp[3][u];

	ll left = 1;
	ll taken = 0;
	for(const Edge& e:adj[u]) {
		if(e.v == par[u]) continue;
		if(e.id < order[u]) {
			ll nleft = left * (solve_par(e.v) + solve_child_before(e.v)) % MOD;
			ll ntaken = taken * (solve_left(e.v) + solve_child(e.v)) % MOD;
			ntaken = (ntaken + left * (solve_left(e.v) + solve_child_after(e.v))) % MOD;
			left = nleft;
			taken = ntaken;
		} else {
			taken = taken * (solve_left(e.v) + solve_child(e.v)) % MOD;
		}
	}
	return dp[3][u] = taken;
}

ll solve_child_after(int u) {
	if(dp[4][u] != -1) return dp[4][u];

	ll left = 1;
	ll taken = 0;
	for(const Edge& e:adj[u]) {
		if(e.v == par[u]) continue;
		if(e.id > order[u]) {
			ll nleft = left * (solve_par(e.v) + solve_child_before(e.v)) % MOD;
			ll ntaken = taken * (solve_left(e.v) + solve_child(e.v)) % MOD;
			ntaken = (ntaken + left * (solve_left(e.v) + solve_child_after(e.v))) % MOD;
			left = nleft;
			taken = ntaken;
		} else {
			left = left * (solve_par(e.v) + solve_child_before(e.v)) % MOD;
		}
	}
	return dp[4][u] = taken;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
	}
	for(int i=1; i<=n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	dfs(1, 0);
	memset(dp, -1, sizeof dp);
	ll ans = solve_left(1) + solve_child(1);
	cout << (ans % MOD + MOD) % MOD << nl;

	return 0;
}