#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int mod = 998244353;

vector<int> g[N];
long long dp[N][3];

void dfs(int v, int p){
	for(int u : g[v]){
		if(u != p){
			dfs(u, v);
		}
	}
	// dp[v][0]
	dp[v][0] = 1;
	for(int u : g[v]){
		if(u != p){
			dp[v][0] = dp[v][0]*(dp[u][0] + dp[u][1])%mod;
		}
	}

	// dp[v][1]
	vector<long long> arr, pref, suff;
	for(int u : g[v]){
		if(u != p){
			arr.emplace_back(dp[u][2]);
			pref.emplace_back((dp[u][0] + 2*dp[u][1])%mod);
			suff.emplace_back((dp[u][0] + 2*dp[u][1])%mod);
		}
	}
	int sz = (int)pref.size();
	for(int i = 1; i < sz; i++){
		pref[i] = pref[i]*pref[i - 1]%mod;
	}
	for(int i = sz - 2; i >= 0; i--){
		suff[i] = suff[i]*suff[i + 1]%mod;
	}
	dp[v][1] = 0;
	for(int i = 0; i < sz; i++){
		long long tmp = arr[i];
		if(i > 0)tmp = tmp*pref[i - 1]%mod;
		if(i + 1 < sz)tmp = tmp*suff[i + 1]%mod;
		dp[v][1] += tmp;
	}
	dp[v][1] %= mod;

	//dp[v][2]
	dp[v][2] = 1;
	for(int u : g[v]){
		if(u != p){
			dp[v][2] = dp[v][2]*(dp[u][0] + 2*dp[u][1])%mod;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	cout << (dp[1][0] + dp[1][1])%mod << '\n';

	return 0;
}