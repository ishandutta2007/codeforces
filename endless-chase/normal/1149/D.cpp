#include<bits/stdc++.h>
using namespace std;
int n,m,pa[111],a,b,x[222],y[222],z[222],re[222],cnt,sz[222];
vector<pair<int,int> > g[13333333];
long long dist[13333333],ans[222];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
}
int get(int a,int b)
{
	return (a*100+b);
}
void addedge(int msk,int x,int y,int z)
{
	int rx=root(x),ry=root(y);
	if (re[rx] && (!(msk&(1<<(re[rx]-1))))) return;
	if (re[ry] && re[ry]!=re[rx] && (msk&(1<<(re[ry]-1)))) return;
	if (re[ry]) g[get(msk,x)].push_back(make_pair(get(msk|(1<<(re[ry]-1)),y),z)); 
	else g[get(msk,x)].push_back(make_pair(get(msk,y),z)); 
}
queue<int> A,B;
void bfs(int s)
{
	for (int i=1;i<=13300000;i++) dist[i]=1e18;
	dist[s]=0;
	A.push(s);
	while(!A.empty() || !B.empty())
	{
		int x;
		if (A.empty())
		{
			x=B.front();
			B.pop();
		} 
		else if (B.empty())
		{
			x=A.front();
			A.pop();
		}
		else
		{
			if (dist[A.front()]<dist[B.front()])
			{
				x=A.front();
				A.pop();
			}
			else
			{
				x=B.front();
				B.pop();
			}
		}
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				if (val==a) A.push(to);
				else B.push(to); 
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	for (int i=1;i<=m;i++)
	{
		if (z[i]==a) Union(x[i],y[i]);
	}
	for (int i=1;i<=n;i++) sz[root(i)]++;
	for (int i=1;i<=n;i++)
	{
		if (root(i)==i && sz[i]>=4)
		{
			re[i]=++cnt;
		}
	}
	for (int i=0;i<(1<<cnt);i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (z[j]==b && root(x[j])==root(y[j])) continue;
			addedge(i,x[j],y[j],z[j]);
			addedge(i,y[j],x[j],z[j]);
		}
	}
	int rt=root(1);
	if (re[rt]) bfs(get((1<<(re[rt]-1)),1));
	else bfs(get(0,1));
	for (int i=1;i<=n;i++) ans[i]=1e18;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<(1<<cnt);j++)
		{
			ans[i]=min(ans[i],dist[get(j,i)]);
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}