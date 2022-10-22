#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, m;
		cin >> n >> m;
		vector<int> vis(n + 1), par(n + 1), up(n + 1), dep(n + 1);
		vector<vector<pair<int, int>>> G(n + 1);
		vector<pair<int, int>> edge;
		for(int i = 0; i < m; i ++) {
			int u, v;
			cin >> u >> v;
			edge.emplace_back(u, v);
			G[u].emplace_back(v, i);
			G[v].emplace_back(u, i);
		}
		string ans(m, '0');
		function<void(int)> dfs = [&] (int u) {
			vis[u] = 1;
			for(auto [v, id] : G[u]) if(!vis[v]) {
				// cout << u << "-->" << v << ' ' << id << '\n';
				ans[id] = '1';
				par[v] = u;
				dep[v] = dep[u] + 1;
				up[v] = id;
				dfs(v);
			}
		};
		dfs(1);
		vector<int> fa(n + 1);
		iota(fa.begin(), fa.end(), 0);
		function<int(int)> find = [&] (int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);};
		
		for(int i = 0; i < m; i ++) if(ans[i] == '0') {
			auto [u, v] = edge[i];
			int x = find(u), y = find(v);
			if(x == y) {
				if(dep[u] < dep[v]) swap(u, v);
				int id = up[u];
				ans[id] = '0';
				ans[i] = '1';
			}
			fa[x] = y;
		}
		cout <<ans << '\n';
	}
	return 0;
}