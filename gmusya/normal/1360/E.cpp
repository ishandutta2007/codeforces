#include <iostream>
#include <vector>

using namespace std;

void add_edge(int n, int x1, int y1, int x2, int y2, vector <vector <bool>> &is, vector <vector <vector <pair <int, int>>>> &g) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) return;
	if (x1 >= n || y1 >= n || x2 >= n || y2 >= n) return;
	if (!is[x1][y1] || !is[x2][y2]) return;
	g[x1][y1].push_back({ x2, y2 });
}

void dfs(int x, int y, vector <vector <bool>> &used, vector <vector <vector <pair <int, int>>>> &g) {
	used[x][y] = true;
	for (auto &now : g[x][y]) {
		int _x = now.first, _y = now.second;
		if (!used[_x][_y])
			dfs(_x, _y, used, g);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <vector <vector <pair <int, int>>>> g(n, vector <vector <pair <int, int>>>(n));
		vector <vector <bool>> used(n, vector <bool>(n)), is(n, vector <bool>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				is[i][j] = (c == '1');
			}
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++) {
				add_edge(n, x, y, x - 1, y, is, g);
				add_edge(n, x, y, x, y - 1, is, g);
			}
		for (int x = 0; x < n; x++)
			dfs(x, n-1, used, g);
		for (int y = 0; y < n; y++)
			dfs(n-1, y, used, g);
		bool tf = true;
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (is[x][y] && !used[x][y])
					tf = false;
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}