#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXL = 200005;
const int MAXN = 2005;
const ll MOD = 1000000007;

int n,m,k,s;

ll ans;
ll f[MAXN];
ll fac[MAXL];
ll inv[MAXL];
ll g[MAXN][25];

pair<int,int> a[MAXN];

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
	fac[0] = 1;
	for (int i = 1;i <= 200000;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[200000] = power(fac[200000],MOD - 2);
	for (int i = 200000;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll calc(int x,int y)
{
	return C(x + y,x);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	init();
	for (int i = 1;i <= k;i++)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a + 1,a + k + 1);
	bool flag = 0;
	if (a[k].first != n || a[k].second != m)
	{
		a[++k] = make_pair(n,m);
		flag = 1;
	}
	for (int i = 1;i <= k;i++)
	{
		f[i] = calc(a[i].first - 1,a[i].second - 1);
		for (int j = 1;j < i;j++)
			if (a[j].first <= a[i].first && a[j].second <= a[i].second)
				(f[i] -= f[j] * calc(a[i].first - a[j].first,a[i].second - a[j].second)) %= MOD;
	}
	for (int i = 1;i <= k;i++)
	{
		g[i][1] = f[i];
		g[i][min(20,i) + 1] = (calc(a[i].first - 1,a[i].second - 1) - g[i][1]) % MOD;
		for (int j = 2;j <= min(20,i);j++)
		{
			g[i][j] = calc(a[i].first - 1,a[i].second - 1);
			for (int l = 1;l < j;l++)
				(g[i][j] -= g[i][l]) %= MOD;
			for (int l = 1;l < i;l++)
				if (a[l].first <= a[i].first && a[l].second <= a[i].second)
					(g[i][j] -= g[l][j] * calc(a[i].first - a[l].first,a[i].second - a[l].second)) %= MOD;
			(g[i][min(20,i) + 1] -= g[i][j]) %= MOD;
		}
	}
	for (int i = 0;i <= 21;i++,s = (s + 1) / 2)
		(ans += s * g[k][i + flag]) %= MOD;
	(ans *= power(calc(n - 1,m - 1),MOD - 2)) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}