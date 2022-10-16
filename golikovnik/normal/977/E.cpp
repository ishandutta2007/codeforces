#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> deg, used;
vector<vector<int>> graph;
bool ok;

void dfs(int u) {
	used[u] = 1;
	ok &= (deg[u] == 2);
	for (int v: graph[u]) {
		if (!used[v]) dfs(v);
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n, m;
	cin >> n >> m;	
	used.resize(n);
	deg.resize(n);
	graph.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		++deg[u], ++deg[v];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ok = 1;
			dfs(i);
			ans += ok;
		}
	}
	cout << ans << "\n";
	return 0;
}