#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int fa[N][17],dep[N],n,q;
vector<int>e[N];
void dfs(int u,int f)
{
	fa[u][0]=f;
	dep[u]=dep[f]+1;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=16;i>=0;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=16;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y)
{
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
int can(int x,int k)
{
	if(x>k)
		return 0;
	if((x-k)&1)
		return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<17;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&q);
	while(q--)
	{
		int x,y,a,b,k;
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int zh=0;
		if(can(dis(a,b),k))
			zh=1;
		if(can(dis(a,x)+dis(b,y)+1,k))
			zh=1;
		if(can(dis(a,y)+dis(b,x)+1,k))
			zh=1;
		puts(zh?"YES":"NO");
	}
	return 0;
}