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

const int MAXN = 2005;
const ll MOD = 1000000007;

int n;
int a[MAXN];

ll ans;
ll fac[MAXN];
ll inv[MAXN];

bool vis[MAXN];

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
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d",&n);
	int need = 0;
	init();
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		if (~a[i])
		{
			if (a[i] == i)
			{
				puts("0");
				return 0;
			}
			vis[a[i]] = vis[i] = 1;
		}
		else
			need++;
	}
	int tot = 0;
	for (int i = 1;i <= n;i++)
		if (!vis[i])
			tot++;
	for (int i = 0;i <= tot;i++)
	{
		int v = ((i & 1) ? -1 : 1);
		(ans += v * C(tot,i) * fac[need - i]) %= MOD;
	}
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}