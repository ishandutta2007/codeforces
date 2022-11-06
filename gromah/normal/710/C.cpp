#include <cstdio>

int n;

inline int Dis(int u, int v)
{
	int x = n + 1 >> 1, res = 0;
	res += u > x ? u - x : x - u;
	res += v > x ? v - x : x - v;
	return res;
}

int main()
{
	scanf("%d", &n);
	if (~n & 1) puts("What the fuck?");
	else
	{
		int d = n >> 1, t_0 = 0, t_1 = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (Dis(i, j) <= d)
				{
					printf("%d%c", t_1 << 1 | 1, j == n ? '\n' : ' ');
					t_1 ++;
				}
				else
				{
					t_0 ++;
					printf("%d%c", t_0 << 1, j == n ? '\n' : ' ');
				}
	}
	return 0;
}