#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
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
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 1;
vector<int> adj[N];
int col[N], ans[N], dp[N];

int calc(int u, int p) {
	int res = (col[u] ? 1 : -1);
	for(int v : adj[u]) {
		if(v == p) continue;
		res += max(0, calc(v, u));
	}
	return dp[u] = res;
}

void solve(int u, int p, int val) {
	int cur = dp[u];
	ans[u] = cur + val;
	for(int v : adj[u]) {
		if(v == p) continue;
		int push = cur - max(0, dp[v]) + val;
		solve(v, u, max(0, push));
	}
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> col[i];
	}
	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	calc(1, 0);
	solve(1, 0, 0);

	for(int i=1; i<=n; i++) {
		cout << ans[i] << " ";
	}
	cout << nl;

	return 0;
}