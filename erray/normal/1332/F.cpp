#include<bits/stdc++.h>         

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
	  --a;--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	const int mod = 998244353; 
	vector<vector<long long>> dp(n, vector<long long>(3, 1));
	function<void(int, int)> dfs = [&](int nd, int par) {
		for (int a : g[nd]) {
			if (a == par) continue;
			dfs(a, nd);
			((dp[nd][0]*=(2*dp[a][0] + 2*dp[a][1] - dp[a][2] + mod)%mod))%=mod; 
			((dp[nd][1]*=(2*dp[a][0] + dp[a][1] - dp[a][2] + mod)%mod))%=mod;
			((dp[nd][2]*=(dp[a][0] + dp[a][1] - dp[a][2] + mod)%mod))%=mod;  
		}
	};             
	dfs(0, -1);
	cout << (dp[0][1] +  dp[0][0] - dp[0][2] - 1 + mod)%mod << '\n';
}