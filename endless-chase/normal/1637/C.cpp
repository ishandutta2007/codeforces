#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[111111];
long long ans;
bool f;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ans = 0;
		if (n == 3 && (a[2] & 1))
		{
			printf("-1\n");
			continue;
		}
		f = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[i] > 1) f = 1;
		}
		if (!f)
		{
			printf("-1\n");
			continue;
		}
		for (int i = 2; i < n; i++)
		{
			ans += ((a[i] + 1) >> 1);
		}
		printf("%lld\n", ans);
	}
	return Accepted;
}