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

struct Node
{
	int ch[26];
	int par,len,MAXr;
}node[MAXN];

int n,id = 1,lst = 1,ans;
int dfn[MAXN];
int R[MAXN];
int ed[MAXN];
int MAX[MAXN << 2];
int fa[MAXN][19];

char s[MAXN];

vector<int> e[MAXN];
vector<int> t[MAXN];
vector<int> q[MAXN];

void modify(int o,int l,int r,int p,int v)
{
	MAX[o] = v;
	if (l == r)
		return;
	int mid = l + r >> 1;
	if (mid >= p)
		modify(o << 1,l,mid,p,v);
	else
		modify(o << 1 | 1,mid + 1,r,p,v);
}

int query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return MAX[o];
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return max(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

void extend(int c)
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

void dfs(int u)
{
	dfn[u] = ++id;
	for (int i = 1;i <= 18;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0;i < e[u].size();i++)
	{
		fa[e[u][i]][0] = u;
		dfs(e[u][i]);
		node[u].MAXr = max(node[u].MAXr,node[e[u][i]].MAXr);
	}
	R[u] = id;
}

void down(int u,int d)
{
	ans = max(ans,d);
	for (int i = 0;i < e[u].size();i++)
		down(e[u][i],d + 1);
}

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 1;i <= n;i++)
		extend(s[i] - 'a');
	int N = id,cur = 1;
	for (int i = 1;i <= n;i++)
	{
		cur = node[cur].ch[s[i] - 'a'];
		node[cur].MAXr = i;
		ed[i] = cur;
	}
	id = 0;
	for (int i = 2;i <= N;i++)
		e[node[i].par].push_back(i);
	dfs(1);
	for (int i = 2;i <= N;i++)
		t[node[i].len].push_back(i);
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < t[i].size();j++)
			q[node[t[i][j]].MAXr].push_back(t[i][j]);
	for (int i = 1;i <= N;i++)
		e[i].clear();
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < q[i].size();j++)
		{
			int u = q[i][j],v = q[i][j];
			for (int k = 18;k >= 0;k--)
				if (fa[v][k] && query(1,1,N,dfn[fa[v][k]],R[fa[v][k]]) - node[fa[v][k]].len + 1 < i - node[u].len + 1)
					v = fa[v][k];
			v = fa[v][0];
			e[v].push_back(u);
		}
		modify(1,1,N,dfn[ed[i]],i);
	}
	down(1,0);
	printf("%d\n",ans);
	return 0;
}