#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <set <int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	int ans = 1e9;
	for (int i = 0; i < n; i++) 
		for (auto j : g[i]) {
			if (j < i)
				continue;
			for (auto z : g[j])
				if (g[i].find(z) != g[i].end())
					ans = min(ans, (int) (g[i].size() + g[j].size() + g[z].size() - 6));
	}
	if (ans != 1e9)
		cout << ans;
	else
		cout << "-1";
	return 0;
}