#include <algorithm>
#include <cstdlib>
#include <cstdio>

int main()
{
	int n; scanf("%d", &n);
	const int INF = 1e9;
	int MIN = INF, MAX = -INF;
	long long ans = 0;
	if (n > 1)
	{
		for (int i = 0; i < n; ++i)
		{
			int a; scanf("%d", &a);
			MIN = std::min(MIN, a);
			MAX = std::max(MAX, a);
			ans += llabs(a);
		}
		printf("%lld", ans - std::max(0, 2 * MIN) + std::min(0, 2 * MAX));
	}
	else 
	{
		scanf("%lld", &ans);
		printf("%lld", ans);
	}
	return 0;
}