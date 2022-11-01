#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minv = 1000000, maxv = -1;

int n, m;
vector <bool> used;
vector <pair <int, int>> kek;
vector <vector <int>> g;

void dfs(int u) {
	if (u < minv)
		minv = u;
	if (u > maxv)
		maxv = u;
	used[u] = true;
	for (int i = 0; i < g[u].size(); i++)
		if (!used[g[u][i]])
			dfs(g[u][i]);
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
	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;
		minv = 1000000, maxv = -1;
		dfs(i);
		kek.push_back({minv, maxv});
	}
	int cnt = 0;
	for (int i = 0; i < kek.size() - 1; i++)
		if (kek[i].second > kek[i + 1].first) {
			cnt++;
			kek[i + 1].first = kek[i].first;
			kek[i + 1].second = max(kek[i].second, kek[i + 1].second);
		}
	cout << cnt;
	return 0;
}