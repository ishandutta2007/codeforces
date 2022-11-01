#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector <int> cats;
vector <vector <int>> g;
vector <bool> used;

void dfs(int u, int hp) {
	used[u] = true;
	if (hp > m)
		return;
	if (u != 0 && g[u].size() == 1)
		cnt++;
	for (int i = 0; i < g[u].size(); i++) {
		if (used[g[u][i]])
			continue;
		dfs(g[u][i], hp * cats[g[u][i]] + cats[g[u][i]]);
	}
}

int main() {
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	cats.resize(n);
	for (int i = 0; i < n; i++)
		cin >> cats[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, cats[0]);
	cout << cnt;
	return 0;
}