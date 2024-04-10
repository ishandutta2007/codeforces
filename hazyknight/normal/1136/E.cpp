#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = 1ll << 60;

int n,q;

ll a[MAXN];
ll k[MAXN];
ll sum1[MAXN];
ll sum2[MAXN];
ll MAX[MAXN << 2];
ll sum[MAXN << 2];
ll laz[MAXN << 2];

void pushup(int o)
{
	MAX[o] = max(MAX[o << 1],MAX[o << 1 | 1]);
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void tag(int o,int l,int r,ll v)
{
	MAX[o] = laz[o] = v;
	sum[o] = v * (r - l + 1);
}

void pushdown(int o,int l,int r)
{
	if (laz[o] != -INF)
	{
		int mid = l + r >> 1;
		tag(o << 1,l,mid,laz[o]);
		tag(o << 1 | 1,mid + 1,r,laz[o]);
		laz[o] = -INF;
	}
}

void buildtree(int o,int l,int r)
{
	laz[o] = -INF;
	if (l == r)
	{
		MAX[o] = sum[o] = a[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	pushup(o);
}

void Setv(int o,int l,int r,int x,int y,ll v)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
		tag(o,l,r,v);
		return;
	}
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid >= x)
		Setv(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		Setv(o << 1 | 1,mid + 1,r,x,y,v);
	pushup(o);
}

ll Qmax(int o,int l,int r,int x,int y)
{
	if (x > y)
		return -INF;
	if (l >= x && r <= y)
		return MAX[o];
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid < x)
		return Qmax(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return Qmax(o << 1,l,mid,x,y);
	return max(Qmax(o << 1,l,mid,x,y),Qmax(o << 1 | 1,mid + 1,r,x,y));
}

ll Qsum(int o,int l,int r,int x,int y)
{
	if (x > y)
		return 0;
	if (l >= x && r <= y)
		return sum[o];
	pushdown(o,l,r);
	int mid = l + r >> 1;
	if (mid < x)
		return Qsum(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return Qsum(o << 1,l,mid,x,y);
	return Qsum(o << 1,l,mid,x,y) + Qsum(o << 1 | 1,mid + 1,r,x,y);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for (int i = 1;i < n;i++)
	{
		scanf("%lld",&k[i]);
		sum1[i] = sum1[i - 1] + k[i];
		a[i + 1] -= sum1[i];
		sum2[i] = sum2[i - 1] + sum1[i];
	}
	buildtree(1,1,n);
	scanf("%d",&q);
	for (int u,v,i = 1;i <= q;i++)
	{
		char tp = getchar();
		while (tp != '+' && tp != 's')
			tp = getchar();
		scanf("%d%d",&u,&v);
		if (tp == '+')
		{
			int low = u,high = n;
			ll val = Qsum(1,1,n,u,u);
			while (low < high)
			{
				int mid = low + high + 1 >> 1;
				if (Qmax(1,1,n,u + 1,mid) >= val + v)
					high = mid - 1;
				else
					low = mid;
			}
			Setv(1,1,n,u,low,val + v);
		}
		else
			printf("%lld\n",Qsum(1,1,n,u,v) + sum2[v - 1] - (u >= 2 ? sum2[u - 2] : 0));
	}
	return 0;
}