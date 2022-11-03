#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[111], ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				ans += (j - i + 1);
				for (int k = i; k <= j; k++)
				{
					if (a[k] == 0) ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return Accepted;
}