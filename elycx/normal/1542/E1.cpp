#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define maxn 105
using namespace std;
int n, f[maxn][maxn * maxn], sum[maxn][maxn * maxn];
int mo;
int fac[maxn];
int c[maxn][maxn]; 
int main()
{
	scanf("%d%d", &n, &mo);
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
	}
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mo;
		}
	}
	f[0][0] = 1;
	for (int i = 0; i <= n * n; i++) sum[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n * n; j++)
		{
			f[i][j] = sum[i - 1][j];
			if(j - min(i - 1, j) - 1 >= 0) f[i][j] = (f[i][j] - sum[i - 1][j - min(i - 1, j) - 1] + mo) % mo; 
			if(j == 0) sum[i][j] = f[i][j];
			else sum[i][j] = (sum[i][j - 1] + f[i][j]) % mo;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			for (int k = j + 1; k <= n * n; k++)
			{
				int tmp = ans;
				ans = (ans + (ll)fac[i - 1] * c[n][i - 1] % mo * f[n - i][k] % mo * sum[n - i][k - j - 1] % mo * (n - i + 1 - j) % mo) % mo;
//				printf("%d %d %d %d\n", fac[i - 1], calc(n, i - 1) % mo, f[n - i][k] % mo, (ll)sum[n - i][k - j - 1] % mo * (n - i + 1 - j + 1) % mo);
//				printf("%d %d %d %d\n", i, j, k, ans - tmp) % mo;
			}
		}
	}
	printf("%d", ans);
	return 0;
}