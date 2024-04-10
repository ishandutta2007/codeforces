#include <cstdio>
#include <cmath>
#include <algorithm>

int tri(int x)
{
	return x * (x + 1) / 2;
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int a, b; scanf("%d%d", &a, &b);
		int d = std::abs(a - b);
		int x = std::max((int) sqrt(2 * d) - 1, 0);
		while (tri(x) < d || tri(x) - d & 1)
			++x;
		printf("%d\n", x);
	}
}