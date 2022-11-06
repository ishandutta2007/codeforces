#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2000 + 5

int n, a[N], f[N][2][2], sum[N][N][4];

inline void update(int &x, int a)
{
	if (a > x) x = a;
}

void Solve()
{
	memset(sum, 200, sizeof(sum));
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j >= 1; j --)
		{
			if (a[j] == 1)
			{
				update(sum[j][i][0], 1);
				update(sum[j][i][0], sum[j + 1][i][0] + 1);
			}
			else
			{
				update(sum[j][i][1], sum[j + 1][i][0] + 1);
				update(sum[j][i][1], sum[j + 1][i][1] + 1);
				update(sum[j][i][2], 1);
				update(sum[j][i][2], sum[j + 1][i][2] + 1);
			}
			update(sum[j][i][0], sum[j + 1][i][0]);
			update(sum[j][i][1], sum[j + 1][i][1]);
			update(sum[j][i][2], sum[j + 1][i][2]);
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] == 1)
		{
			update(f[i][0][0], f[i - 1][0][0] + 1);
			update(f[i][0][1], f[i - 1][0][1] + 1);
		}
		else
		{
			update(f[i][1][0], f[i - 1][1][0] + 1);
			update(f[i][1][1], f[i - 1][1][1] + 1);
			update(f[i][1][0], f[i - 1][0][0] + 1); 
			update(f[i][1][1], f[i - 1][0][1] + 1);
		}
		for (int j = 1; j <= i; j ++)
		{
			update(f[i][0][1], f[j - 1][0][0] + sum[j][i][0]);
			update(f[i][1][1], f[j - 1][0][0] + sum[j][i][1]);
			update(f[i][1][1], f[j - 1][1][0] + sum[j][i][2]);
		}
		update(f[i][0][0], f[i - 1][0][0]);
		update(f[i][0][1], f[i - 1][0][1]);
		update(f[i][1][0], f[i - 1][1][0]);
		update(f[i][1][1], f[i - 1][1][1]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		update(ans, f[i][0][1]);
		update(ans, f[i][1][1]);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", a + i);
	Solve();
	return 0;
}