#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N;
vector<int> adj[MAXN];
int sz[MAXN];
LL total, ans;

void dfs(int n, int p) {
	sz[n] = 1;
	for (int v : adj[n]) if (v != p) {
		dfs(v, n);
		sz[n] += sz[v];
	}
	total += sz[n];
}

void solve(int n, int p) {
	ans = max(ans, total);
	for (int v : adj[n]) if (v != p) {
		total += N - 2 * sz[v];
		solve(v, n);
		total -= N - 2 * sz[v];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0, 0);
	solve(0, 0);

	cout << ans << endl;
	return 0;
}