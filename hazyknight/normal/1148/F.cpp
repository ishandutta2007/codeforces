#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int n;
int val[MAXN];
int cnt[MAXN];

ll sum,ans;
ll mask[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%lld",&val[i],&mask[i]);
		sum += val[i];
	}
	if (sum < 0)
	{
		for (int i = 1;i <= n;i++)
			val[i] = -val[i];
	}
	for (int i = 61;i >= 0;i--)
	{
		ll a = 0,b = 0;
		for (int j = 1;j <= n;j++)
			if ((1ll << i) == (mask[j] & -mask[j]))
			{
				if (cnt[j] & 1)
					b += val[j];
				else
					a += val[j];
			}
		if (b - a < 0)
		{
			ans |= (1ll << i);
			for (int j = 1;j <= n;j++)
				if (mask[j] >> i & 1)
					cnt[j]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}