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

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 998244353;

struct Event
{
	ll d,v;
	int p,x,y;
	
	bool operator < (const Event &p)const
	{
		return d * p.v < p.d * v;
	}
}evt[MAXN << 1];

int n,tot;

ll Inv,ANS;
ll x[MAXN];
ll v[MAXN];
ll a[MAXN];
ll ans[MAXN];
ll p[MAXN << 2][2][2];

bool ok[MAXN][2][2];

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

void update(int o,int x)
{
	p[o][0][0] = p[o][0][1] = p[o][1][0] = p[o][1][1] = 0;
	for (int xl = 0;xl <= 1;xl++)
		for (int yl = 0;yl <= 1;yl++)
			for (int xr = 0;xr <= 1;xr++)
				for (int yr = 0;yr <= 1;yr++)
					if (ok[x][yl][xr])
						(p[o][xl][yr] += p[o << 1][xl][yl] * p[o << 1 | 1][xr][yr]) %= MOD;
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		p[o][0][0] = 1 - a[l];
		p[o][1][1] = a[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	update(o,mid);
}

void modify(int o,int l,int r,int x)
{
	int mid = l + r >> 1;
	if (x < mid)
		modify(o << 1,l,mid,x);
	if (x > mid)
		modify(o << 1 | 1,mid + 1,r,x);
	update(o,mid);
}

int main()
{
	scanf("%d",&n);
	Inv = power(100,MOD - 2);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld%lld%lld",&x[i],&v[i],&a[i]);
		(a[i] *= Inv) %= MOD;
	}
	for (int i = 1;i < n;i++)
	{
		ok[i][0][0] = ok[i][0][1] = ok[i][1][0] = ok[i][1][1] = 1;
		evt[++tot] = (Event){x[i + 1] - x[i],v[i] + v[i + 1],i,1,0};
		if (v[i] > v[i + 1])
			evt[++tot] = (Event){x[i + 1] - x[i],v[i] - v[i + 1],i,1,1};
		if (v[i] < v[i + 1])
			evt[++tot] = (Event){x[i + 1] - x[i],v[i + 1] - v[i],i,0,0};
	}
	sort(evt + 1,evt + tot + 1);
	ans[0] = 1;
	buildtree(1,1,n);
	for (int i = 1;i <= tot;i++)
	{
		ok[evt[i].p][evt[i].x][evt[i].y] = 0;
		modify(1,1,n,evt[i].p);
		ans[i] = (p[1][0][0] + p[1][0][1] + p[1][1][0] + p[1][1][1]) % MOD;
		(ANS += evt[i].d * power(evt[i].v,MOD - 2) % MOD * (ans[i - 1] - ans[i])) %= MOD;
	}
	printf("%lld\n",(ANS + MOD) % MOD);
	return 0;
}