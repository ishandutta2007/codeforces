//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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

const int N = 3e5 + 1;
vector<int> adj[N];
ll f[N], dp[N][2]; // disconnected, connected

ll solve(int, int);
ll connect(int, int, int);

// disconnected
ll solve(int u, int p) {
	if(f[u] != -1) return f[u];
	ll take = 1;
	ll cut = 1;
	ll skip = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		take = take * (solve(v, u) + connect(v, u, 0)) % MOD;
		cut = cut * solve(v, u) % MOD;
		skip = skip * (solve(v, u) + connect(v, u, 1)) % MOD;
	}
	return f[u] = (take - cut + skip) % MOD;
}

// connected
ll connect(int u, int p, int t) {
	if(dp[u][t] != -1) return dp[u][t];
	ll take = 1;
	ll skip = 1;
	for(int v : adj[u]) {
		if(v == p) continue;
		take = take * (solve(v, u) + connect(v, u, 0)) % MOD;
		skip = skip * (solve(v, u) + connect(v, u, 1)) % MOD;
	}
	return dp[u][t] = (skip + t * take) % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(f, -1, sizeof f);
	memset(dp, -1, sizeof dp);
	cout << (solve(1, 0) - 1 + MOD) % MOD << nl;

	return 0;
}