#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector <int> &d, vector <vector <int>> &g) {
	d[v] = 1;
	for (int u : g[v]) {
		if (!d[u])
			dfs(u, d, g);
		d[v] = max(d[v], d[u] + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		vector <vector <int>> g(n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 2 * i; j <= n; j += i)
				if (a[i] < a[j])
					g[j].push_back(i);
		vector <int> d(n + 1);
		for (int i = 1; i <= n; i++)
			dfs(i, d, g);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, d[i]);
		cout << ans << '\n';
	}
	return 0;
}