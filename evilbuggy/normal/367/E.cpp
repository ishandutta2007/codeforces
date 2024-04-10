#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;
int n, m, x;
vector<vector<vector<ll> > > dp;

ll dfs(int ind, int open, int close){
	if(ind == m + 1)return open == n && close == n;
	if(dp[ind][open][close] != -1)return dp[ind][open][close];
	if(ind == x){
		if(open == n)return 0;
		ll &ret = dp[ind][open][close];
		ret = dfs(ind + 1, open + 1, close);
		ret += dfs(ind + 1, open + 1, close + 1);
		if(ret >= mod)ret -= mod;
		return ret;
	}
	ll &ret = dp[ind][open][close];
	ret = dfs(ind + 1, open, close);
	if(open < n)ret += dfs(ind + 1, open + 1, close);
	if(ret >= mod)ret -= mod;
	if(open < n)ret += dfs(ind + 1, open + 1, close + 1);
	if(ret >= mod)ret -= mod;
	if(close < open)ret += dfs(ind + 1, open, close + 1);
	if(ret >= mod)ret -= mod;
	return ret;
}

int main(){
	cin>>n>>m>>x;
	if(n > m){
		cout<<0<<endl;
		exit(0);
	}
	dp = vector<vector<vector<ll> > > (m + 5, vector<vector<ll> > (n + 5, vector<ll> (n + 5, -1)));
	ll ans = dfs(1,0,0);
	for(int i = 2; i <= n; i++){
		(ans *= i) %= mod;
	}
	cout<<ans<<endl;
}