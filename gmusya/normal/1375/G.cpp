#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector <bool> &used, vector <int> &col, vector <vector <int>> &g) {
	used[v] = true;
	for (int u : g[v])
		if (!used[u]) {
			col[u] = (col[v] ^ 1);
			dfs(u, used, col, g);
		}
}

int main() {
	int n;
	cin >> n;
	vector <vector <int>> g(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector <bool> used(n);
	vector <int> col(n);
	dfs(0, used, col, g);
	int b = 0, w = 0;
	for (int i = 0; i < n; i++) {
		if (col[i]) b++;
		else w++;
	}
	if (b > w) swap(b, w);
	cout << b - 1;
	return 0;
}