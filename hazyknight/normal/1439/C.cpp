#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n,q;
int a[MAXN];
int MAX[MAXN << 2];
int laz[MAXN << 2];

ll sum[MAXN << 2];

void update(int o)
{
	MAX[o] = MAX[o << 1];
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		MAX[o] = a[l];
		sum[o] = a[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	update(o);
}

void setv(int o,int l,int r,int v)
{
	MAX[o] = v;
	sum[o] = (ll)(r - l + 1) * v;
	laz[o] = v;
}

void pushdown(int o,int l,int r)
{
	if (!laz[o])
		return;
	int mid = l + r >> 1;
	setv(o << 1,l,mid,laz[o]);
	setv(o << 1 | 1,mid + 1,r,laz[o]);
	laz[o] = 0;
}

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		setv(o,l,r,v);
		return;
	}
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	update(o);
}

int query1(int o,int l,int r,int p)
{
	if (l == r)
		return MAX[o] <= p ? l : l + 1;
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (MAX[o << 1 | 1] <= p)
		return query1(o << 1,l,mid,p);
	return query1(o << 1 | 1,mid + 1,r,p);
}

ll query2(int o,int l,int r,int p)
{
	if (r <= p)
		return sum[o];
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid + 1 > p)
		return query2(o << 1,l,mid,p);
	return query2(o << 1,l,mid,p) + query2(o << 1 | 1,mid + 1,r,p);
}

int query3(int o,int l,int r,ll t)
{
	if (l == r)
		return sum[o] <= t ? l : l - 1;
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (sum[o << 1] <= t)
		return query3(o << 1 | 1,mid + 1,r,t - sum[o << 1]);
	return query3(o << 1,l,mid,t);
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	buildtree(1,1,n);
	while (q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (t == 1)
		{
			int l = query1(1,1,n,y);
			if (l <= x)
				modify(1,1,n,l,x,y);
		}
		else
		{
			int cnt = 0;
			x = max(x,query1(1,1,n,y));
			while (y && x <= n)
			{
				ll tar = (x == 1 ? 0 : query2(1,1,n,x - 1));
				int r = query3(1,1,n,tar + y);
				y -= query2(1,1,n,r) - tar;
				cnt += r - x + 1;
				x = max(r + 2,query1(1,1,n,y));
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}