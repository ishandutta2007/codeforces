#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[111111],x,y,z,pa[111111],f[111111],cnt,sub[111111],ans;
bool ist[111111];
pair<int,pair<int,int> > ed[111111],d[111111];
vector<int> g[111111];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
bool Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return 0;
	pa[rx]=ry;
	return 1;
}
void dfs(int i,int fa)
{
	if (ist[i]) sub[i]=1;
	else sub[i]=0;
	f[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to]; 
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		ist[a[i]]=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		ed[i]=make_pair(z,make_pair(x,y));
	}
	sort(ed+1,ed+m+1);
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		if (Union(ed[i].second.first,ed[i].second.second))
		{
			d[++cnt]=ed[i];
			g[ed[i].second.first].push_back(ed[i].second.second);
			g[ed[i].second.second].push_back(ed[i].second.first);  
		}
	}
	dfs(1,0);
	reverse(d+1,d+cnt+1);
	for (int i=1;i<=cnt;i++)
	{
		x=d[i].second.first;y=d[i].second.second;z=d[i].first;
		if (f[x]==y) swap(x,y);
		if (sub[y] && sub[y]<k) 
		{
			ans=z;
			break;
		}
	}
	for (int i=1;i<=k;i++) printf("%d ",ans);
	return 0;
}