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

const int MAXN = 1100005;
const ll MOD = 998244353;

int n,cnt,tot;
int a[MAXN];
int sum[MAXN];

ll ans;
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

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n + tot;i++)
		fac[i] = fac[i - 1] * i % MOD;
	inv[n + tot] = power(fac[n + tot],MOD - 2);
	for (int i = n + tot;i >= 1;i--)
		inv[i - 1] = inv[i] * i % MOD;
}

ll C(int x,int y)
{
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		tot += a[i];
	}
	init();
	sort(a + 1,a + n + 1);
	int MIN = -1;
	for (int i = 1;i < n;i++)
		if (a[i + 1] < i)
		{
			MIN = i - 1;
			break;
		}
	if (~MIN)
	{
		for (int i = 0,j = 0;i <= MIN;i++)
		{
			while (j + 1 <= n && a[j + 1] < i)
				j++;
			(ans += C(i + n - j - 1,n - 1)) %= MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		a[i] %= n;
		sum[0] += a[i];
		sum[n - a[i]] -= n;
	}
	for (int i = 0;i < n;i++)
	{
		cnt += sum[i];
		(ans += C((tot - cnt) / n + n - 1,n - 1)) %= MOD;
		cnt += n;
	}
	printf("%lld\n",ans);
	return 0;
}