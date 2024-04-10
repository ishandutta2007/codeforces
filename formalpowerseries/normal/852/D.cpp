#include<bits/stdc++.h>
using namespace std;
bool vis[605];
int n,m,c,K,pos[205],dis[605][605],match[605];
vector<int> G[205];
bool dfs(int now)
{
	for(auto st:G[now])
	{
		if(vis[st])	continue;
		vis[st]=true;
		if(!match[st] || dfs(match[st]))	return match[st]=now,true;
	}
	return false;
}
bool check(int tim)
{
	memset(G,0,sizeof G);
	for(int i=1;i<=c;++i)	for(int j=1;j<=n;++j)	if(dis[pos[i]][j]<=tim)	G[i].push_back(j);
	memset(match,0,sizeof match);
	int ret=0;
	for(int i=1;i<=c;++i)
	{
		memset(vis,false,sizeof vis);
		if(dfs(i))	++ret;
	}
	return ret>=K;
}
int main(){
	scanf("%d %d %d %d",&n,&m,&c,&K);
	for(int i=1;i<=c;++i)	scanf("%d",&pos[i]);
	memset(dis,63,sizeof dis);
	for(int i=1;i<=n;++i)	dis[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		int u,v,val;
		scanf("%d %d %d",&u,&v,&val);
		dis[u][v]=dis[v][u]=min(dis[u][v],val);
	}
	for(int k=1;k<=n;++k)	for(int i=1;i<=n;++i)	for(int j=1;j<=n;++j)	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int l=0,r=1731311,ans=1731312;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))	r=mid-1,ans=mid;
		else	l=mid+1;
	}
	printf("%d",ans==1731312?-1:ans);
	return 0;
}