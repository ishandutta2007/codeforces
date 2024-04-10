#include <cstdio>
#include <algorithm>
const int N = 3e5, INF = 1e9;
int m[2], a[N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d", &n);
		long long k; scanf("%lld", &k);
		m[0] = INF;
		m[1] = -INF;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &a[i]);
			m[0] = std::min(m[0], a[i]);
			m[1] = std::max(m[1], a[i]);
		}
		for (int i = 1; i <= n; ++i)
			printf("%d ", std::abs(m[k % 2] - a[i]));
		printf("\n");
	}
}