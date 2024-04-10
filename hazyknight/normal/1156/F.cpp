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
const ll MOD = 998244353;

int n;
int a[MAXN];

ll ans;
ll fac[MAXN];
ll inv[MAXN];
ll sum[MAXN];
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
	scanf("%d",&n);
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n] = power(fac[n],MOD - 2);
	for (int i = n;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
	for (int i = 1;i <= n;i++)
		(inv[i] *= fac[i - 1]) %= MOD;
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	int cnt = 1;
	for (int i = n;i >= 1;i--,cnt++)
		if (a[i] != a[i - 1])
		{
			for (int j = 1;j <= i;j++)
			{
				f[i][j] = (cnt - 1 + sum[j + 1]) * inv[n - j] % MOD;
				(sum[j] += f[i][j] * cnt) %= MOD;
			}
			(ans += f[i][1] * cnt) %= MOD;
			cnt = 0;
		}
	printf("%d\n",(int)(ans * inv[n] % MOD));
	return 0;
}