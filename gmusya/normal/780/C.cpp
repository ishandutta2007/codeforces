#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> col;
vector <bool> used;
vector <vector <int>> g;

void dfs(int u, int p, int gp) {
	used[u] = true;
	int cnt = 1;
	for (int i = 0; i < g[u].size(); i++) {
		while (cnt == col[u] || cnt == col[p])
			cnt++;
		if (!used[g[u][i]]) {
			col[g[u][i]] = cnt;
			cnt++;
		}
	}
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i], u, p);
}

int main() {
	int n;
	cin >> n;
	used.resize(n);
	g.resize(n);
	col.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	col[0] = 1;
	dfs(0, 0, 0);
	int ma = col[0];
	for (auto now : col)
		ma = max(ma, now);
	cout << ma << endl;
	for (auto now : col)
		cout << now << " ";
	return 0;
}