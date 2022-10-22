#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define maxn 505
using namespace std;
int n, f[2][maxn * maxn], sum[2][maxn * maxn];
int sum2[2][maxn * maxn], sum3[2][maxn * maxn];
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
	int ans = 0;
	int last = 0, now = 1;
	f[last][0] = 1;
	for (int i = 0; i <= n * n / 2; i++) 
	{
		sum[last][i] = 1;
		sum2[last][i] = i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (register int j = 0; j <= i * i / 2; j++)
		{
			f[now][j] = sum[last][j];
			if(j - min(i - 1, j) - 1 >= 0) f[now][j] = (f[now][j] - sum[last][j - min(i - 1, j) - 1] + mo) % mo; 
			if(j == 0)
			{
				sum[now][j] = f[now][j];
				sum2[now][j] = sum[now][j];
				sum3[now][j] = 0;
			}
			else
			{
			sum[now][j] = (sum[now][j - 1] + f[now][j]) % mo;
			sum2[now][j] = (sum2[now][j - 1] + sum[now][j]) % mo;
			sum3[now][j] = (sum3[now][j - 1] + (ll)sum[now][j] * j % mo) % mo;
		}
		}
		for (register int j = i * i / 2 + 1; j <= (i + 1) * (i + 1) / 2; j++)
		{
			f[now][j] = 0;
			if(j == 0)
			{
				sum[now][j] = f[now][j];
				sum2[now][j] = sum[now][j];
				sum3[now][j] = 0;
			}
			else
			{
			sum[now][j] = (sum[now][j - 1] + f[now][j]) % mo;
			sum2[now][j] = (sum2[now][j - 1] + sum[now][j]) % mo;
			sum3[now][j] = (sum3[now][j - 1] + (ll)sum[now][j] * j % mo) % mo;
		}
		}
			for (register int k = 2; k <= i * i / 2; k++)
			{
				int tmp = sum2[now][k - 2];
				if(k - 1 - min(i + 1, k - 1) - 1 >= 0) tmp = (tmp + mo - sum2[now][k - 1 - min(i + 1, k - 1) - 1]) % mo;
				tmp = ((ll)tmp * (i + 2 - k + mo) % mo + sum3[now][k - 2]) % mo;
				if(k - 1 - min(i + 1, k - 1) - 1 >= 0) tmp = (tmp + mo - sum3[now][k - 1 - min(i + 1, k - 1) - 1]) % mo;
				ans = (ans + (ll)fac[n - i - 1] * c[n][n - i - 1] % mo * f[now][k] % mo * tmp % mo) % mo;
			}
			swap(last, now);
	}
	printf("%d", ans);
	return 0;
}