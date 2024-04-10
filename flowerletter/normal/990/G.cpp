#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main(){
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	constexpr int maxn = 2e5 + 10;
	int n;
	cin >> n;
	vector<vector<int>> G(n + 1);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	vector<map<int, int>> t(n + 1);
	vector<i64> ans(maxn);
	function<void(int, int)> dfs = [&] (int u, int par) {
		t[u][a[u]] = 1;
		ans[a[u]] ++;
		for(auto v : G[u]) if(v != par) {
			dfs(v, u);
			for(auto [w, k] : t[v]) {
				for(auto [x, y] : t[u]) ans[__gcd(x, w)] += 1ll * y * k;
			}
			for(auto [w, k] : t[v]) {
				int o = __gcd(w, a[u]);
				t[u][o] += k;
			}
			t[v].clear();
		}
	};
	dfs(1, 1);
	for(int i = 1; i < maxn; i ++) if(ans[i]) cout << i << ' ' << ans[i] << '\n';
	return 0;
}