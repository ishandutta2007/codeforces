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

const int MAXN = 5005;
const ll MOD = 1000000007;

int n,k;
int a[MAXN];

ll tot,ans;
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

int main()
{
	cin >> n >> k;
	tot = 1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		(tot *= a[i]) %= MOD;
	}
	f[0][0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= i;j++)
			f[i][j] = (f[i - 1][j] + (j ? f[i - 1][j - 1] * a[i] : 0)) % MOD;
	ll fac = 1;
	for (int i = 0;i <= min(k,n);(fac *= k - (i++)) %= MOD)
	{
		ll val = power(n,k - i) * fac % MOD * f[n][n - i] % MOD;
		if (i & 1)
			(ans -= val) %= MOD;
		else
			(ans += val) %= MOD;
	}
	ans = (tot - ans * power(n,k * (MOD - 2))) % MOD;
	cout << (ans + MOD) % MOD << endl;
	return 0;
}