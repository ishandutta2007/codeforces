#include <iostream>
#include <vector>

using namespace std;

bool tf;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	if (g[u].size() != 2)
		tf = false;
	used[u] = true;
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	int n, m;
	cin >> n >> m;
	used.resize(n);
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			tf = true;
			dfs(i);
			if (tf)
				cnt++;
		}
	cout << cnt;
	return 0;
}