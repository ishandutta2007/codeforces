#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 205
const int mod=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
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
int n,K,c[N],dp[N][M],siz[N],S[M][M],fac[M],ans;
vector<int> G[N];
void dfs(int u,int fa){
	dp[u][0]=2;
	siz[u]=1;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		static int g[M];
		for(int i=0;i<=K;++i)c[i]=(c[i]-dp[v][i]+mod)%mod;
		for(int i=0;i<=min(K,siz[u]+siz[v]);++i)g[i]=0;
		for(int i=0;i<=min(K,siz[u]);++i){
			for(int j=0;j<=min(K-i,siz[v]);++j){
				g[i+j]=(g[i+j]+1LL*dp[u][i]*dp[v][j])%mod;
			}
		}
		siz[u]+=siz[v];
		for(int i=0;i<=min(K,siz[u]);++i)dp[u][i]=g[i];
	}
	for(int i=0;i<=K;++i)c[i]=(c[i]+dp[u][i])%mod;
	for(int i=K;i>=1;--i){
		dp[u][i]=(dp[u][i]+dp[u][i-1])%mod;
	}
	dp[u][1]=(dp[u][1]+mod-1)%mod;
}
int main(){
	n=read(),K=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	fac[0]=1;
	for(int i=1;i<=K;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	S[0][0]=1;
	for(int i=1;i<=K;++i){
		for(int j=1;j<=i;++j){
			S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%mod;	
		}
	}
	for(int i=0;i<=K;++i){
		ans=(ans+1LL*fac[i]*c[i]%mod*S[K][i])%mod;	
	}
	printf("%d\n",ans);
	return 0;
}