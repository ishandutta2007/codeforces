#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 105;
const int S = 40000;

int n;
int a[MAXN];
int b[MAXN];
double ans[MAXN];
int f[2][MAXN][MAXN * MAXN * 6];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[i] <<= 1;
		b[i] <<= 1;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j <= i + 1;j++)
			for (int k = -400 * (i + 1);k <= 200 * (i + 1);k++)
				f[~i & 1][j][k + S] = -1e9;
		for (int j = 0;j <= i;j++)
			for (int k = -400 * i;k <= 200 * i;k++)
				if (f[i & 1][j][k + S] >= 0)
				{
					f[~i & 1][j + 1][k - (a[i + 1] - b[i + 1]) * 2 + S] = max(f[~i & 1][j + 1][k - (a[i + 1] - b[i + 1]) * 2 + S],f[i & 1][j][k + S] + a[i + 1]);
					f[~i & 1][j][k + b[i + 1] + S] = max(f[~i & 1][j][k + b[i + 1] + S],f[i & 1][j][k + S]);
				}
	}
	for (int j = 1;j <= n;j++)
		for (int k = -40000;k <= 20000;k++)
			ans[j] = max(ans[j],f[n & 1][j][k + S] + min(k / 2.,0.));
	for (int i = 1;i <= n;i++)
		printf("%.10lf ",ans[i] / 2.);
	printf("\n");
	return 0;
}