#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T,n;
int v[505][505];

ll sumx[505][505];
ll sumy[505][505];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ll ans = 0,MIN = 1e18;
		for (int i = 1;i <= 2 * n;i++)
			for (int j = 1;j <= 2 * n;j++)
			{
				scanf("%d",&v[i][j]);
				if (i > n && j > n)
					ans += v[i][j];
			}
		for (int i = 1;i <= 2 * n;i++)
			for (int j = 1;j <= 2 * n;j++)
			{
				sumx[i][j] = sumx[i][j - 1] + v[i][j];
				sumy[i][j] = sumy[i - 1][j] + v[i][j];
			}
		for (int i = 1;i <= n;i++)
			for (int j = n + 1;j <= 2 * n;j++)
				if (i == 1 || i == n || j == n + 1 || j == 2 * n)
					MIN = min(MIN,min(sumx[i][j - 1] - sumx[i][n],sumx[i][2 * n] - sumx[i][j]) + min(sumy[i - 1][j] - sumy[0][j],sumy[n][j] - sumy[i][j]) + v[i][j]);
		for (int i = n + 1;i <= 2 * n;i++)
			for (int j = 1;j <= n;j++)
				if (i == n + 1 || i == 2 * n || j  == 1 || j == n)
					MIN = min(MIN,min(sumx[i][j - 1] - sumx[i][0],sumx[i][n] - sumx[i][j]) + min(sumy[i - 1][j] - sumy[n][j],sumy[2 * n][j] - sumy[i][j]) + v[i][j]);
		printf("%lld\n",ans + MIN);
	}
	return 0;
}