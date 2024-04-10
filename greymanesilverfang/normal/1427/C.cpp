#include <cstdio>
#include <algorithm>
const int MAX = 2e5;
int f[MAX], t[MAX], x[MAX], y[MAX];

int dist(int i, int j)
{
	return std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
}

int main()
{
	int r, n; scanf("%d%d", &r, &n);
	x[0] = y[0] = 1;
	int res = 0, max = -MAX;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = -MAX;
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		for (int j = 1; j < 998; ++j)
			if (j <= i && dist(i, i - j) <= t[i] - t[i - j])
			{
				// printf("i j %d %d\n", i, i - j);
				f[i] = std::max(f[i], f[i - j] + 1);
			}
		if (i >= 998)
		{
			max = std::max(max, f[i - 998]);
			f[i] = std::max(f[i], max + 1);
		}
		res = std::max(res, f[i]);
	}
	printf("%d\n", res);
}