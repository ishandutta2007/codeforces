#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <bool> used(n);
	vector <vector <pair <int, int>>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}
	vector <int> d(n);
	queue <int> q;
	q.push(0);
	used[0] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (pair <int, int> u : g[v]) 
			if (!used[u.first]) {
				q.push(u.first);
				used[u.first] = true;
				d[u.first] = d[v] + u.second;
			}
	}
	int ma = 0;
	for (int i = 0; i < n; i++)
		ma = max(d[i], ma);
	cout << ma;
	return 0;
}