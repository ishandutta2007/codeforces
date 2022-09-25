#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000010
int n,dp[N],g[N],ans[N],cnt[N],mxs[N],las[N],f[N];
vector<int> G[N],a[N];
void dfs1(int u,int fa){
	f[u]=fa;
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs1(v,u);
		dp[u]=max(dp[u],dp[v]+1);
	}	
}
void dfs2(int u,int fa,int up){
	int mx=up,se=up;
	a[up].push_back(u);
	for(auto v:G[u]){
		if(v==fa)continue;
		a[dp[v]+1].push_back(u);
		if(dp[v]+1>mx)se=mx,mx=dp[v]+1;
		else se=max(se,dp[v]+1);
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		if(dp[v]+1==mx)dfs2(v,u,se+1);
		else dfs2(v,u,mx+1);	
	}
}
#define update(x,y) x=max(x,y)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	fill(ans+1,ans+n+1,1);
	for(int i=1;i<=n;++i){
		ans[1]=max(ans[1],(int)G[i].size()+1);
	}
	dfs1(1,0),dfs2(1,0,0);
	for(int i=n;i>=1;--i){
		for(auto u:a[i]){
			++cnt[u];
			update(ans[i<<1],cnt[u]);
			update(ans[i<<1],cnt[u]+max(mxs[u],cnt[f[u]])-2);
			if(las[u])update(ans[2*min(i,las[u]-1)+1],cnt[u]);
			las[u]=i;
			mxs[f[u]]=max(mxs[f[u]],cnt[u]);
		}
	}
	for(int i=n;i>=2;--i){
		ans[i]=max(ans[i],ans[i+2]);
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}