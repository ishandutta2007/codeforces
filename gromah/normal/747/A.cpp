#include <cstdio>

int n, x;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i * i <= n; i ++)
		if (n % i == 0) x = i;
	printf("%d %d\n", x, n / x);
	return 0;
}