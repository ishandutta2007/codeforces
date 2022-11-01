#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
const int INF = 2e9;

pair <int, int> _f(int v) {
	return { v / m, v % m };
}

int f(int i, int j) {
	return i * m + j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int sx, sy, maxl, maxr;
	cin >> sx >> sy >> maxl >> maxr;
	sx--, sy--;
	vector <vector <char>> c(n, vector <char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	vector <bool> used(n * m);
	vector <int> d(n * m, INF);
	d[f(sx, sy)] = 0;
	deque <int> dq;
	dq.push_back(f(sx, sy));
	while (!dq.empty()) {
		int v = dq.front();
		dq.pop_front();
		if (used[v]) continue;
		used[v] = true;
		pair <int, int> kek = _f(v);
		int x = kek.first;
		int y = kek.second;
		vector <pair <int, int>> g;
		if (x + 1 < n && c[x + 1][y] != '*') g.push_back({ f(x + 1, y), 0 });
		if (x - 1 >= 0 && c[x - 1][y] != '*') g.push_back({ f(x - 1, y), 0 });
		if (y + 1 < m && c[x][y + 1] != '*') g.push_back({ f(x, y + 1), 1 });
		if (y - 1 >= 0 && c[x][y - 1] != '*') g.push_back({ f(x, y - 1), 0 });
		for (auto now : g) {
			int u = now.first;
			int w = now.second;
			if (d[v] + w < d[u]) {
				if (w == 1) dq.push_back(u);
				else dq.push_front(u);
				d[u] = d[v] + w;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = f(i, j);
			int r = d[v];
			int l = r - (j - sy);
			if (l <= maxl && r <= maxr) ans++;
		}
	cout << ans;
	return 0;
}