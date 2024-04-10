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

const int END = 1000000;
const int MAXN = END + 5;

int n,m,q;
int a[MAXN];
int b[MAXN];
int MIN[MAXN << 2];
int laz[MAXN << 2];

void add(int o,int v)
{
	MIN[o] += v;
	laz[o] += v;
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

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int query(int o,int l,int r,int v)
{
	if (l == r)
	{
		if (MIN[o] >= v)
			return l;
		return -1;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (MIN[o << 1 | 1] < v)
		return query(o << 1 | 1,mid + 1,r,v);
	int res = query(o << 1,l,mid,v);
	if (~res)
		return res;
	return mid + 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		modify(1,0,END,a[i],END,1);
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&b[i]);
		modify(1,0,END,b[i],END,-1);
	}
	scanf("%d",&q);
	for (int tp,id,v,i = 1;i <= q;i++)
	{
		scanf("%d%d%d",&tp,&id,&v);
		if (tp == 1)
		{
			modify(1,0,END,a[id],END,-1);
			a[id] = v;
			modify(1,0,END,a[id],END,1);
		}
		else
		{
			modify(1,0,END,b[id],END,1);
			b[id] = v;
			modify(1,0,END,b[id],END,-1);
		}
		int res = query(1,0,END,n - m);
		printf("%d\n",res ? res : -1);
	}
	return 0;
}