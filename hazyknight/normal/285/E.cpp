#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

const int MAXN = 1005;
const int MOD = 1000000007;

int n,k;

ll ans;
ll g[MAXN];
ll fac[MAXN];
ll inv[MAXN];
ll f[MAXN][MAXN];

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
	for (int i = 1;i <= n;i++)
	 	fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return x < y ? 0 : fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	cin >> n >> k;
	init();
	f[0][0] = f[1][0] = f[1][1] = 1;
	for (int i = 2;i < n;i++)
		for (int j = 0;j <= i;j++)
		{
			f[i][j] = f[i - 1][j];
			if (j > 0)
				(f[i][j] += f[i - 2][j - 1]) %= MOD;
		}
	for (int i = 0;i <= n / 2;i++)
		for (int j = 0;j <= n / 2;j++)
			(g[i + j] += f[n - 1][i] * f[n - 1][j] % MOD * fac[n / 2 - i + (n + 1) / 2 - j]) %= MOD;
	for (int i = n;i >= 0;i--)
		for (int j = i + 1;j <= n;j++)
			(g[i] -= g[j] * C(j,i)) %= MOD;
	cout << (g[k] + MOD) % MOD << endl;
	return 0;
}