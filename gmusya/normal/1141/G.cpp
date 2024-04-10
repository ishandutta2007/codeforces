#include <iostream>
#include <vector>

using namespace std;

int ans;
vector <int> deg;
vector <int> color;
vector <vector <pair <int, int>>> g;

void dfs(int v, int p = -1, int ep = -1) {
	if (deg[v] <= ans) {
		int colorp = (p == -1 ? 0 : color[ep]);
		int col = 1;
		for (auto &now : g[v]) {
			if (col == colorp) col++;
			int u = now.first;
			int id = now.second;
			if (u == p) continue;
			color[id] = col;
			col++;
			dfs(u, v, id);
		}
		return;
	}
	int colorp = (p == -1 ? 1 : color[ep]);
	for (auto &now : g[v]) {
		int u = now.first;
		if (u == p) continue;
		int id = now.second;
		color[id] = colorp;
		dfs(u, v, id);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	deg.resize(n), color.resize(n - 1), g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back({ v, i - 1 });
		g[v].push_back({ u, i - 1 });
	}
	ans = n;
	vector <int> cnt(n);
	for (int i = 0; i < n; i++) {
		cnt[g[i].size()]++;
		deg[i] = g[i].size();
	}
	for (int i = 1; i < n; i++) {
		cnt[i] += cnt[i - 1];
		if (k >= n - cnt[i]) {
			ans = i;
			break;
		}
	}
	dfs(0);
	cout << ans << '\n';
	for (auto &now : color)
		cout << now << ' ';
	return 0;
}