#include <cstdio>

int n;
long long x;

int main()
{
	scanf("%d%I64d", &n, &x);
	for (n = 1; x + 1 & 1; x >>= 1) n ++;
	printf("%d\n", n);
	return 0;
}