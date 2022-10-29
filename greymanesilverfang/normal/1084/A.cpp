#include <cstdio>

int main()
{
	int n; scanf("%d", &n);
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a; scanf("%d", &a);
		res += a * (i - 1) * 4;
	}
	printf("%d", res);
	return 0;
}