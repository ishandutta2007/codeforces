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

int T,n,m,K;
int a[MAXN];

ll ans;
ll sum[MAXN];

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 0;i < m;i++)
		for (int j = 0;j < m;j++)
		{
			ll MIN = 1e18,cur = 0;
			for (int k = 0;k <= n;k++)
			{
				if (k % m == i)
					cur = max(cur,sum[k] - (ll)k / m * K - MIN);
				if (k % m == j)
					MIN = min(MIN,sum[k] - (ll)k / m * K);
			}
			if (i > j)
				cur -= K;
			ans = max(ans,cur);
		}
	printf("%lld\n",ans);
	return 0;
}