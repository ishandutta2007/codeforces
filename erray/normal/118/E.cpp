#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	vector<int> dp(n, -1), d(n, -1);
	vector<pair<int, int>> ans;
	d[0] = 0;
	function<int(int, int)> dfs = [&](int nd, int par) {
		dp[nd] = 0;
		for (int a : g[nd]) {
			if (a == par) continue;
			if (d[nd] > d[a]){
				ans.emplace_back(nd, a);
			}
			if (d[a] == -1) {
				d[a] = d[nd] + 1;
				dp[nd] += dfs(a, nd);
			} else {
				dp[nd] += d[a] > d[nd] ? -1 : 1;
			}         
		}       
		return dp[nd];
	};
	dfs(0, -1);
	for (int i = 1; i < n; ++i) {
		if (!dp[i]) return cout << 0, 0;
	}
	for (auto a : ans) cout << a.first + 1 << ' ' << a.second + 1 << '\n';
}