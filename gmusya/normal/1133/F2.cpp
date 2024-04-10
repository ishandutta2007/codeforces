#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs1(int v, int col, vector <bool> &used, vector <int> &colour, vector <vector <int>> &g) {
	used[v] = true;
	colour[v] = col;
	for (int u : g[v])
		if (!used[u])
			dfs1(u, col, used, colour, g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, d;
	cin >> n >> m >> d;
	vector <int> kids;
	vector <vector <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		if (u == 0) 
			kids.push_back(v);
		else g[u].push_back(v), g[v].push_back(u);
	}
	vector <bool> used(n);
	vector <int> colour(n);
	int col = 0;
	for (int i = 1; i < n; i++)
		if (!used[i])
			dfs1(i, col++, used, colour, g);
	if (d > kids.size() || d < col) {
		cout << "NO\n";
		return 0;
	}
	vector <bool> usedcomp(col);
	int ex = d - col;
	for (int i = 0; i < kids.size(); i++) {
		int v = kids[i];
		if (!usedcomp[colour[v]]) {
			usedcomp[colour[v]] = true;
			g[0].push_back(v);
			continue;
		}
		if (!ex) continue;
		ex--;
		g[0].push_back(v);
	}
	cout << "YES\n";
	queue <int> q;
	q.push(0);
	vector <int> dis(n, 1e9), p(n, -1);
	dis[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : g[v])
			if (dis[v] + 1 < dis[u]) {
				dis[u] = dis[v] + 1;
				p[u] = v;
				q.push(u);
			}
	}
	for (int i = 1; i < n; i++)
		cout << i + 1 << ' ' << p[i] + 1 << '\n';
	return 0;
}