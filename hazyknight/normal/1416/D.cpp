#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n,m,q,id,cc,OD;
int w[MAXN];
int u[MAXN];
int v[MAXN];
int tp[MAXN];
int x[MAXN];
int L[MAXN];
int R[MAXN];
int ch[MAXN][2];
int fa[MAXN][20];
int pre[MAXN];
int tim[MAXN];
int od[MAXN];
int MAX[MAXN << 2];

bool vis[MAXN];

int Max(int a,int b)
{
	return w[a] > w[b] ? a : b;
}

int getroot(int u)
{
	return u == pre[u] ? u : pre[u] = getroot(pre[u]);
}

void modify(int o,int l,int r,int p,int v)
{
	if (l == r)
	{
		MAX[o] = v;
		return;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		modify(o << 1,l,mid,p,v);
	else
		modify(o << 1 | 1,mid + 1,r,p,v);
	MAX[o] = Max(MAX[o << 1],MAX[o << 1 | 1]);
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
	return Max(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

void dfs(int u)
{
	if (u <= n)
	{
		L[u] = R[u] = ++cc;
		od[u] = ++OD;
		modify(1,1,n,OD,u);
		return;
	}
	L[u] = cc + 1;
	dfs(ch[u][0]);
	dfs(ch[u][1]);
	R[u] = cc;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&w[i]);
	for (int i = 1;i <= m;i++)
		scanf("%d%d",&u[i],&v[i]);
	for (int i = 1;i <= q;i++)
	{
		scanf("%d%d",&tp[i],&x[i]);
		if (tp[i] == 2)
			vis[x[i]] = 1;
	}
	for (int i = 1;i <= n;i++)
	{
		pre[i] = i;
		tim[i] = q + 1;
	}
	id = n;
	for (int i = 1;i <= m;i++)
	{
		if (vis[i])
			continue;
		int ru = getroot(u[i]),rv = getroot(v[i]);
		if (ru != rv)
		{
			tim[++id] = q + 1;
			pre[ru] = id;
			pre[rv] = id;
			pre[id] = id;
			ch[id][0] = ru;
			ch[id][1] = rv;
			fa[ru][0] = id;
			fa[rv][0] = id;
		}
	}
	for (int i = q;i >= 1;i--)
	{
		if (tp[i] == 2)
		{
			int ru = getroot(u[x[i]]),rv = getroot(v[x[i]]);
			if (ru != rv)
			{
				tim[++id] = i;
				pre[ru] = id;
				pre[rv] = id;
				pre[id] = id;
				ch[id][0] = ru;
				ch[id][1] = rv;
				fa[ru][0] = id;
				fa[rv][0] = id;
			}
		}
	}
	for (int i = id;i >= 1;i--)
		for (int j = 1;j <= 19;j++)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	for (int i = 1;i <= id;i++)
		if (!fa[i][0])
			dfs(i);
	for (int i = 1;i <= q;i++)
		if (tp[i] == 1)
		{
			int cur = x[i];
			for (int j = 19;j >= 0;j--)
				if (fa[cur][j] && tim[fa[cur][j]] >= i)
					cur = fa[cur][j];
			int ans = query(1,1,n,L[cur],R[cur]);
			printf("%d\n",w[ans]);
			w[ans] = 0;
			modify(1,1,n,od[ans],ans);
		}
	return 0;
}