#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <bool> used;
vector <vector <int>> g;

void dfs(int u) {
	used[u] = true;
	for (int to : g[u])
		if (!used[to])
			dfs(to);
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	g.resize(n + m), used.resize(n + m);
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y + n);
		g[y + n].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < n + m; i++)
		if (!used[i]) {
			ans++;
			dfs(i);
		}
	cout << ans - 1;
	return 0;
}