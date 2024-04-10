#include <cstdio>
#include <algorithm>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			int a; scanf("%d", &a);
			printf("%d ", i & 1 ? std::abs(a) : -std::abs(a));
		}
		printf("\n");
	}
}