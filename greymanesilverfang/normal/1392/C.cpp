#include <cstdio>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d", &n);
		int prv = 0;
		long long sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			int cur; scanf("%d", &cur);
			if (prv > cur)
				sum += prv - cur;
			prv = cur;
		}
		printf("%lld\n", sum);
	}
}