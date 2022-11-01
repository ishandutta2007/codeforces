#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt_v = 0, cnt_comp = 0;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	cnt_v++;
	for (auto to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			dfs(i);
			cnt_comp++;
		}
	cout << m + cnt_comp - cnt_v;
	return 0;
}