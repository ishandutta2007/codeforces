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

const int MAXN = 2005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int n,rt,id;
int first[MAXN];
int c[MAXN];
int a[MAXN];
int sz[MAXN];

vector<int> num[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void getsize(int u)
{
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		getsize(edge[i].to);
		sz[u] += sz[edge[i].to];
	}
}

void dfs(int u)
{
	if (c[u] > sz[u] - 1)
	{
		puts("NO");
		exit(0);
	}
	a[u] = num[u][c[u]];
	num[u].erase(num[u].begin() + c[u]);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		for (int j = 0;j < sz[edge[i].to];j++)
		{
			num[edge[i].to].push_back(num[u].back());
			num[u].pop_back();
		}
		reverse(num[edge[i].to].begin(),num[edge[i].to].end());
		dfs(edge[i].to);
	}
}

int main()
{
	scanf("%d",&n);
	for (int fa,i = 1;i <= n;i++)
	{
		scanf("%d%d",&fa,&c[i]);
		if (fa)
			addE(fa,i);
		else
			rt = i;
	}
	getsize(rt);
	for (int i = 1;i <= n;i++)
		num[rt].push_back(i);
	dfs(rt);
	puts("YES");
	for (int i = 1;i <= n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}