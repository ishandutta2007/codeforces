#include<bits/stdc++.h>
using namespace std;
#define N 100010
const int B=800;
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
int n,dp[N],g[N],ans[N],p[N],dep[N],f[N];
vector<int> G[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;f[u]=fa;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
inline int calc(int x){
	memset(dp,0,sizeof(dp));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;++i){
		int u=p[i];
		int mx=1,se=1;
		for(auto v:G[u]){
			if(v==f[u])continue;
			if(g[v]+1>=mx)se=mx,mx=g[v]+1;
			else if(g[v]+1>se)se=g[v]+1;
			dp[u]+=dp[v];
		}
		if(mx+se-1>=x)++dp[u];
		else g[u]=mx;
	}
	return dp[1];
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)p[i]=i;
	dfs(1,0);
	sort(p+1,p+n+1,[&](int i,int j){return dep[i]>dep[j];});
	for(int i=1;i<=min(n,B);++i){
		ans[i]=calc(i);	
	}
	for(int i=B+1,j;i<=n;i=j+1){
		ans[i]=calc(i);
		j=i;int p=1;
		while(j+p<=n&&calc(j+p)==ans[i])j+=p,p<<=1;
		while(p){if(j+p<=n&&calc(j+p)==ans[i])j+=p;p>>=1;}
		for(int k=i;k<=j;++k)ans[k]=ans[i];
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}