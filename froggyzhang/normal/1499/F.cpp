/*qwq*/
#include<bits/stdc++.h>
using namespace std;
#define N 5050
typedef long long ll;
const int mod=998244353;
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
int n,K,dp[N][N],siz[N],ans;
vector<int> G[N];
void dfs(int u,int fa){
	siz[u]=1;
	dp[u][0]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		static int g[N];
		for(int i=0;i<=min(K,max(siz[u],siz[v]+1));++i)g[i]=0;
		for(int i=0;i<=min(K,siz[u]);++i){
			for(int j=0;j<=min(K,siz[v]);++j){
				g[i]=(g[i]+1LL*dp[u][i]*dp[v][j])%mod;
			}
			for(int j=0;j<=min(K-i-1,siz[v]);++j){
				g[max(i,j+1)]=(g[max(i,j+1)]+1LL*dp[u][i]*dp[v][j])%mod;
			}
		}
		for(int i=0;i<=min(K,max(siz[u],siz[v]+1));++i)dp[u][i]=g[i];
		siz[u]+=siz[v];
	}
}
int main(){
	n=read(),K=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=0;i<=K;++i)ans=(ans+dp[1][i])%mod;
	printf("%d\n",ans);
	return 0;
}