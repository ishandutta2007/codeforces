#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,id;
int l[MAXN];
int r[MAXN];
int first[MAXN];

long long f[MAXN][2];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	f[u][0] = f[u][1] = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			f[u][0] += max(f[edge[i].to][0] + abs(l[edge[i].to] - l[u]),f[edge[i].to][1] + abs(r[edge[i].to] - l[u]));
			f[u][1] += max(f[edge[i].to][0] + abs(l[edge[i].to] - r[u]),f[edge[i].to][1] + abs(r[edge[i].to] - r[u]));
		}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d%d",&l[i],&r[i]);
		for (int u,v,i = 1;i < n;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
			addE(v,u);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
	return 0;
}