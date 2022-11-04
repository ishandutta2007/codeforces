#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int n,q;
int a[MAXN];
int MIN[MAXN << 2];
int sum[MAXN];
int ans[MAXN];
int l[MAXN];
int r[MAXN];
int laz[MAXN << 2];

vector<int> Q[MAXN];

void mdf(int p)
{
	while (p <= n)
	{
		sum[p]++;
		p += p & -p;
	}
}

int qry(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		MIN[o] = a[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

void add(int o,int v)
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

void modify(int o,int l,int r,int p)
{
	if (l == r)
	{
		MIN[o] = 1e9;
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= p)
		modify(o << 1,l,mid,p);
	else
		modify(o << 1 | 1,mid + 1,r,p);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

void modify2(int o,int l,int r,int p)
{
	if (l >= p)
	{
		add(o,-1);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= p)
		modify2(o << 1,l,mid,p);
	modify2(o << 1 | 1,mid + 1,r,p);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int query(int o,int l,int r,int p)
{
	if (r < p || MIN[o] > 0)
		return n + 1;
	if (l == r)
		return l;
	pushdown(o);
	int mid = l + r >> 1;
	int L = query(o << 1,l,mid,p);
	if (L < n + 1)
		return L;
	return query(o << 1 | 1,mid + 1,r,p);
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		a[i] = i - a[i];
		if (a[i] < 0)
			a[i] = 1e9;
	}
	buildtree(1,1,n);
	for (int i = 1;i <= q;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		l[i]++;
		r[i] = n - r[i];
		Q[l[i]].push_back(i);
	}
	for (int i = n;i >= 1;i--)
	{
		if (!a[i])
		{
			int cur = i;
			while (cur <= n)
			{
				mdf(cur);
				modify(1,1,n,cur);
				if (cur < n)
					modify2(1,1,n,cur + 1);
				int nxt = query(1,1,n,cur + 1);
				cur = nxt;
			}
		}
		for (int j = 0;j < Q[i].size();j++)
			ans[Q[i][j]] = qry(r[Q[i][j]]);
	}
	for (int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}