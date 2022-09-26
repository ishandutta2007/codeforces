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

const int MAXN = 100005;

int n,k;
int a[MAXN];

ll sum[MAXN];

map<ll,int> cnt;

ll Count(ll t)
{
	cnt.clear();
	cnt[0] = 1;
	ll r = 0;
	for (int i = 1;i <= n;i++)
	{
		r += cnt[sum[i] - t];
		cnt[sum[i]]++;
	}
	return r;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	if (k == 1)
		printf("%lld\n",Count(1));
	else if (k == -1)
		printf("%lld\n",Count(1) + Count(-1));
	else
	{
		ll v = 1,ans = 0;
		while (abs(v) <= n * 1e9)
		{
			ans += Count(v);
			v *= k;
		}
		printf("%lld\n",ans);
	}
	return 0;
}