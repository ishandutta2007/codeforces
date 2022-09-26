#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int T,n,q;
int l[MAXN];
int r[MAXN];
int sum[MAXN << 2];
int laz[MAXN << 2];

char s[MAXN];
char t[MAXN];

void buildtree(int o,int l,int r)
{
	laz[o] = -1;
	if (l == r)
	{
		sum[o] = t[l] - '0';
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void st(int o,int l,int r,int v)
{
	laz[o] = v;
	if (v)
		sum[o] = r - l + 1;
	else
		sum[o] = 0;
}

void pushdown(int o,int l,int r)
{
	if (~laz[o])
	{
		int mid = l + r >> 1;
		st(o << 1,l,mid,laz[o]);
		st(o << 1 | 1,mid + 1,r,laz[o]);
		laz[o] = -1;
	}
}

void setv(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		st(o,l,r,v);
		return;
	}
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid >= x)
		setv(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		setv(o << 1 | 1,mid + 1,r,x,y,v);
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

int query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return sum[o];
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return query(o << 1,l,mid,x,y) + query(o << 1 | 1,mid + 1,r,x,y);
}

void dfs(int o,int l,int r,bool &ok)
{
	if (l == r)
	{
		ok &= (sum[o] == s[l] - '0');
		return;
	}
	pushdown(o,l,r);
	int mid = l + r >> 1;
	dfs(o << 1,l,mid,ok);
	dfs(o << 1 | 1,mid + 1,r,ok);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%s%s",&n,&q,s + 1,t + 1);
		buildtree(1,1,n);
		for (int i = 1;i <= q;i++)
			scanf("%d%d",&l[i],&r[i]);
		bool ok = 1;
		for (int i = q;i >= 1;i--)
		{
			int cnt = query(1,1,n,l[i],r[i]),el = r[i] - l[i] + 1 - cnt;
			if (cnt == el)
				ok = 0;
			else
				setv(1,1,n,l[i],r[i],cnt > el);
		}
		dfs(1,1,n,ok);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}