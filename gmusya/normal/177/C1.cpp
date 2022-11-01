#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> used;
vector <vector <int>> g, comp;

void dfs(int v, int pos) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs(u, pos);
	comp[pos].push_back(v);
}

int main() {
	int n, m;
	cin >> n >> m;
	used.resize(n), g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int k;
	cin >> k;
	vector <vector <bool>> i_abhor_you(n, vector<bool>(n));
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		i_abhor_you[u][v] = i_abhor_you[v][u] = 1;
	}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			comp.push_back({});
			dfs(i, comp.size() - 1);
		}
	int ans = 0;
	for (int i = 0; i < comp.size(); i++) {
		bool tf = true;
		for (int j = 0; j < comp[i].size(); j++)
			for (int y = j + 1; y < comp[i].size(); y++)
				if (i_abhor_you[comp[i][j]][comp[i][y]])
					tf = false;
		ans = max(ans, (int) (tf * comp[i].size()));
	}
	cout << ans;
	return 0;
}