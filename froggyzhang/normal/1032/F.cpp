#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=998244353;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,dp[N][3]; //      
vector<int> G[N];
void dfs(int u,int fa){
	dp[u][0]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		dp[u][2]=(1LL*(dp[u][0]+dp[u][1])*(dp[v][0]+dp[v][1])+dp[u][2]*(dp[v][0]+2LL*dp[v][2]))%mod;
		dp[u][1]=(1LL*dp[u][0]*dp[v][2]+1LL*dp[u][1]*(dp[v][0]+2LL*dp[v][2]))%mod;
		dp[u][0]=1LL*dp[u][0]*(dp[v][0]+dp[v][2])%mod;
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",(dp[1][0]+dp[1][2])%mod);
	return 0;
}