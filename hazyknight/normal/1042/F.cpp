#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 1000005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,k,id;
int first[MAXN];
int degree[MAXN];
int size[MAXN];

priority_queue<int,vector<int>,greater<int> > Q[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	degree[v]++;
	first[u] = id;
}

void dfs(int now,int fa,int depth)
{
	int MAX = 0;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,now,depth + 1);
			if (Q[edge[i].to].size() > Q[MAX].size())
				MAX = edge[i].to;
		}
	if (!MAX)
	{
		Q[now].push(depth);
		return;
	}
	swap(Q[now],Q[MAX]);
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && edge[i].to != MAX)
			while (!Q[edge[i].to].empty())
			{
				Q[now].push(Q[edge[i].to].top());
				Q[edge[i].to].pop();
			}
	int last = Q[now].top();
	Q[now].pop();
	while (!Q[now].empty() && Q[now].top() + last - 2 * depth <= k)
	{
		last = Q[now].top();
		Q[now].pop();
	}
	Q[now].push(last);
}

int main()
{
	read(n),read(k);
	for (int u,v,i = 1;i < n;i++)
	{
		read(u),read(v);
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		if (degree[i] > 1)
		{
			dfs(i,0,0);
			printf("%d\n",Q[i].size());
			return 0;
		}
	return 0;
}