#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 1000005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN];

struct Set
{
	priority_queue<int > Q,rQ;
	
	void insert(int a)
	{
		Q.push(a);
	}
	
	void erase(int a)
	{
		rQ.push(a);
	}
	
	int MAX()
	{
		while (!rQ.empty() && Q.top() == rQ.top())
		{
			Q.pop();
			rQ.pop();
		}
		return Q.top();
	}
}S[MAXN];

int n,m,id,s,t;
int dis[MAXN];
int first[MAXN];

bool mark[MAXN];

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(v,u,1e9);
		S[u].insert(1e9);
	}
	scanf("%d%d",&s,&t);
	for (int i = 1;i <= n;i++)
		dis[i] = 1e9;
	dis[t] = 0;
	Q.push(make_pair(0,t));
	while (!Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		if (mark[u])
			continue;
		mark[u] = 1;
		for (int i = first[u];i;i = edge[i].nxt)
		{
			int v = edge[i].to;
			S[v].erase(edge[i].w);
			S[v].insert(edge[i].w = dis[u]);
			if (min(S[v].MAX(),dis[u] + 1) < dis[v])
			{
				dis[v] = min(S[v].MAX(),dis[u] + 1);
				Q.push(make_pair(dis[v],v));
			}
		}
	}
	printf("%d\n",(dis[s] == 1e9 ? -1 : dis[s]));
	return 0;
}