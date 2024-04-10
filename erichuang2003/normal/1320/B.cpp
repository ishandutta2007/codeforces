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

const int MAXN = 200005;
const int INF = 1e9;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,id,N,T,MAX,MIN;
int p[MAXN];
int dis[MAXN];
int first[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	scanf("%d",&N);
	for (int i = 1;i <= N;i++)
		scanf("%d",&p[i]);
	T = p[N];
	queue<int> Q;
	Q.push(T);
	for (int i = 1;i <= n;i++)
		dis[i] = INF;
	dis[T] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if ((~i & 1) && dis[edge[i].to] > dis[u] + 1)
			{
				dis[edge[i].to] = dis[u] + 1;
				Q.push(edge[i].to);
			}
	}
	for (int i = 1;i < N;i++)
	{
		if (dis[p[i]] < dis[p[i + 1]] + 1)
			MIN++;
		for (int j = first[p[i]];j;j = edge[j].nxt)
			if ((j & 1) && edge[j].to != p[i + 1] && dis[p[i]] == dis[edge[j].to] + 1)
			{
				MAX++;
				break;
			}
	}
	printf("%d %d\n",MIN,MAX);
	return 0;
}