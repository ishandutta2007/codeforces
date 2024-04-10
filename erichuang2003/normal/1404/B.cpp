#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,a,b,da,db,id;
int first[MAXN];
int depth[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int getlen(int u,int fa,int v)
{
	if (u == v)
		return 0;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (edge[i].to == fa)
			continue;
		int r = getlen(edge[i].to,u,v);
		if (r <= n)
			return r + 1;
	}
	return 1e9;
}

int getd(int u,int fa)
{
	int MAX = 0,MAX2 = 0,res = 0;
	depth[u] = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			res = max(res,getd(edge[i].to,u));
			depth[u] = max(depth[u],depth[edge[i].to] + 1);
			if (depth[edge[i].to] + 1 >= MAX)
			{
				MAX2 = MAX;
				MAX = depth[edge[i].to] + 1;
			}
			else if (depth[edge[i].to] + 1 > MAX2)
				MAX2 = depth[edge[i].to] + 1;
		}
	res = max(res,MAX + MAX2);
	return res;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		id = 0;
		for (int u,v,i = 1;i < n;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
			addE(v,u);
		}
		int d = getd(1,0);
		da = min(da,d);
		db = min(db,d);
		puts(getlen(a,0,b) <= da || 2 * da >= db ? "Alice" : "Bob");
	}
	return 0;
}