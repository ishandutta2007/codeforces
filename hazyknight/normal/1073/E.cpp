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
#include <iomanip>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll l,r,k;
ll f[20][1 << 10][2];
ll g[20][1 << 10][2];

ll a[20];

ll bitcount(ll p)
{
	return p ? bitcount(p - (p & -p)) + 1 : 0;
}

ll dp(int n,ll lim)
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	ll ret = 0;
	for (int i = n;i >= 1;i--)
	{
		a[i] = lim % 10;
		lim /= 10;
	}
	for (int i = 1;i < a[1];i++)
	{
		f[1][1 << i][0] = i;
		g[1][1 << i][0] = 1;
	}
	f[1][1 << a[1]][1] = a[1];
	g[1][1 << a[1]][1] = 1;
	for (int i = 1;i < n;i++)
		for (int j = 0;j < (1 << 10);j++)
		{
			if (f[i][j][0] || g[i][j][0])
			{
				for (int k = 0;k <= 9;k++)
				{
					(f[i + 1][j | (1 << k)][0] += f[i][j][0] * 10 + g[i][j][0] * k) %= MOD;
					(g[i + 1][j | (1 << k)][0] += g[i][j][0]) %= MOD;
				}
			}
			if (f[i][j][1] || g[i][j][1])
			{
				for (int k = 0;k < a[i + 1];k++)
				{
					(f[i + 1][j | (1 << k)][0] += f[i][j][1] * 10 + g[i][j][1] * k) %= MOD;
					(g[i + 1][j | (1 << k)][0] += g[i][j][1]) %= MOD;
				}
				(f[i + 1][j | (1 << a[i + 1])][1] += f[i][j][1] * 10 + g[i][j][1] * a[i + 1]) %= MOD;
				(g[i + 1][j | (1 << a[i + 1])][1] += g[i][j][1]) %= MOD;
			}
		}
	for (int i = 0;i < (1 << 10);i++)
		if (bitcount(i) <= k)
			(ret += f[n][i][0] + f[n][i][1]) %= MOD;
	return ret;
}

ll solve(ll v)
{
	if (!v)
		return 0;
	ll ret = 0;
	for (int i = 1;i <= 18;i++)
	{
		ll MAX = 0;
		for (int j = 1;j <= i;j++)
			MAX = MAX * 10 + 9;
		if (MAX >= v)
		{
			(ret += dp(i,v)) %= MOD;
			break;
		}
		(ret += dp(i,MAX)) %= MOD;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> r >> k;
	cout << (solve(r) - solve(l - 1) + MOD) % MOD << endl;
	return 0;
}