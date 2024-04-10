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

const int MAXN = 755;
const int MAXL = 10000005;
const int INF = (1 << 30) - 1;

struct Node
{
	int ch[2];
	int len,par;
	bool flag;
}node[MAXL << 1];

struct Edge
{
	int to;
	int cap;
	int nxt;
}edge[MAXN * MAXN << 2];

int n,lst = 1,id = 1,ID = 1,S,T;
int ed[MAXN];
int pre[MAXL << 1];
int dis[MAXN << 1];
int cur[MAXN << 1];
int first[MAXN << 1];

bool vis[MAXN << 1];
bool G[MAXN << 1][MAXN << 1];

char str[MAXL];

pair<string,int> s[MAXN];

queue<int> Q;

bool cmp(const pair<string,int> &a,const pair<string,int> &b)
{
	return a.first.size() > b.first.size();
}

void addE(int u,int v)
{
	if (G[u][v])
		return;
	G[u][v] = 1;
	edge[++ID] = (Edge){v,1,first[u]};
	first[u] = ID;
	edge[++ID] = (Edge){u,0,first[v]};
	first[v] = ID;
}

void extend(int c,int cur)
{
	int np = ++id,p = lst;
	node[np].len = node[p].len + 1;
	while (p && !node[p].ch[c])
	{
		node[p].ch[c] = np;
		p = node[p].par;
	}
	if (!p)
		node[np].par = 1;
	else
	{
		int q = node[p].ch[c];
		if (node[q].len == node[p].len + 1)
			node[np].par = q;
		else
		{
			int nq = ++id;
			node[nq].len = node[p].len + 1;
			memcpy(node[nq].ch,node[q].ch,sizeof(node[q].ch));
			node[nq].par = node[q].par;
			node[q].par = node[np].par = nq;
			while (p && node[p].ch[c] == q)
			{
				node[p].ch[c] = nq;
				p = node[p].par;
			}
		}
	}
	lst = np;
}

void go(int u)
{
	if (!u)
	{
		pre[u] = 0;
		return;
	}
	if (~pre[u])
		return;
	go(node[u].par);
	pre[u] = node[node[u].par].flag ? node[u].par : pre[node[u].par];
}

void jump(int cur,int i)
{
	if (!cur || node[cur].len == i)
		return;
	jump(pre[cur],i);
	node[cur].len = i;
	if (node[cur].flag)
		for (int k = 1;k <= n;k++)
			if (k != i && ed[k] == cur)
				addE(i << 1,k << 1 | 1);
}

bool bfs()
{
	memset(dis,-1,sizeof(dis));
	Q.push(S);
	dis[S] = 0;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap > 0 && dis[edge[i].to] == -1)
			{
				dis[edge[i].to] = dis[u] + 1;
				Q.push(edge[i].to);
			}
	}
	return ~dis[T];
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	int res = 0;
	for (int &i = cur[u];i;i = edge[i].nxt)
		if (edge[i].cap > 0 && dis[edge[i].to] == dis[u] + 1)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}

int Dinic()
{
	int res = 0;
	memcpy(cur,first,sizeof(cur));
	while (bfs())
	{
		while (int tot = dfs(S,INF))
		{
			res += tot;
			memcpy(cur,first,sizeof(cur));
		}
		memcpy(cur,first,sizeof(cur));
	}
	return res;
}

void work(int u)
{
	if (vis[u])
		return;
	vis[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].cap > 0)
			work(edge[i].to);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",str);
		int l = strlen(str);
		s[i].first.resize(l);
		s[i].second = i;
		for (int j = 0;j < l;j++)
			s[i].first[j] = str[j];
	}
	sort(s + 1,s + n + 1,cmp);
	S = 1,T = (n + 1) << 1;
	for (int i = 1;i <= n;i++)
	{
		int cur = 1;
		for (int j = 0;j < s[i].first.size();j++)
		{
			if (!node[cur].ch[s[i].first[j] - 'a'])
			{
				cur = -1;
				break;
			}
			cur = node[cur].ch[s[i].first[j] - 'a'];
		}
		if (~(ed[i] = cur))
			node[cur].flag = 1;
		lst = 1;
		for (int j = 0;j < s[i].first.size();j++)
			extend(s[i].first[j] - 'a',i);
	}
	memset(pre,-1,sizeof(pre));
	for (int i = 1;i <= id;i++)
	{
		go(i);
		node[i].len = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		int cur = 1;
		for (int j = 0;j < s[i].first.size();j++)
		{
			cur = node[cur].ch[s[i].first[j] - 'a'];
			jump(cur,i);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		addE(S,i << 1);
		addE(i << 1 | 1,T);
	}
	printf("%d\n",n - Dinic());
	work(S);
	for (int i = 1;i <= n;i++)
		if (vis[i << 1] && !vis[i << 1 | 1])
			printf("%d ",s[i].second);
	printf("\n");
	return 0;
}