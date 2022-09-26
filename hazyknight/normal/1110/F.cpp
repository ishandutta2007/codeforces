#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 500005;
const ll INF = (1ll << 60) - 1;

struct Query
{
	int l,r,id;
};

struct Edge
{
	int to,val;
	bool operator < (const Edge &p)const
	{
		return to < p.to;
	}
};

int n,q;
int deg[MAXN];
int L[MAXN];
int R[MAXN];

ll ans[MAXN];
ll MIN[MAXN << 2];
ll laz[MAXN << 2];

vector<Edge> e[MAXN];
vector<Query> ql[MAXN];
vector<Query> qr[MAXN];

void add(int o,ll v)
{
	laz[o] += v;
	MIN[o] += v;
}

void pushdown(int o)
{
	if (laz[o])
	{
		add(o << 1,laz[o]);
		add(o << 1 | 1,laz[o]);
		laz[o] = 0;
	}
}

void setval(int o,int l,int r,int p)
{
	if (l == r)
	{
		MIN[o] = 0;
		return;
	}
	pushdown(o);
	int mid = (l + r) >> 1;
	if (p <= mid)
		setval(o << 1,l,mid,p);
	else
		setval(o << 1| 1,mid + 1,r,p);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

void addval(int o,int l,int r,int x,int y,int v)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = (l + r) >> 1;
	if (mid >= x)
		addval(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		addval(o << 1 | 1,mid + 1,r,x,y,v);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

ll query(int o,int l,int r,int x,int y)
{
	if (x > y)
		return INF;
	if (l >= x && r <= y)
		return MIN[o];
	pushdown(o);
	int mid = (l + r) >> 1;
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	return min(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

void dfsl(int u)
{
	R[u] = u;
	if (!e[u].size())
		setval(1,1,n,u);
	for (int i = 0;i < ql[u].size();i++)
		ans[ql[u][i].id] = min(ans[ql[u][i].id],query(1,1,n,ql[u][i].l,ql[u][i].r));
	for (int i = 0;i < e[u].size();i++)
	{
		addval(1,1,n,1,R[u],e[u][i].val);
		dfsl(e[u][i].to);
		addval(1,1,n,1,R[u],-e[u][i].val);
		addval(1,1,n,R[u] + 1,R[e[u][i].to],e[u][i].val);
		R[u] = R[e[u][i].to];
	}
}

void dfsr(int u)
{
	L[u] = R[u] + 1;
	for (int i = 0;i < e[u].size();i++)
	{
		addval(1,1,n,L[u],n,e[u][i].val);
		dfsr(e[u][i].to);
		addval(1,1,n,L[u],n,-e[u][i].val);
		addval(1,1,n,L[e[u][i].to],L[u] - 1,e[u][i].val);
		L[u] = L[e[u][i].to];
	}
	for (int i = 0;i < qr[u].size();i++)
		ans[qr[u][i].id] = min(ans[qr[u][i].id],query(1,1,n,qr[u][i].l,qr[u][i].r));
	if (!e[u].size())
		setval(1,1,n,u);
	L[u] = u;
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int fa,v,i = 2;i <= n;i++)
	{
		scanf("%d%d",&fa,&v);
		e[fa].push_back((Edge){i,v});
		deg[fa]++;
		deg[i]++;
	}
	for (int x,l,r,i = 1;i <= q;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		if (x >= l && x <= r)
		{
			if (deg[x] == 1)
				continue;
			ql[x].push_back((Query){l,x - 1,i});
			qr[x].push_back((Query){x + 1,r,i});
		}
		else if (x > r)
			ql[x].push_back((Query){l,r,i});
		else
			qr[x].push_back((Query){l,r,i});
		ans[i] = INF;
	}
	for (int i = 1;i <= n;i++)
		sort(e[i].begin(),e[i].end());
	for (int i = 1;i <= (n << 2);i++)
	{
		MIN[i] = INF;
		laz[i] = 0;
	}
	dfsl(1);
	for (int i = 1;i <= n;i++)
		reverse(e[i].begin(),e[i].end());
	for (int i = 1;i <= (n << 2);i++)
	{
		MIN[i] = INF;
		laz[i] = 0;
	}
	dfsr(1);
	for (int i = 1;i <= q;i++)
		printf("%I64d\n",ans[i]);
	return 0;
}