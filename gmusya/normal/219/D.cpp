#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <bool> used;
vector <int> d, ans;
vector <vector <pair <int, int>>> g;

void dfs1(int v) {
	used[v] = true;
	for (auto now : g[v]) {
		int u = now.first;
		int w = now.second;
		if (!used[u]) {
			d[u] = d[v] + w;
			ans[0] += w;
			dfs1(u);
		}
	}
}

void dfs2(int v, int _w = 0, int p = -1) {
	used[v] = false;
	if (p != -1) ans[v] = ans[p] + 1 - 2 * _w;
	for (auto now : g[v]) {
		int u = now.first;
		int w = now.second;
		if (used[u])
			dfs2(u, w, v);
	}
}

int main() {
	cin >> n;
	used.resize(n), d.resize(n), ans.resize(n), g.resize(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back({ v, 0 });
		g[v].push_back({ u, 1 });
	}
	dfs1(0);
	dfs2(0);
	int mi = 1e9;
	for (int i = 0; i < n; i++) mi = min(ans[i], mi);
	vector <int> answer;
	for (int i = 0; i < n; i++) 
		if (mi == ans[i]) 
			answer.push_back(i + 1);
	cout << mi << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}