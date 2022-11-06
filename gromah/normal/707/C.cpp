#include <cstdio>
typedef long long LL;

int n;
LL m, k;

int main()
{
	scanf("%d", &n);
	if (n <= 2) puts("-1");
	else if (n & 1)
	{
		int x = n + 1 >> 1, y = n - 1 >> 1;
		m = (LL) 2 * x * y;
		k = (LL) x * x + (LL) y * y;
		printf("%I64d %I64d\n", m, k);
	}
	else
	{
		int x = n >> 1, y = 1;
		m = (LL) (x + y) * (x - y);
		k = (LL) x * x + (LL) y * y;
		printf("%I64d %I64d\n", m, k);
	}
	return 0;
}