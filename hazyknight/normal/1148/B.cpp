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

int n,m,k;

ll ta,tb,ans;
ll a[MAXN];
ll b[MAXN];

int main()
{
	scanf("%d%d%lld%lld%d",&n,&m,&ta,&tb,&k);
	if (m <= k)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	a[n + 1] = (1ll << 60) - 1;
	for (int i = 1;i <= m;i++)
		scanf("%lld",&b[i]);
	for (int i = 0;i <= min(n,k);i++)
	{
		ll t = a[i + 1] + ta;
		if (t > b[m])
		{
			puts("-1");
			return 0;
		}
		int low = 1,high = m;
		while (low < high)
		{
			int mid = low + high >> 1;
			if (b[mid] >= t)
				high = mid;
			else
				low = mid + 1;
		}
		if (low + k - i - 1 >= m)
		{
			puts("-1");
			return 0;
		}
		ans = max(ans,b[low + k - i] + tb);
	}
	printf("%lld\n",ans);
	return 0;
}