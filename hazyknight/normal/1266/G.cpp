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

const int MAXN = 1000005;
const ll MOD = 998244353;

int n;

ll ans;
ll c[MAXN << 1];
ll fac[MAXN];
ll inv[MAXN];

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
	cin >> n;
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	ans = n * fac[n] % MOD;
	ans = ans * (ans + 1) / 2 % MOD;
	c[0] = n;
	for (int i = 1;i < n;i++)
		c[i] = fac[n] * inv[n - i + 1] % MOD * ((ll)(n - i) * (n - i) % MOD + 1) % MOD;
	for (int i = n;i < 2 * n;i++)
		c[i] = fac[n] - c[i - n];
	for (int i = 1;i < 2 * n;i++)
		(ans -= c[i] * i) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}