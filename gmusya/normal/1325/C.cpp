#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <vector <pair <int, int>>> g(n);
	vector <int> ans(n - 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back({ v, i }), g[v].push_back({ u, i });
	}
	vector <int> deg(n);
	vector <bool> used(n);
	for (int i = 0; i < n; i++)
		deg[i] = g[i].size();
	queue <int> q;
	int unused = 0;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			q.push(i);
			deg[i] = 0;
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		unused++;
		if (unused == n) break;
		int v = q.front();
		q.pop();
		deg[v] = 0;
		for (auto u : g[v]) {
			if (used[u.second]) continue;
			ans[u.second] = cnt++;
			deg[u.first]--;
			used[u.second] = true;
			if (deg[u.first] == 1) 
				q.push(u.first);
		}
	}
	for (int i = 0; i < n - 1; i++)
		cout << ans[i] << endl;
	return 0;
}