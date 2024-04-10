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
const ll MOD = 1000000007;

int T,n,p;
int a[MAXN];

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
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&p);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		if (p == 1)
		{
			printf("%d\n",(n & 1) ? 1 : 0);
			continue;
		}
		ll dif = 0,dif2 = 0;
		for (int i = n;i >= 1;i--)
		{
			if (i < n && a[i] != a[i + 1])
			{
				ll g = power(p,a[i + 1] - a[i]);
				(dif2 *= g) %= MOD;
				for (int j = 1;j <= a[i + 1] - a[i] && dif;j++)
				{
					dif *= p;
					if (dif >= n)
					{
						dif = n;
						break;
					}
				}
			}
			if (!dif)
				dif = dif2 = 1;
			else
			{
				dif--;
				dif2--;
			}
		}
		(dif2 *= power(p,a[1])) %= MOD;
		printf("%lld\n",(dif2 + MOD) % MOD);
	}
	return 0;
}