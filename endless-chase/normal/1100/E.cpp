#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x[111111],y[111111],z[111111],deg[111111],l,r,cnt,ans[111111],ord[111111],ct;
bool used[111111];
vector<int> g[111111];
bool check(int mid)
{
	memset(deg,0,sizeof(deg));
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=m;i++)
	{
		if (z[i]>mid) 
		{
			g[x[i]].push_back(y[i]); 
			deg[y[i]]++;
		}
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i); 
	}
	memset(used,0,sizeof(used));
	while(!q.empty())
	{
		int x=q.front();q.pop();
		used[x]=1;
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			deg[to]--;
			if (!deg[to]) q.push(to); 
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	l=0;r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d ",l);
	memset(deg,0,sizeof(deg));
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<=m;i++)
	{
		if (z[i]>l) 
		{
			g[x[i]].push_back(y[i]); 
			deg[y[i]]++;
		}
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i); 
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		ord[x]=++ct;
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			deg[to]--;
			if (!deg[to]) q.push(to); 
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (z[i]>l) continue;
		if (ord[x[i]]<ord[y[i]]) continue;
		ans[++cnt]=i;
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",ans[i]);
	printf("\n");
	return Accepted;
}