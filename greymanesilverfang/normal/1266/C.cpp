#include <cstdio>

int main()
{
	int r, c; scanf("%d%d", &r, &c);
	if (r == 1 && c == 1)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= r; ++i, puts(""))
		for (int j = 1; j <= c; ++j)
			printf("%d ", r < c ? i * (r + j) : j * (c + i));
}