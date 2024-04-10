#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;
const int MAXM = 300005;
const int INF = 1000000000;

struct Query
{
	int l,r,id;
	int ans;
}q[MAXM];

struct Node
{
	int lch,rch;
	int MAX;
}node[MAXN << 5];

int n,m,id;
int a[MAXN];
int root[MAXN];
int laz[MAXN << 2];

bool cmp1(const Query &a,const Query &b)
{
	return a.r < b.r;
}

bool cmp2(const Query &a,const Query &b)
{
	return a.id < b.id;
}

void update(int o)
{
	node[o].MAX = max(node[node[o].lch].MAX,node[node[o].rch].MAX);
}

int duplicate(int o)
{
	id++;
	node[id].lch = node[o].lch;
	node[id].rch = node[o].rch;
	node[id].MAX = node[o].MAX;
	return id;
}

int modify1(int o,int l,int r,int p,int v)
{
	o = duplicate(o);
	if (l == r)
	{
		node[o].MAX = v;
		return o;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		node[o].lch = modify1(node[o].lch,l,mid,p,v);
	else
		node[o].rch = modify1(node[o].rch,mid + 1,r,p,v);
	update(o);
	return o;
}

int query1(int o,int l,int r,int x,int y)
{
	if (!o || (l >= x && r <= y))
		return node[o].MAX;
	int mid = l + r >> 1;
	if (mid < x)
		return query1(node[o].rch,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query1(node[o].lch,l,mid,x,y);
	return max(query1(node[o].lch,l,mid,x,y),query1(node[o].rch,mid + 1,r,x,y));
}

void modify2(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		laz[o] = min(laz[o],v);
		return;
	}
	int mid = l + r >> 1;
	if (mid >= x)
		modify2(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify2(o << 1 | 1,mid + 1,r,x,y,v);
}

int query2(int o,int l,int r,int p)
{
	if (l == r)
		return laz[o];
	int mid = l + r >> 1;
	if (mid >= p)
		return min(laz[o],query2(o << 1,l,mid,p));
	return min(laz[o],query2(o << 1 | 1,mid + 1,r,p));
}

void doit()
{
	id = 0;
	memset(node,0,sizeof(node));
	for (int i = 1;i <= n << 2;i++)
		laz[i] = INF;
	for (int i = 1,j = 1;i <= n;i++)
	{
		int pre = query1(root[i - 1],0,INF,a[i],INF);
		while (pre && a[pre] >= a[i])
		{
			modify2(1,1,n,1,pre,a[pre] - a[i]);
			pre = query1(root[pre - 1],0,INF,a[i],(a[i] + a[pre] - 1) >> 1);
		}
		root[i] = modify1(root[i - 1],0,INF,a[i],i);
		while (j <= m && q[j].r == i)
		{
			q[j].ans = min(q[j].ans,query2(1,1,n,q[j].l));
			j++;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
		q[i].ans = INF;
	}
	sort(q + 1,q + m + 1,cmp1);
	doit();
	for (int i = 1;i <= m;i++)
	{
		q[i].l = n - q[i].l + 1;
		q[i].r = n - q[i].r + 1;
		swap(q[i].l,q[i].r);
	}
	sort(q + 1,q + m + 1,cmp1);
	reverse(a + 1,a + n + 1);
	doit();
	sort(q + 1,q + m + 1,cmp2);
	for (int i = 1;i <= m;i++)
		printf("%d\n",q[i].ans);
	return 0;
}