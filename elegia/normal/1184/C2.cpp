#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;

const int MAXN = 200005;
const int BASE = 2000002;

struct Query
{
	int x,l,v;
	Query (int a = 0,int b = 0,int c = 0)
	{
		x = a;
		l = b;
		v = c;
	}
	bool operator < (const Query &p)const
	{
		return x == p.x ? v < p.v : x < p.x;
	}
}event[MAXN << 1];

struct Node
{
	int lch,rch;
	int MAX,laz;
}node[15000005];

int n,r,id,root,ans,tot;

void add(int o,int v)
{
	node[o].MAX += v;
	node[o].laz += v;
}

void pushdown(int o)
{
	if (node[o].laz)
	{
		add(node[o].lch,node[o].laz);
		add(node[o].rch,node[o].laz);
		node[o].laz = 0;
	}
}

int modify(int o,int l,int r,int x,int y,int v)
{
	if (!o)
		o = ++id;
	if (l >= x && r <= y)
	{
		add(o,v);
		return o;
	}
	if (!node[o].lch)
		node[o].lch = ++id;
	if (!node[o].rch)
		node[o].rch = ++id;
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		node[o].lch = modify(node[o].lch,l,mid,x,y,v);
	if (mid + 1 <= y)
		node[o].rch = modify(node[o].rch,mid + 1,r,x,y,v);
	node[o].MAX = max(node[node[o].lch].MAX,node[node[o].rch].MAX);
	return o;
}

int main()
{
	scanf("%d%d",&n,&r);
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		int X = x + y,Y = x - y;
		event[++tot] = Query(X,Y,1);
		event[++tot] = Query(X + 2 * r + 1,Y,-1);
	}
	sort(event + 1,event + tot + 1);
	for (int i = 1;i <= tot;i++)
	{
		root = modify(1,-1e7,1e7,event[i].l - r,event[i].l + r,event[i].v);
		ans = max(ans,node[root].MAX);
	}
	printf("%d\n",ans);
	return 0;
}