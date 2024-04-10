#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, int &cnt, vector <bool> &used, vector <vector <int>> &g) {
	used[v] = true;
	cnt++;
	for (int u : g[v])
		if (!used[u])
			dfs(u, cnt, used, g);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		a--, b--;
		vector <vector <int>> g(n);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector <bool> used(n);
		used[a] = true;
		int cntb = 0;
		dfs(b, cntb, used, g);
		used.assign(n, false);
		used[b] = true;
		int cnta = 0;
		dfs(a, cnta, used, g);
		long long x = (n - cntb - 1);
		long long y = (n - cnta - 1);
		cout << x * y << '\n';
	}
	return 0;
}