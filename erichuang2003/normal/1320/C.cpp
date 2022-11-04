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

#define int long long

using namespace std;

const int MAXN = 400005;
const int INF = 1e12 + 1;

int n,m,p,tot,ans;
int val[MAXN << 1];
int MAX[MAXN << 3];
int laz[MAXN << 3];
int x[MAXN];
int y[MAXN];
int z[MAXN];
int vis[MAXN << 1];

pair<int,int> a[MAXN];
pair<int,int> b[MAXN];
pair<int,int> c[MAXN];
map<int,int> match;

void add(int o,int v)
{
	MAX[o] += v;
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
	MAX[o] = max(MAX[o << 1],MAX[o << 1 | 1]);
}

signed main()
{
	scanf("%d%d%d",&n,&m,&p);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&b[i].first,&b[i].second);
		val[++tot] = b[i].first;
	}
	for (int i = 1;i <= p;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		val[++tot] = y[i];
		c[i] = make_pair(x[i],i);
	}
	sort(a + 1,a + n + 1);
	sort(c + 1,c + p + 1);
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= tot;i++)
		match[val[i]] = i;
	for (int i = 1;i <= (tot << 2);i++)
		MAX[i] = -INF;
	memset(vis,-1,sizeof(vis));
	for (int i = 1;i <= m;i++)
	{
		b[i].first = match[b[i].first];
		if (~vis[b[i].first])
		{
			if (b[i].second >= vis[b[i].first])
				continue;
			modify(1,1,tot,b[i].first,b[i].first,vis[b[i].first] - b[i].second);
			vis[b[i].first] = b[i].second;
			continue;
		}
		vis[b[i].first] = b[i].second;
		modify(1,1,tot,b[i].first,b[i].first,INF - b[i].second);
	}
	ans = -INF;
	for (int i = 1,j = 1;i <= n;i++)
	{
		while (j <= p && c[j].first < a[i].first)
		{
			int id = c[j].second;
			y[id] = match[y[id]];
			if (y[id] < tot)
				modify(1,1,tot,y[id] + 1,tot,z[id]);
			j++;
		}
		ans = max(ans,MAX[1] - a[i].second);
	}
	printf("%d\n",ans);
	return 0;
}