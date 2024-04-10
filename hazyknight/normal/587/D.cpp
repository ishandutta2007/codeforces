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

const int MAXN = 400005;
const int MAXM = 2000005;

struct Ed
{
	int u,v,c,t,id;
	
	bool operator < (const Ed &p)const
	{
		return t < p.t;
	}
}ed[MAXN];

struct Edge
{
	int to;
	int nxt;
}edge[MAXM];

int n,m,cc,scc,id,idf;
int first[MAXN];
int dfn[MAXN];
int low[MAXN];
int bel[MAXN];
int de[MAXN];
int mark[MAXN];

bool vis[MAXN];

queue<int> Q;
stack<int> S;
vector<int> ans;
vector<int> e[MAXN];
vector<int> sc[MAXN];
map<int,int> deg[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int u,bool U,int v,bool V)
{
	addE(u << 1 | U,v << 1 | V);
	addE(v << 1 | !V,u << 1 | !U);
}

void dfs(int u)
{
	dfn[u] = low[u] = ++idf;
	vis[u] = 1;
	S.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (!dfn[edge[i].to])
		{
			dfs(edge[i].to);
			low[u] = min(low[u],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[u] = min(low[u],dfn[edge[i].to]);
	}
	if (low[u] == dfn[u])
	{
		scc++;
		while (S.top() != u)
		{
			bel[S.top()] = scc;
			vis[S.top()] = 0;
			S.pop();
		}
		bel[u] = scc;
		vis[u] = 0;
		S.pop();
	}
}

bool two_sat()
{
	memset(dfn,0,sizeof(dfn));
	idf = scc = 0;
	for (int i = 2;i <= (cc << 1 | 1);i++)
		if (!dfn[i])
			dfs(i);
	for (int i = 1;i <= cc;i++)
		if (bel[i << 1] == bel[i << 1 | 1])
			return 0;
	return 1;
}

void buildgraph()
{
	for (int i = 1;i <= n;i++)
		deg[i].clear();
	for (int i = 1;i <= m;i++)
	{
		e[ed[i].u].push_back(i);
		e[ed[i].v].push_back(i);
		int &u = deg[ed[i].u][ed[i].c];
		if (!u)
			u = i;
		else
			add(u,0,i,1);
		int &v = deg[ed[i].v][ed[i].c];
		if (!v)
			v = i;
		else
			add(v,0,i,1);
	}
	cc = m;
	for (int i = 1;i <= n;i++)
	{
		if (!e[i].size())
			continue;
		int p = e[i][0];
		for (int j = 1;j < e[i].size();j++)
		{
			int u = e[i][j],v = ++cc;
			add(p,1,v,1);
			add(u,1,v,1);
			add(p,1,u,0);
			p = v;
		}
	}
}

bool check(int v)
{
	int tmp = id;
	for (int i = m;i >= 1 && ed[i].t > v;i--)
		addE(i << 1 | 1,i << 1);
	bool res = two_sat();
	id = tmp;
	for (int i = m;i >= 1 && ed[i].t > v;i--)
		first[i << 1 | 1] = edge[first[i << 1 | 1]].nxt;
	return res;
}

void construct(int v)
{
	for (int i = m;i >= 1 && ed[i].t > v;i--)
		addE(i << 1 | 1,i << 1);
	two_sat();
	for (int i = 1;i <= (cc << 1 | 1);i++)
		sc[bel[i]].push_back(i);
	for (int i = 1;i <= scc;i++)
		e[i].clear();
	for (int i = 1;i <= (cc << 1 | 1);i++)
		for (int j = first[i];j;j = edge[j].nxt)
			if (bel[i] != bel[edge[j].to])
			{
				e[bel[edge[j].to]].push_back(bel[i]);
				de[bel[i]]++;
			}
	memset(mark,-1,sizeof(mark));
	for (int i = 1;i <= scc;i++)
		if (!de[i])
			Q.push(i);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (mark[u] == -1)
			mark[u] = 1;
		for (int i = 0;i < sc[u].size();i++)
			mark[bel[sc[u][i] ^ 1]] = mark[u] ^ 1;
		for (int i = 0;i < e[u].size();i++)
			if (!--de[e[u][i]])
				Q.push(e[u][i]);
	}
	for (int i = 1;i <= m;i++)
		if (mark[bel[i << 1 | 1]])
			ans.push_back(i);
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d ",ed[ans[i]].id);
	printf("\n");
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d%d",&ed[i].u,&ed[i].v,&ed[i].c,&ed[i].t);
		ed[i].id = i;
		if (++deg[ed[i].u][ed[i].c] > 2 || ++deg[ed[i].v][ed[i].c] > 2)
		{
			puts("No");
			return 0;
		}
	}
	sort(ed + 1,ed + m + 1);
	buildgraph();
	if (!check(1000000000))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int low = 0,high = 1000000000;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%d ",low);
	construct(low);
	return 0;
}