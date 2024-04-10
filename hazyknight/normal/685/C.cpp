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
#include <assert.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,n;

ll MINA,MAXA,MINB,MAXB,MINC,MAXC,MIND,MAXD;
ll x[MAXN];
ll y[MAXN];
ll z[MAXN];
ll a[MAXN];
ll b[MAXN];
ll c[MAXN];
ll d[MAXN];

ll up(ll x)
{
	return x & 1 ? (x + 1) / 2 : x / 2;
}

ll dn(ll x)
{
	return x & 1 ? (x - 1) / 2 : x / 2;
}

bool solve(ll MINABC,ll MAXABC,ll MINA,ll MAXA,ll MINB,ll MAXB,ll MINC,ll MAXC,ll &A,ll &B,ll &C)
{
	if (MINABC > MAXABC || MINA > MAXA || MINB > MAXB || MINC > MAXC || MINA + MINB + MINC > MAXABC || MAXA + MAXB + MAXC < MINABC)
		return 0;
	A = MINA;
	B = MINB;
	C = MINC;
	if (A + B + C >= MINABC)
		return 1;
	A += min(MAXA - A,MINABC - A - B - C);
	if (A + B + C >= MINABC)
		return 1;
	B += min(MAXB - B,MINABC - A - B - C);
	if (A + B + C >= MINABC)
		return 1;
	C += min(MAXC - C,MINABC - A - B - C);
	return 1;
}

bool ok(ll l)
{
	MINA = MINB = MINC = MIND = -4e18;
	MAXA = MAXB = MAXC = MAXD = 4e18;
	for (int i = 1;i <= n;i++)
	{
		MINA = max(MINA,a[i] - l);
		MINB = max(MINB,b[i] - l);
		MINC = max(MINC,c[i] - l);
		MIND = max(MIND,d[i] - l);
		MAXA = min(MAXA,a[i] + l);
		MAXB = min(MAXB,b[i] + l);
		MAXC = min(MAXC,c[i] + l);
		MAXD = min(MAXD,d[i] + l);
	}
	ll A,B,C;
	return solve(up(MINA),dn(MAXA),up(MINB),dn(MAXB),up(MINC),dn(MAXC),up(MIND),dn(MAXD),A,B,C) || solve(up(MINA - 3),dn(MAXA - 3),up(MINB - 1),dn(MAXB - 1),up(MINC - 1),dn(MAXC - 1),up(MIND - 1),dn(MAXD - 1),A,B,C);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
			a[i] = x[i] + y[i] + z[i];
			b[i] = x[i] - y[i] + z[i];
			c[i] = x[i] + y[i] - z[i];
			d[i] = -x[i] + y[i] + z[i];
		}
		ll low = 0,high = 4e18;
		while (low < high)
		{
			ll mid = low + high >> 1;
			if (ok(mid))
				high = mid;
			else
				low = mid + 1;
		}
		ok(low);
		ll A,B,C,t = 0;
		if (!solve(up(MINA),dn(MAXA),up(MINB),dn(MAXB),up(MINC),dn(MAXC),up(MIND),dn(MAXD),A,B,C))
		{
			t = 1;
			solve(up(MINA - 3),dn(MAXA - 3),up(MINB - 1),dn(MAXB - 1),up(MINC - 1),dn(MAXC - 1),up(MIND - 1),dn(MAXD - 1),A,B,C);
		}
		printf("%lld %lld %lld\n",A + B + t,B + C + t,A + C + t);
	}
	return 0;
}