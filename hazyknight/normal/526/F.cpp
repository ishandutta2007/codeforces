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

const int MAXN = 300005;

struct Node
{
	int MIN,cnt,laz;
}node[MAXN << 2];

int n,tmin,tmax;
int a[MAXN];
int MIN[MAXN];
int MAX[MAXN];

long long ans;

void add(int o,int v)
{
	node[o].MIN += v;
	node[o].laz += v;
}

void pushdown(int o)
{
	if (node[o].laz)
	{
		add(o << 1,node[o].laz);
		add(o << 1 | 1,node[o].laz);
		node[o].laz = 0;
	}
}

void update(int o)
{
	node[o].MIN = min(node[o << 1].MIN,node[o << 1 | 1].MIN);
	node[o].cnt = (node[o << 1].MIN == node[o].MIN) * node[o << 1].cnt + (node[o << 1 | 1].MIN == node[o].MIN) * node[o << 1 | 1].cnt;
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		node[o].cnt = 1;
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	update(o);
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
	update(o);
}

int main()
{
	scanf("%d",&n);
	for (int r,c,i = 1;i <= n;i++)
	{
		scanf("%d%d",&r,&c);
		a[r] = c;
	}
	buildtree(1,1,n);
	for (int i = 1;i <= n;i++)
	{
		while (tmin && a[MIN[tmin]] > a[i])
		{
			modify(1,1,n,MIN[tmin - 1] + 1,MIN[tmin],a[MIN[tmin]]);
			tmin--;
		}
		modify(1,1,n,MIN[tmin] + 1,i,-a[i]);
		MIN[++tmin] = i;
		while (tmax && a[MAX[tmax]] < a[i])
		{
			modify(1,1,n,MAX[tmax - 1] + 1,MAX[tmax],-a[MAX[tmax]]);
			tmax--;
		}
		modify(1,1,n,MAX[tmax] + 1,i,a[i]);
		MAX[++tmax] = i;
		if (i > 1)
			modify(1,1,n,1,i - 1,-1);
		ans += node[1].cnt - n + i;
	}
	printf("%lld\n",ans);
	return 0;
}