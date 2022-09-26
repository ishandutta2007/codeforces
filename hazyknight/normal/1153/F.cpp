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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <bitset>

using namespace std;

typedef long long ll;

const int MAXN = 4005;
const ll MOD = 998244353;

ll n,k,l,ans;
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

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	cin >> n >> k >> l;
	f[0] = 1;
	for (int i = 2;i <= n << 1;i += 2)
		f[i] = (i - 1) * f[i - 2] % MOD;
	fac[0] = 1;
	for (int i = 1;i <= n << 1;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n << 1] = power(fac[n << 1],MOD - 2);
	for (int i = n << 1;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	(l *= power(n << 1 | 1,MOD - 2)) %= MOD;
	for (int i = 0;i <= n << 1;i++)
		for (int j = k;j <= n;j++)
		{
			int l = i,r = 2 * n - i;
			if (((l - j) & 1) || ((r - j) & 1) || l < j || r < j)
				continue;
			(ans += C(l,j) * C(r,j) % MOD * fac[j] % MOD * f[l - j] % MOD * f[r - j] % MOD) %= MOD;
		}
	cout << l * ans % MOD * power(f[n << 1],MOD - 2) % MOD << endl;
	return 0;
}