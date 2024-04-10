#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

typedef long long ll;
 
const int MAXN = 300005;
const ll MOD = 998244353;

int n,m;
int a[MAXN];

ll ans;
ll f[MAXN];
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

ll Inv(int v)
{
	return fac[v - 1] * inv[v] % MOD;
}
 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		m += a[i];
	}
	fac[0] = 1;
	for (int i = 1;i <= max(n,m);i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[max(n,m)] = power(fac[max(n,m)],MOD - 2);
	for (int i = max(n,m);i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	ll val1 = (n - 2) * Inv(n - 1) % MOD,val2 = (val1 + Inv(n - 1)) % MOD;
	f[0] = val2 * power(1 - val1,MOD - 2) % MOD;
	for (int i = 1;i < m;i++)
	{
		ll c = (ll)(m - i) * (n - 2) % MOD * Inv(m) % MOD * Inv(n - 1) % MOD;
		val1 = (c + i * Inv(m)) % MOD;
		val2 = (c + (m - i) * Inv(m) % MOD * Inv(n - 1) + i * Inv(m) % MOD * (f[i - 1] + 1)) % MOD;
		f[i] = val2 * power(1 - val1,MOD - 2) % MOD;
	}
	for (int i = m - 2;i >= 0;i--)
		(f[i] += f[i + 1]) %= MOD;
	ll ans = 0;
	for (int i = 1;i <= n;i++)
		(ans += f[a[i]]) %= MOD;
	(ans -= f[0] * (n - 1)) %= MOD;
	(ans *= power(n,MOD - 2)) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}