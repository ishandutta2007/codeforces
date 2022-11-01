#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool tf = true;
vector <int> order;
vector <bool> used;
vector <vector <int>> g, gr, d;

void dfs1(int v) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u])
			dfs1(u);
	order.push_back(v);
}

void dfs2(int v) {
	used[v] = true;
	for (int u : gr[v])
		if (!used[u])
			dfs2(u);
}

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	g.resize(n), gr.resize(n), used.resize(n), d.resize(n, vector <int>(26));
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		gr[v].push_back(u);
		if (u == v)
			tf = false;
	}
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs1(i);
	used.assign(n, false);
	for (int i = 0; i < n; i++) {
		if (used[order[n - i - 1]] || !tf) {
			cout << "-1";
			return 0;
		}
		dfs2(order[n - i - 1]);
	}
	vector <int> deg(n);
	for (int v = 0; v < n; v++)
		for (int u : g[v])
			deg[u]++;
	queue <int> q;
	for (int v = 0; v < n; v++)
		if (deg[v] == 0)
			q.push(v);
	used.assign(n, false);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		d[v][s[v] - 'a']++;
		used[v] = true;
		for (int u : g[v]) {
			for (int i = 0; i < 26; i++)
				d[u][i] = max(d[u][i], d[v][i]);
			deg[u]--;
			if (deg[u] == 0) {
				q.push(u);
				used[u] = true;
			}
		}
	}
	int ma = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 26; j++)
			ma = max(d[i][j], ma);
	cout << ma;
	return 0;
}