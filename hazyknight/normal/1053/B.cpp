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

const int MAXN = 300005;

int n;

ll ans,sum;
ll cnt[2];
ll a[MAXN];

int popcount(ll v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
		a[i] = popcount(a[i]);
	}
	cnt[0]++;
	for (int i = 1;i <= n;i++)
	{
		sum ^= (a[i] & 1);
		cnt[sum]++;
	}
	ans += cnt[0] * (cnt[0] - 1) / 2;
	ans += cnt[1] * (cnt[1] - 1) / 2;
	for (int i = 1;i <= n;i++)
	{
		sum = 0;
		ll MAX = 0,tot = 0;
		for (int j = i;j <= min(n,i + 64);j++)
		{
			MAX = max(MAX,a[j]);
			tot += a[j];
			sum ^= (a[j] & 1);
			if (!sum && MAX > tot / 2)
				ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}