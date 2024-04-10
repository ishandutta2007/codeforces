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

int n;
int a[MAXN];
int ans[MAXN];

bool ok[MAXN];

ll k;

ll check(ll v)
{
	for (int i = 1;i <= n;i++)
	{
		int low = 0,high = a[i];
		while (low < high)
		{
			int mid = low + high + 1 >> 1;
			if (a[i] + v - 3ll * mid * mid >= 0)
				low = mid;
			else
				high = mid - 1;
		}
		ok[i] = 0;
		if (low == a[i])
		{
			ans[i] = low;
			continue;
		}
		if (3ll * low * low + 3ll * low + 1 - a[i] - v <= 0)
			ans[i] = low + 1;
		else
			ans[i] = low;
		if (3ll * low * low + 3ll * low + 1 - a[i] - v == 0)
			ok[i] = 1;
	}
	ll tot = 0;
	for (int i = 1;i <= n;i++)
		tot += ans[i];
	return tot;
}

int main()
{
	scanf("%d%lld",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	ll low = -3e18,high = 3e18;
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (check(mid) >= k)
			high = mid;
		else
			low = mid + 1;
	}
	ll tot = check(low);
	for (int i = 1;i <= n;i++)
		if (tot > k && ok[i])
		{
			ans[i]--;
			tot--;
		}
	for (int i = 1;i <= n;i++)
		printf("%d ",ans[i]);
	printf("\n");
    return 0;
}