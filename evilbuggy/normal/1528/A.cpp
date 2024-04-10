#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N];
long long a[N][2], dp[N][2];

void dfs(int v, int p){
	dp[v][0] = dp[v][1] = 0;
	for(int u : g[v]){
		if(u == p)continue;
		dfs(u, v);
		for(int i : {0, 1}){
			long long val = 0;
			for(int j : {0, 1}){
				val = max(val, abs(a[v][i] - a[u][j]) + dp[u][j]);
			}
			dp[v][i] += val;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		cin >> a[i][0] >> a[i][1];
	}
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}