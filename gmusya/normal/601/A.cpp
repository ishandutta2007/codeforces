#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector <vector <bool>> tf;
vector <vector <int>> g;

int main() {
	cin >> n >> m;
	tf.assign(n, vector<bool>(n));
	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		tf[u][v] = 1;
		tf[v][u] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tf[i][j] != tf[0][n - 1] && i != j)
				g[i].push_back(j);
	vector <int> d(n, -1);
	queue <int> q;
	d[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto to : g[u]) {
			if (d[to] != -1)
				continue;
			d[to] = d[u] + 1;
			q.push(to);
		}
	}
	cout << d[n - 1];
}