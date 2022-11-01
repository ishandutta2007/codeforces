#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs1(int v, int p, vector <int> &dp, vector <int> &color, vector <vector <int>> &g) {
	dp[v] = color[v];
	for (int u : g[v]) {
		if (u == p) continue;
		dfs1(u, v, dp, color, g);
		dp[v] += max(dp[u], 0);
	}
}

void dfs2(int v, int p, vector <int> &dp, vector <int> &color, vector <int> &ans, vector <vector <int>> &g) {
	ans[v] = dp[v];
	for (int u : g[v]) {
		if (u == p) continue;
		dp[v] -= max(0, dp[u]);
		dp[u] += max(0, dp[v]);
		dfs2(u, v, dp, color, ans, g);
		dp[u] -= max(0, dp[v]);
		dp[v] += max(0, dp[u]);
	}
}

int main() {
	int n;
	cin >> n;
	vector <int> color(n);
	for (int i = 0; i < n; i++) {
		cin >> color[i];
		if (color[i] == 0) color[i] = -1;
	}
	vector <vector <int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	vector <int> dp(n), ans(n);
	dfs1(0, -1, dp, color, g);
	dfs2(0, -1, dp, color, ans, g);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}