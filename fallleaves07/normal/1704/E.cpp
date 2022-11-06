#include<bits/stdc++.h>
using LL = long long;
const int M = 998244353;

struct DAG {
	std::vector<std::vector<int>> e, f;
	std::vector<int> a, out;
	std::vector<bool> vis;
	int n, m;
	DAG(int n, int m) : e(n + 1), f(n + 1), a(n + 1), out(n + 1), vis(n + 1) {
		this->n = n, this->m = m;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}
		for (int i = 1; i <= m; i++) {
			int u, v;
			std::cin >> u >> v;
			e[v].emplace_back(u);
			++out[u];
		}
	}
	void dfs(int v) {
		if (vis[v]) {
			return;
		}
		vis[v] = true, f[v].resize(n + 1);
		int res = a[v];
		for (int i = 0; i < n; i++) {
			f[v][i] = (res > 0) ? 1 : 0;
			res -= f[v][i];
		}
		f[v][n] = res;
		for (auto u : e[v]) {
			dfs(u);
			for (int i = 0; i <= n; i++) {
				(f[v][std::min(n, i + 1)] += f[u][i]) %= M;
			}
			int pre = 0;
			for (int i = 0; i < n; i++) {
				pre += f[v][i];
				f[v][i] = std::min(1, pre);
				pre -= f[v][i];
			}
			(f[v][n] += pre) %= M;
		}
	}
	void solve() {
		for (int i = 1; i <= n; i++) {
			if (!out[i]) {
				dfs(i);
				while (!f[i].empty() && f[i].back() == 0) {
					f[i].pop_back();
				}
				int tot = 0;
				for (auto v : f[i]) {
					tot = (tot + ((v == 0) ? 1 : v)) % M;
				}
				std::cout << (int)tot << '\n';
			}
		}
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	DAG dag(n, m);
	dag.solve();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}