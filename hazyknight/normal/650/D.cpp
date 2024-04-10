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

const int MAXN = 1000005;

int n,m,tot,globalans;
int h[MAXN];
int val[MAXN];
int MX[MAXN];
int F[MAXN];
int G[MAXN];
int f[MAXN];
int g[MAXN];
int a[MAXN];
int b[MAXN];
int vis[MAXN];

bool must[MAXN];

vector<pair<int,int> > q[MAXN];

void modify(int p,int v)
{
	while (p <= tot)
	{
		MX[p] = max(MX[p],v);
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res = max(res,MX[p]);
		p -= p & -p;
	}
	return res;
}

int find(int v)
{
	int low = 1,high = tot;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (val[mid] >= v)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&h[i]);
		val[++tot] = h[i];
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		val[++tot] = b[i];
	}
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= n;i++)
		h[i] = find(h[i]);
	for (int i = 1;i <= m;i++)
	{
		b[i] = find(b[i]);
		q[a[i]].push_back(make_pair(b[i],i));
	}
	for (int i = 1;i <= n;i++)
	{
		f[i] = query(h[i] - 1) + 1;
		for (int j = 0;j < q[i].size();j++)
			F[q[i][j].second] = query(q[i][j].first - 1) + 1;
		modify(h[i],f[i]);
	}
	memset(MX,0,sizeof(MX));
	for (int i = n;i >= 1;i--)
	{
		g[i] = query(tot - h[i]) + 1;
		for (int j = 0;j < q[i].size();j++)
			G[q[i][j].second] = query(tot - q[i][j].first) + 1;
		modify(tot - h[i] + 1,g[i]);
	}
	for (int i = 1;i <= n;i++)
		globalans = max(globalans,f[i] + g[i] - 1);
	for (int i = 1;i <= n;i++)
		if (f[i] + g[i] - 1 == globalans)
			vis[f[i]]++;
	for (int i = 1;i <= n;i++)
		if (f[i] + g[i] - 1 == globalans && vis[f[i]] == 1)
			must[i] = 1;
	for (int i = 1;i <= m;i++)
		printf("%d\n",max(F[i] + G[i] - 1,globalans - must[a[i]]));
	return 0;
}