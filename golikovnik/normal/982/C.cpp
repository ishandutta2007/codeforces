#include <bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> graph;
vector<int> used;

//size, ans
pair<int, int> dfs(int u, int p = -1) {
	used[u] = 1;
	int ans = 0;
	int size = 1;
	for (int v: graph[u]) {
		if (v == p) continue;
		if (!used[v]) {
			auto res = dfs(v, u);
			if (res.first % 2 == 0) {
				ans += res.second + 1;
				continue;
			}
			ans += res.second;
			size += res.first;
		}
	}
	return make_pair(size, ans);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	graph.resize(n);
	used.resize(n);
	for (int i = 0; i + 1 < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	auto ans = dfs(0);
	cout << (ans.first % 2 == 0 ? ans.second : -1) << "\n";
	return 0;	
}