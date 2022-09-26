#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
 
struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];
 
int T,n,id,ans,cur;
int a[MAXN];
int R[MAXN];
int dfn[MAXN];
int first[MAXN];
int mark[MAXN];
int laz[MAXN << 2];
 
void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u)
{
	dfn[u] = ++id;
	for (int i = first[u];i;i = edge[i].nxt)
		dfs1(edge[i].to);
	R[u] = id;
}

void col(int o,int c)
{
	laz[o] = c;
}

void pushdown(int o)
{
	if (~laz[o])
	{
		col(o << 1,laz[o]);
		col(o << 1 | 1,laz[o]);
		laz[o] = -1;
	}
}

void modify(int o,int l,int r,int x,int y,int c)
{
	if (l >= x && r <= y)
	{
		col(o,c);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,c);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,c);
}

int query(int o,int l,int r,int p)
{
	if (l == r)
		return laz[o];
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= p)
		return query(o << 1,l,mid,p);
	return query(o << 1 | 1,mid + 1,r,p);
}

void add(int u)
{
	int c = query(1,1,n,dfn[u]);
	if (c > 0)
	{
		mark[u] = c;
		modify(1,1,n,dfn[c],R[c],0);
		cur--;
	}
	modify(1,1,n,dfn[u],R[u],u);
	cur++;
}

void sub(int u)
{
	modify(1,1,n,dfn[u],R[u],0);
	cur--;
	if (mark[u])
	{
		int v = mark[u];
		modify(1,1,n,dfn[v],R[v],v);
		cur++;
	}
}

void dfs2(int u)
{
	add(u);
	ans = max(ans,cur);
	for (int i = first[u];i;i = edge[i].nxt)
		dfs2(edge[i].to);
	sub(u);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = mark[i] = 0;
		for (int i = 1;i <= (n << 2);i++)
			laz[i] = -1;
		for (int i = 2;i <= n;i++)
			scanf("%d",&a[i]);
		for (int b,i = 2;i <= n;i++)
		{
			scanf("%d",&b);
			addE(b,i);
		}
		id = 0;
		dfs1(1);
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		for (int i = 2;i <= n;i++)
			addE(a[i],i);
		ans = 0;
		dfs2(1);
		printf("%d\n",ans);
	}
	return 0;
}