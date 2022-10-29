#include <cstdio>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		long long x; scanf("%lld", &x);
		printf("%s\n", 14 <= x && 1 <= x % 14 && x % 14 <= 6 ? "YES" : "NO");
	}
}