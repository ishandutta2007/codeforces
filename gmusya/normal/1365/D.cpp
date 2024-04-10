#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <char>> c(n, vector <char>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> c[i][j];
		bool tf = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (c[i][j] != 'B') continue;
				if (i && c[i - 1][j] == 'G') tf = false;
				if (j && c[i][j - 1] == 'G') tf = false;
				if (i < n - 1 && c[i + 1][j] == 'G') tf = false;
				if (j < m - 1 && c[i][j + 1] == 'G') tf = false;
				if (i && c[i - 1][j] != 'B') c[i - 1][j] = '#';
				if (j && c[i][j - 1] != 'B') c[i][j - 1] = '#';
				if (i < n - 1 && c[i + 1][j] != 'B') c[i + 1][j] = '#';
				if (j < m - 1 && c[i][j + 1] != 'B') c[i][j + 1] = '#';
			}
		if (!tf) {
			cout << "No\n";
			continue;
		}
		vector <vector <int>> g(n * m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (c[i][j] == '#') continue;
				if (i && c[i - 1][j] != '#')
					g[i * m + j].push_back((i - 1) * m + j);
				if (j && c[i][j - 1] != '#')
					g[i * m + j].push_back(i * m + j - 1);
				if (i < n - 1 && c[i + 1][j] != '#')
					g[i * m + j].push_back((i + 1) * m + j);
				if (j < m - 1 && c[i][j + 1] != '#')
					g[i * m + j].push_back(i * m + j + 1);
			}
		vector <int> d(n * m, INF);
		int s = n * m - 1;
		queue <int> q;
		q.push(s);
		d[s] = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u : g[v])
				if (d[v] + 1 < d[u]) {
					d[u] = d[v] + 1;
					q.push(u);
				}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (c[i][j] == 'G' && d[i * m + j] == INF) tf = false;
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}