#include <cstdio>

int f(int i, int x)
{
    return i < x ? 4 : x < 3 ? 3 : x - 2 << 1;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i, printf("\n"))
		for (int j = 1; j <= m; ++j)
			printf("%d ", f(i, n) * f(j, m));
}