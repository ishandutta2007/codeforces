#include <cstdio>
const int N = 301;
int a[N][N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				if ((i == 1 || i == n) && (j == 1 || j == m) && a[i][j] > 2)
					goto wrong;
				if ((i == 1 || i == n || j == 1 || j == m) && a[i][j] > 3)
					goto wrong;
				if (a[i][j] > 4)
					goto wrong;
			}
		printf("YES\n");
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				if ((i == 1 || i == n) && (j == 1 || j == m))
					printf("2 ");
				else if (i == 1 || i == n || j == 1 || j == m)
					printf("3 ");
				else 
					printf("4 ");
			printf("\n");
		}
		continue;
		wrong:
		printf("NO\n");
	}
}