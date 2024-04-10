#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[111111], num0, num1, arr[111111], cnt;
long long ans, cur;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		num0 = num1 = 0;
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &a[i]);
			if (a[i] & 1) num1 ++;
			else num0 ++;
		}
		if (abs(num0 - num1) > 1)
		{
			printf("-1\n");
			continue;
		}
		ans = 1e18;
		cnt = 0;
		if (num0 == num1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] % 2 == 0) arr[++cnt] = i;
			}
			cur = 0;
			for (int i = 1; i <= cnt; i++)
			{
				cur += abs(arr[i] - (i << 1));
			}
			ans = min(ans, cur);
			cur = 0;
			for (int i = 1; i <= cnt; i++)
			{
				cur += abs(arr[i] - (i << 1) + 1);
			}
			ans = min(ans, cur);
		}
		else if (num0 > num1)
		{
			ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] & 1) arr[++cnt] = i;
			}
			for (int i = 1; i <= cnt; i++)
			{
				ans += abs(arr[i] - (i << 1));
			}
		}
		else
		{
			ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] % 2 == 0) arr[++cnt] = i;
			}
			for (int i = 1; i <= cnt; i++)
			{
				ans += abs(arr[i] - (i << 1));
			}
		}
		printf("%lld\n", ans);
	}
	return Accepted;
}