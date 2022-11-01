#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k,tot,f[21][300005],root[600006];
int dep[600005],col[600005],cnt[600005],f0[600005],f1[600006];
int point[1000005],nxt[1000005],head[1000005];
vector<int> g[300005];
void goto_Hell(){puts("0");exit(0);}
void addedge(int x,int y)
{
	point[++tot]=y,nxt[tot]=head[x],head[x]=tot;
	point[++tot]=x,nxt[tot]=head[y],head[y]=tot;
}
void dfs(int x,int fa)
{
	f[0][x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=point[i];
		if(y==fa) continue;
		dfs(y,x);
	}
}
void paint_Tree(int x)
{
	int c=col[x];
	x=f[0][x];
	while(col[x]!=c)
	{
		if(col[x]) goto_Hell();
		col[x]=c;x=f[0][x];
	}
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	if(dep[x]>dep[y])
		for(int i=20;i>=0;i--) if(dep[f[i][x]]>=dep[y]) x=f[i][x];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(f[i][x]!=f[i][y]) x=f[i][x],y=f[i][y];
	return f[0][x];
}
void dfs2(int x,int fa)
{
	cnt[x]=(col[x]>0);
	for(int i=head[x];i;i=nxt[i])
	{
		int y=point[i];
		if(y==fa) continue;
		dfs2(y,x);
		cnt[x]+=cnt[y];
	}
	if(!cnt[x]) return;
	if(col[x]) f1[x]=1;
	else f0[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=point[i];
		if(y==fa||!cnt[y]) continue;
		if(col[x]) f1[x]=1ll*f1[x]*(f0[y]+f1[y])%mod;
		else 
		{
			f1[x]=(1ll*f1[x]*(f0[y]+f1[y])+1ll*f0[x]*f1[y])%mod;
			f0[x]=1ll*f0[x]*(f0[y]+f1[y])%mod;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&col[i]),g[col[i]].push_back(i);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1,0);
	for(int i=1;i<=20;i++) for(int x=1;x<=n;x++) f[i][x]=f[i-1][f[i-1][x]];
	for(int i=1;i<=k;i++) 
	{
		root[i]=g[i][0];
		for(int j=1;j<g[i].size();j++) root[i]=getlca(root[i],g[i][j]);
		if(col[root[i]]&&col[root[i]]!=i) goto_Hell();
		col[root[i]]=i;
		for(int j=0;j<g[i].size();j++)
		{
			int x=g[i][j];
			if(x==root[i]) continue;
			paint_Tree(x);
		}
	}
	dfs2(1,0);
	printf("%d\n",f1[1]);
	return 0;
}