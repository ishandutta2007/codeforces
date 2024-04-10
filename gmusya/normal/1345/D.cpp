#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector <bool> &used, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v]) 
		if (!used[u])
			dfs(u, used, g);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <char>> c(n, vector <char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	bool tf1 = false, tf2 = false;
	for (int i = 0; i < n; i++) {
		int L = 0;
		int R = m - 1;
		for (; L < m && c[i][L] != '#'; L++);
		for (; R >= 0 && c[i][R] != '#'; R--);
		if (L == m) {
			tf1 = true;
			continue;
		}
		for (int j = L; j <= R; j++)
			if (c[i][j] == '.') {
				cout << "-1";
				return 0;
			}
	}
	for (int j = 0; j < m; j++) {
		int L = 0;
		int R = n - 1;
		for (; L < n && c[L][j] != '#'; L++);
		for (; R >= 0 && c[R][j] != '#'; R--);
		if (L == n) {
			tf2 = true;
			continue;
		}
		for (int i = L; i <= R; i++)
			if (c[i][j] == '.') {
				cout << "-1";
				return 0;
			}
	}
	if (tf1 + tf2 == 1) {
		cout << -1;
		return 0;
	}
	vector <vector <int>> g(n * m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (c[i][j] == '.') continue;
			if (j + 1 < m && c[i][j + 1] == '#') {
				g[i * m + j].push_back(i * m + (j + 1));
				g[i * m + (j + 1)].push_back(i * m + j);
			}
			if (i + 1 < n && c[i + 1][j] == '#') {
				g[i * m + j].push_back((i + 1) * m + j);
				g[(i + 1) * m + j].push_back(i * m + j);
			}
			if (j - 1 >= 0 && c[i][j - 1] == '#') {
				g[i * m + j].push_back(i * m + (j - 1));
				g[i * m + (j - 1)].push_back(i * m + j);
			}
			if (i - 1 >= 0 && c[i - 1][j] == '#') {
				g[i * m + j].push_back((i - 1) * m + j);
				g[(i - 1) * m + j].push_back(i * m + j);
			}
		}
	int ans = 0;
	vector <bool> used(n * m);
	for (int i = 0; i < n * m; i++)
		if (c[i / m][i % m] == '#' && !used[i]) {
			dfs(i, used, g);
			ans++;
		}
	cout << ans;
	return 0;
}