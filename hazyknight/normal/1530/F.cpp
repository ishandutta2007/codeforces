#include <bits/stdc++.h>

using namespace std;

const int MAXN = 21;
const int MOD = 31607;

int n,ans;
int c[MAXN];
int r[MAXN];
int iv[MAXN][MAXN];
int a[MAXN][MAXN];

int power(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
//	n = 21;
	int inv = power(10000,MOD - 2);
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
		//	a[i][j] = rand() % 10000 + 1;
			(a[i][j] *= inv) %= MOD;
			iv[i][j] = power(a[i][j],MOD - 2);
		}
	for (int i = 0;i < n;i++)
		c[i] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			(c[j] *= a[i][j]) %= MOD;
	for (int S = 0;S < (1 << n);S++)
	{
		for (int i = 0;i < n;i++)
		{
			r[i] = 1;
			for (int j = 0;j < n;j++)
				if (~S >> j & 1)
					(r[i] *= a[i][j]) %= MOD;
		}
		for (int d1 = 0;d1 <= 1;d1++)
			for (int d2 = 0;d2 <= 1;d2++)
			{
				int res = ((d1 + d2) & 1) ? -1 : 1;
				for (int i = 0;i < n;i++)
				{
					if (S >> i & 1)
						(res *= -c[i]) %= MOD;
					else
					{
						if (d1)
							(res *= a[i][i]) %= MOD;
						if (d2 && (!d1 || n - i - 1 != i))
							(res *= a[n - i - 1][i]) %= MOD;
					}
				}
				for (int i = 0;i < n;i++)
				{
					int val = r[i];
					if (d1 && ~S >> i & 1)
						(val *= iv[i][i]) %= MOD;
					if (d2 && ~S >> (n - 1 - i) & 1 && (!d1 || n - 1 - i != i || S >> i & 1))
						(val *= iv[i][n - i - 1]) %= MOD;
					(res *= 1 - val) %= MOD;
				}
				(ans += res) %= MOD;
			}
	}
	printf("%d\n",(1 - ans + MOD) % MOD);
	return 0;
}