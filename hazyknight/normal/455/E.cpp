#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;
const int INF = (1 << 30) - 1;

int n,m;
int a[MAXN];
int k[MAXN];
int b[MAXN];
int ans[MAXN];
int sum[MAXN];
int optk[MAXN << 2];
int optb[MAXN << 2];

vector<pair<int,int> > qry[MAXN];

void modify(int o,int l,int r,int x,int y,int k,int b)
{
	int mid = l + r >> 1;
	if (l >= x && r <= y)
	{
		int curvl = k * l + b,curvr = k * r + b;
		int optvl = optk[o] * l + optb[o],optvr = optk[o] * r + optb[o];
		if (curvl <= optvl && curvr <= optvr)
		{
			optk[o] = k;
			optb[o] = b;
			return;
		}
		if (curvl >= optvl && curvr >= optvr)
			return;
		int curvm = k * mid + b;
		int optvm = optk[o] * mid + optb[o];
		if (curvm < optvm)
		{
			swap(k,optk[o]);
			swap(b,optb[o]);
		}
		modify(o << 1,l,mid,x,y,k,b);
		modify(o << 1 | 1,mid + 1,r,x,y,k,b);
		return;
	}
	if (mid >= x)
		modify(o << 1,l,mid,x,y,k,b);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,k,b);
}

int query(int o,int l,int r,int p)
{
	int res = optk[o] * p + optb[o];
	if (l == r)
		return res;
	int mid = l + r >> 1;
	if (mid >= p)
		return min(res,query(o << 1,l,mid,p));
	return min(res,query(o << 1 | 1,mid + 1,r,p));
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= (n << 2);i++)
		optb[i] = INF;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		b[i] = (i + 1) * a[i] - sum[i];
		k[i] = -a[i];
	}
	scanf("%d",&m);
	for (int l,r,i = 1;i <= m;i++)
	{
		scanf("%d%d",&l,&r);
		ans[i] = sum[r];
		qry[r].push_back(make_pair(r - l + 1,i));
	}
	for (int i = 1;i <= n;i++)
	{
		modify(1,1,n,1,i,k[i],b[i]);
		for (int j = 0;j < qry[i].size();j++)
			ans[qry[i][j].second] += query(1,1,n,qry[i][j].first);
	}
	for (int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}