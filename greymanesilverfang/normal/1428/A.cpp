#include <cstdio>
#include <algorithm>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int res = std::abs(x1 - x2) + std::abs(y1 - y2);
		if (x1 != x2 && y1 != y2)
			res += 2;
		printf("%d\n", res);
	}
}