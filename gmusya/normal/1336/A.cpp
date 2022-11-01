#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> used;
vector <int> d, sz;
vector <vector <int>> g;

void dfs(int v) {
	used[v] = true;
	sz[v] = 1;
	for (int u : g[v]) {
		if (!used[u]) {
			d[u] = d[v] + 1;
			dfs(u);
			sz[v] += sz[u];
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	used.resize(n), sz.resize(n), d.resize(n), g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	vector <int> ans(n);
	for (int i = 0; i < n; i++)
		ans[i] = d[i] - sz[i];
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	long long answer = 0;
	for (int i = 0; i < k; i++) 
		answer += ans[i];
	cout << answer + k;
	return 0;
}