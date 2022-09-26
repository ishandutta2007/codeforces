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

const int MAXN = 500005;
const int MAXM = 100005;

struct Node
{
	int ch[26];
	int len,par;
}node[MAXM];

struct TNode
{
	int lch,rch;
	pair<int,int> MAX;
}nd[MAXM * 20];

struct Query
{
	int l,r,id;
};

int n,m,q,lst,id = 1;
int rt[MAXM];
int pos[MAXN];
int dis[MAXN];
int fa[MAXM][16];

char s[MAXN];
char t[MAXM];

pair<int,int> ans[MAXN];

vector<int> e[MAXM];
vector<int> add[MAXM];
vector<char> S[MAXM];
vector<Query> tag[MAXM];

void extend(int c)
{
	int p = lst;
	if (node[p].ch[c] && node[node[p].ch[c]].len == node[p].len + 1)
	{
		lst = node[p].ch[c];
		return;
	}
	int np = ++id;
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
	for (int i = 1;i <= 15;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0;i < e[u].size();i++)
		dfs(e[u][i]);
}

pair<int,int> Max(pair<int,int> a,pair<int,int> b)
{
	if (a.second == b.second)
		return a.first < b.first ? a : b;
	return a.second > b.second ? a : b;
}

int merge(int u,int v,int l,int r)
{
	if (!u || !v)
		return u | v;
	if (l == r)
	{
		nd[u].MAX.second += nd[v].MAX.second;
		return u;
	}
	int mid = l + r >> 1;
	nd[u].lch = merge(nd[u].lch,nd[v].lch,l,mid);
	nd[u].rch = merge(nd[u].rch,nd[v].rch,mid + 1,r);
	nd[u].MAX = Max(nd[nd[u].lch].MAX,nd[nd[u].rch].MAX);
	return u;
}

int modify(int u,int l,int r,int p)
{
	if (!u)
		u = ++id;
	if (l == r)
	{
		nd[u].MAX.first = l;
		nd[u].MAX.second++;
		return u;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		nd[u].lch = modify(nd[u].lch,l,mid,p);
	else
		nd[u].rch = modify(nd[u].rch,mid + 1,r,p);
	nd[u].MAX = Max(nd[nd[u].lch].MAX,nd[nd[u].rch].MAX);
	return u;
}

pair<int,int> query(int u,int l,int r,int x,int y)
{
	if (!u)
		return make_pair(x,0);
	if (l >= x && r <= y)
		return nd[u].MAX;
	int mid = l + r >> 1;
	if (mid < x)
		return query(nd[u].rch,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(nd[u].lch,l,mid,x,y);
	return Max(query(nd[u].lch,l,mid,x,y),query(nd[u].rch,mid + 1,r,x,y));
}

void solve(int u)
{
	for (int i = 0;i < e[u].size();i++)
	{
		solve(e[u][i]);
		rt[u] = merge(rt[u],rt[e[u][i]],1,m);
	}
	for (int i = 0;i < add[u].size();i++)
		rt[u] = modify(rt[u],1,m,add[u][i]);
	for (int i = 0;i < tag[u].size();i++)
		ans[tag[u][i].id] = query(rt[u],1,m,tag[u][i].l,tag[u][i].r);
}

int main()
{
	scanf("%s%d",s + 1,&m);
	n = strlen(s + 1);
	for (int i = 1;i <= m;i++)
	{
		scanf("%s",t + 1);
		int l = strlen(t + 1);
		S[i].resize(l + 1);
		lst = 1;
		for (int j = 1;j <= l;j++)
		{
			S[i][j] = t[j];
			extend(t[j] - 'a');
		}
	}
	int cur = 1,len = 0;
	for (int i = 1;i <= n;i++)
	{
		while (cur && !node[cur].ch[s[i] - 'a'])
		{
			cur = node[cur].par;
			len = node[cur].len;
		}
		if (!cur)
			cur = 1;
		else
		{
			cur = node[cur].ch[s[i] - 'a'];
			len++;
		}
		pos[i] = cur;
		dis[i] = len;
	}
	for (int i = 2;i <= id;i++)
	{
		e[node[i].par].push_back(i);
		fa[i][0] = node[i].par;
	}
	dfs(1);
	scanf("%d",&q);
	for (int l,r,pl,pr,i = 1;i <= q;i++)
	{
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		int cur = pos[pr],len = dis[pr];
		if (len < pr - pl + 1)
		{
			ans[i].first = l;
			continue;
		}
		for (int j = 15;j >= 0;j--)
			if (fa[cur][j] && node[fa[cur][j]].len >= pr - pl + 1)
				cur = fa[cur][j];
		tag[cur].push_back((Query){l,r,i});
	}
	for (int i = 1;i <= m;i++)
	{
		int cur = 1;
		for (int j = 1;j < S[i].size();j++)
		{
			cur = node[cur].ch[S[i][j] - 'a'];
			add[cur].push_back(i);
		}
	}
	id = 0;
	nd[0].MAX.first = 1e9;
	solve(1);
	for (int i = 1;i <= q;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}