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

typedef long long ll;

const int MAXN = 1005;
const int MAXM = 10005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXM << 1];

int n,m,L,s,t,id;
int first[MAXN];
int u[MAXM];
int v[MAXM];
int w[MAXM];
int dis[MAXN];

bool mark[MAXN];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void Dijkstra()
{
	memset(mark,0,sizeof(mark));
	while (!Q.empty())
	{
		int d = Q.top().first,u = Q.top().second;
		Q.pop();
		if (mark[u])
			continue;
		mark[u] = 1;
		for (int i = first[u];i;i = edge[i].nxt)
			if (dis[edge[i].to] > dis[u] + edge[i].w)
				Q.push(make_pair(dis[edge[i].to] = dis[u] + edge[i].w,edge[i].to));
	}
}

int main()
{
	srand(20030506);
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	s++,t++;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		u[i]++;
		v[i]++;
		if (w[i] > 0)
		{
			addE(u[i],v[i],w[i]);
			addE(v[i],u[i],w[i]);
		}
	}
	for (int i = 2;i <= m;i++)
	{
		int to = rand() % (i - 1) + 1;
		swap(u[to],u[i]);
		swap(v[to],v[i]);
		swap(w[to],w[i]);
	}
	for (int i = 1;i <= n;i++)
		dis[i] = L + 1;
	dis[s] = 0;
	Q.push(make_pair(0,s));
	Dijkstra();
	if (dis[t] < L)
	{
		puts("NO");
		return 0;
	}
	if (dis[t] == L)
	{
		puts("YES");
		for (int i = 1;i <= m;i++)
			printf("%d %d %d\n",u[i] - 1,v[i] - 1,w[i] ? w[i] : L + 1);
		return 0;
	}
	for (int i = 1;i <= m;i++)
		if (!w[i])
		{
			w[i] = 1;
			addE(u[i],v[i],1);
			addE(v[i],u[i],1);
			Q.push(make_pair(dis[u[i]],u[i]));
			Q.push(make_pair(dis[v[i]],v[i]));
			Dijkstra();
			if (dis[t] <= L)
			{
				w[i] = 1 + L - dis[t];
				for (int j = i + 1;j <= m;j++)
					if (!w[j])
						w[j] = L + 1;
				puts("YES");
				for (int j = 1;j <= m;j++)
					printf("%d %d %d\n",u[j] - 1,v[j] - 1,w[j]);
				return 0;
			}
		}
	puts("NO");
	return 0;
}