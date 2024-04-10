#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <bool> used;
vector <int> d;
vector <int> p;
vector <vector <int>> g;

void dfs(int u, int p) {
	used[u] = true;
	if (p == -1)
		d[u] = 0;
	else
		d[u] = d[p] + 1;
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i], u);
}

int main() {
	cin >> n;
	used.resize(n);
	d.resize(n);
	g.resize(n);
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (v == -1)
			p.push_back(i);
		else
			g[v - 1].push_back(i);
	}
	for (int i = 0; i < p.size(); i++)
		dfs(p[i], -1);
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	cout << ans + 1;
	return 0;
}