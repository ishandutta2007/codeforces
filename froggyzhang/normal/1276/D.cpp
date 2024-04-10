#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
typedef long long ll;
int dp[N][4],n;
vector<int> G[N];
void dfs(int u,int fa){
	vector<int> pre(G[u].size()),suf(G[u].size());
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);	
	}
	int Pre=1,Suf=1;
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if(v==fa){
			pre[i]=Pre;
			continue;
		}
		pre[i]=(Pre=1LL*Pre*(dp[v][0]+dp[v][1])%mod);
	}
	for(int i=G[u].size()-1;i>=0;--i){
		int v=G[u][i];
		if(v==fa){
			suf[i]=Suf;
			dp[u][1]=1LL*suf[i]*pre[i]%mod;
			continue;
		}
		suf[i]=(Suf=1LL*Suf*((dp[v][0]+dp[v][2])%mod+dp[v][3])%mod);	
	}
	dp[u][3]=Pre;
	int now=0;
	for(int i=0;i<(int)G[u].size();++i){
		int v=G[u][i];
		if(v==fa){now=2;continue;}
		dp[u][now]=(dp[u][now]+1LL*(dp[v][2]+dp[v][3])%mod*(!i?1:pre[i-1])%mod*(i==G[u].size()-1?1:suf[i+1]))%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<(dp[1][0]+(dp[1][2]+dp[1][3])%mod)%mod<<'\n';
	return 0;
}