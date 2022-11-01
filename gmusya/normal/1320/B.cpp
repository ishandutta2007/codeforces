#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int>> g(n), _g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), _g[v].push_back(u);
	}
	int k;
	cin >> k;
	vector <int> path(k);
	for (int i = 0; i < k; i++) {
		cin >> path[i];
		path[i]--;
	}
	int f = path[k - 1];
	vector <int> d(n, INF);
	d[f] = 0;
	queue <int> q;
	q.push(f);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : _g[v]) {
			if (d[u] == INF) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	int ans_min = 0, ans_max = 0;
	for (int i = 0; i < k - 1; i++) {
		int v = path[i], u = path[i + 1];
		if (d[v] != d[u] + 1) {
			ans_min++, ans_max++;
			continue;
		}
		for (int w : g[v]) 
			if (d[w] <= d[u] && w != u) {
				ans_max++;
				break;
			}
	}
	cout << ans_min << " " << ans_max << endl;
	return 0;
}