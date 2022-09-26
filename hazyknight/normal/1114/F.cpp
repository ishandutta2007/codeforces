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
typedef unsigned long long ull;

const int MAXN = 400005;
const int MAXV = 305;
const ll MOD = 1000000007;

int n,q,tot;
int a[MAXN];
int prime[MAXV];

ll inv[MAXV];
ll laz1[MAXN << 2];
ll mul[MAXN << 2];

ull mask[MAXN];
ull laz2[MAXN << 2];
ull info[MAXN << 2];

bool mark[MAXV];

char s[10];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

void init()
{
	for (int i = 2;i <= 300;i++)
	{
		if (!mark[i])
		{
			inv[tot] = power(i,MOD - 2);
			prime[tot++] = i;
		}
		for (int j = 0;j < tot && i * prime[j] <= 300;j++)
		{
			mark[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

void pushup(int o)
{
	mul[o] = mul[o << 1] * mul[o << 1 | 1] % MOD;
	info[o] = info[o << 1] | info[o << 1 | 1];
}

void mdf1(int o,int l,int r,ll v)
{
	(mul[o] *= power(v,r - l + 1)) %= MOD;
	(laz1[o] *= v) %= MOD;
}

void mdf2(int o,ull v)
{
	info[o] |= v;
	laz2[o] |= v;
}

void pushdown(int o,int l,int r)
{
	int mid = (l + r) >> 1;
	if (laz1[o] != 1)
	{
		mdf1(o << 1,l,mid,laz1[o]);
		mdf1(o << 1 | 1,mid + 1,r,laz1[o]);
		laz1[o] = 1;
	}
	if (laz2[o])
	{
		mdf2(o << 1,laz2[o]);
		mdf2(o << 1 | 1,laz2[o]);
		laz2[o] = 0;
	}
}

void buildtree(int o,int l,int r)
{
	laz1[o] = 1;
	if (l == r)
	{
		mul[o] = a[l];
		info[o] = mask[l];
		return;
	}
	int mid = (l + r) >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	pushup(o);
}

void modify(int o,int l,int r,int x,int y,ll v,ull V)
{
	if (l >= x && r <= y)
	{
		mdf1(o,l,r,v);
		mdf2(o,V);
		return;
	}
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v,V);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v,V);
	pushup(o);
}

ll query1(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return mul[o];
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	if (mid + 1 > y)
		return query1(o << 1,l,mid,x,y);
	if (mid < x)
		return query1(o << 1 | 1,mid + 1,r,x,y);
	return query1(o << 1,l,mid,x,y) * query1(o << 1 | 1,mid + 1,r,x,y) % MOD;
}

ull query2(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return info[o];
	pushdown(o,l,r);
	int mid = (l + r) >> 1;
	if (mid + 1 > y)
		return query2(o << 1,l,mid,x,y);
	if (mid < x)
		return query2(o << 1 | 1,mid + 1,r,x,y);
	return query2(o << 1,l,mid,x,y) | query2(o << 1 | 1,mid + 1,r,x,y);
}

int main()
{
	init();
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		for (int j = 0;j < tot;j++)
			if (a[i] % prime[j] == 0)
				mask[i] |= (1ull << j);
	}
	buildtree(1,1,n);
	for (int l,r,v,i = 1;i <= q;i++)
	{
		scanf("%s",s);
		if (s[0] == 'M')
		{
			scanf("%d%d%d",&l,&r,&v);
			ull V = 0;
			for (int j = 0;j < tot;j++)
				if (v % prime[j] == 0)
					V |= (1ull << j);
			modify(1,1,n,l,r,v,V);
		}
		else
		{
			scanf("%d%d",&l,&r);
			ll res1 = query1(1,1,n,l,r),res2 = query2(1,1,n,l,r);
			for (int j = 0;j < tot;j++)
				if (res2 >> j & 1)
					(res1 *= (prime[j] - 1) * inv[j] % MOD) %= MOD;
			printf("%d\n",(int)res1);
		}
	}
	return 0;
}