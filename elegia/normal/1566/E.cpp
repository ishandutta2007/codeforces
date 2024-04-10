#include <bits/stdc++.h>

typedef unsigned long long ull;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int n; std::cin >> n;
		std::vector<std::vector<int>> g(n);
		for (int rep = 1; rep != n; ++rep) {
			int u, v; std::cin >> u >> v; --u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0;
		std::function<bool(int, int)> dfs = [&](int u, int p) {
			int tot = 0;
			for (int v : g[u]) if (v != p) tot += dfs(v, u);
			if (!tot) return ++ans, true;
			if (p != -1) --ans; return false;
		};
		dfs(0, -1);
		std::cout << ans << '\n';
	}
	return 0;
}