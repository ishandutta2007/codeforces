#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n;
ll dp[200001][2];
int p[200001];
vector<int>c[200001];
void dfs(int id){
	if(c[id].empty()){
		dp[id][0]=dp[id][1]=1;
		return;
	}
	ll tzu[3];tzu[0]=1,tzu[1]=0,tzu[2]=0;
	for(auto cur:c[id]){
		dfs(cur);
		tzu[2]=(tzu[2]*(dp[cur][0]+dp[cur][1])+tzu[1]*dp[cur][1])%mod;
		tzu[1]=(tzu[0]*dp[cur][1]+tzu[1]*dp[cur][0])%mod;
		tzu[0]=tzu[0]*dp[cur][0]%mod;
	}
	dp[id][0]=(tzu[0]+tzu[2])%mod;
	dp[id][1]=(tzu[1]+tzu[2])%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2; i<=n ;i++){
		cin >> p[i];
		c[p[i]].push_back(i);
	}
	dfs(1);
	cout << dp[1][0] << '\n';
}