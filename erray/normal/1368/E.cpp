#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n), rg(n);
		while (m--) {
			int a, b;
			cin >> a >> b;
			--a;--b;
			g[a].push_back(b);
			rg[b].push_back(a);
		}
		vector<int> dp(n, -1);
		function<int(int)> dfs = [&] (int nd) {
			if (dp[nd] != -1) return dp[nd];
			dp[nd] = 0;
			for (int el : rg[nd]) {
				dp[nd] = max(dfs(el) + 1, dp[nd]);
			}
			return dp[nd];
		};
		vector<int> ord(n);
		iota(ord.begin(), ord.end(), 0);
		sort(ord.begin(), ord.end(), [=](int a, int b) {
			return dfs(a) < dfs(b); 
		});
		vector<int> dp2(n), ans;        
		for (int el : ord) {
			for (int nd : rg[el]) {
				dp2[el] = max(dp2[nd] + 1, dp2[el]);		
			}
			if (dp2[el] == 2) {
				dp2[el] = -1;
				ans.push_back(el);
			}
		}
		assert((int) ans.size() <= 4 * n / 7);
		cout << ans.size() << '\n';
		for (int el : ans) cout << el + 1 << ' ';
		cout << '\n';
	}
}