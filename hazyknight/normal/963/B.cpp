#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int sum;
	int next;
}edge[MAXN << 1],Gdge[MAXN << 1];

int n,id,p1,p2;
int first[MAXN];
int Girst[MAXN];
int degree[MAXN];

queue<int> Q;

inline void addE(int u,int v)
{
	edge[++id] = (Edge){v,0,first[u]};
	first[u] = id;
}

inline void addG(int u,int v)
{
	Gdge[++id] = (Edge){v,0,Girst[u]};
	Girst[u] = id;
	degree[v]++;
}

int dfs(int now,int fa)
{
	int ret = 1;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			if (!edge[i].sum)
			{
				edge[i].sum = dfs(edge[i].to,now);
				edge[i ^ 1].sum = n - edge[i].sum;
			}
			ret += edge[i].sum;
		}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	scanf("%d",&n);
	if (!(n & 1))
	{
		printf("NO\n");
		return 0; 
	}
	id = 1;
	for (int fa,i = 1;i <= n;i++)
	{
		scanf("%d",&fa);
		if (!fa)
			continue;
		addE(fa,i);
		addE(i,fa);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = first[i];j;j = edge[j].next)
		{
			if (!edge[j].sum)
			{
				edge[j].sum = dfs(edge[j].to,i);
				edge[j ^ 1].sum = n - edge[j].sum;
			}
			if (edge[j].sum % 2 == 0)
				addG(edge[j].to,i);
		}
	}
	printf("YES\n");
	for (int i = 1;i <= n;i++)
		if (!degree[i])
			Q.push(i);
	while (!Q.empty())
	{
		int now = Q.front();
		printf("%d\n",now);
		Q.pop();
		for (int i = Girst[now];i;i = Gdge[i].next)
		{
			degree[Gdge[i].to]--;
			if (!degree[Gdge[i].to])
				Q.push(Gdge[i].to);
		}
	}
	return 0;
}