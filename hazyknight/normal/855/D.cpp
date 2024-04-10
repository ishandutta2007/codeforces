#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,q,u,v,id,tp,c1,c2;
int first[MAXN];
int dfn[MAXN];
int R[MAXN];
int fa1[MAXN];
int fa2[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	dfn[u] = ++c1;
	for (int i = first[u];i;i = edge[i].nxt)
		dfs(edge[i].to);
	R[u] = ++c2;
}

bool isfa1(int u,int v)
{
	return dfn[u] < dfn[v] && R[u] > R[v];
}

bool isfa2(int u,int v)
{
	return dfn[u] <= dfn[v] && R[u] >= R[v];
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&u,&v);
		if (u == -1)
		{
			fa1[i] = fa2[i] = i;
			continue;
		}
		addE(u,i);
		fa1[i] = (v == 1 ? fa1[u] : i);
		fa2[i] = v ? i : fa2[u];
	}
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			dfs(i);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d%d%d",&tp,&u,&v);
		if (tp == 2)
		{
			if (u == v || fa1[v] == v)
				puts("NO");
			else if (isfa2(fa1[v],fa2[u]) && isfa1(fa2[u],v))
				puts("YES");
			else if (isfa2(fa2[u],fa1[v]) && isfa2(fa1[v],u))
				puts("YES");
			else
				puts("NO");
		}
		else
			puts(isfa2(fa2[v],u) && isfa1(u,v) ? "YES" : "NO");
	}
	return 0;
}