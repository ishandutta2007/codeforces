#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

namespace ST
{

struct Node
{
	int lch,rch,sum;
}node[MAXN * 20];

int id;
int rt[MAXN];

int insert(int o,int l,int r,int p)
{
	o = ++id;
	node[o].sum = 1;
	if (l == r)
		return o;
	int mid = l + r >> 1;
	if (mid >= p)
		node[o].lch = insert(o << 1,l,mid,p);
	else
		node[o].rch = insert(o << 1 | 1,mid + 1,r,p);
	return o;
}

int merge(int u,int v,int l,int r)
{
	if (!u || !v)
		return u | v;
	if (l == r)
		return u;
	int mid = l + r >> 1;
	int cur = ++id;
	node[cur].lch = merge(node[u].lch,node[v].lch,l,mid);
	node[cur].rch = merge(node[u].rch,node[v].rch,mid + 1,r);
	node[cur].sum = node[node[cur].lch].sum + node[node[cur].rch].sum;
	return cur;
}

int query(int o,int l,int r,int x,int y)
{
	if (!o)
		return 0;
	if (l >= x && r <= y)
		return node[o].sum;
	int mid = l + r >> 1;
	if (mid < x)
		return query(node[o].rch,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(node[o].lch,l,mid,x,y);
	return query(node[o].lch,l,mid,x,y) + query(node[o].rch,mid + 1,r,x,y);
}

}

struct Node
{
	int ch[26];
	int par,len,pos,MAXr;
}node[MAXN];

int n,id = 1,lst = 1,ans,K;
int fa[MAXN][19];

char s[MAXN];

vector<int> e[MAXN];

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
	for (int i = 1;i <= 18;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	if (node[u].pos)
		ST::rt[u] = ST::insert(ST::rt[u],1,n,node[u].pos);
	node[u].MAXr = node[u].pos;
	for (int i = 0;i < e[u].size();i++)
	{
		fa[e[u][i]][0] = u;
		dfs(e[u][i]);
		node[u].MAXr = max(node[u].MAXr,node[e[u][i]].MAXr);
		ST::rt[u] = ST::merge(ST::rt[u],ST::rt[e[u][i]],1,n);
	}
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
	K = 2;
	for (int i = 1;i <= n;i++)
		extend(s[i] - 'a');
	int cur = 1;
	for (int i = 1;i <= n;i++)
	{
		cur = node[cur].ch[s[i] - 'a'];
		node[cur].pos = i;
	}
	for (int i = 2;i <= id;i++)
		e[node[i].par].push_back(i);
	dfs(1);
	for (int i = 1;i <= id;i++)
		e[i].clear();
	for (int i = 2;i <= id;i++)
	{
		int u = i;
		for (int j = 18;j >= 0;j--)
			if (fa[u][j] > 1 && ST::query(ST::rt[fa[u][j]],1,n,node[i].MAXr - node[i].len + node[fa[u][j]].len,node[i].MAXr) < K)
				u = fa[u][j];
		u = fa[u][0];
		e[u].push_back(i);
	}
	down(1,0);
	printf("%d\n",ans);
	return 0;
}