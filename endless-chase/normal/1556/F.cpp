#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod = 1e9 + 7;
int test, n, a[22], pro[22][22], dp[(1 << 14) + 10], res[(1 << 14) + 10], pp[22], msk, cur;
int binpow(int a, int t)
{
	int res = 1, p = a;
	for (int i = t; i; i >>= 1)
	{
		if (i & 1) res = 1ll * res * p % mod;
		p = 1ll * p * p % mod;
	}
	return res;
}
int main()
{
	test = 1;
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				pro[i][j] = 1ll * a[i] * binpow(a[i] + a[j], mod - 2) % mod;
			}
		}
		for (int i = 1; i < (1 << n); i++) dp[i] = 1;
		for (int i = 1; i < (1 << n); i++)
		{
			for (int j = 0; j < n; j++)
			{
				pp[j] = 1;
				for (int k = 0; k < n; k++)
				{
					if (i & (1 << k)) pp[j] = 1ll * pp[j] * pro[k][j] % mod;
				}
			}
			msk = (1 << n) - 1 - i;
			for (int j = msk; j; j = (j - 1) & msk)
			{
				cur = 1;
				for (int k = 0; k < n; k++)
				{
					if (j & (1 << k)) cur = 1ll * cur * pp[k] % mod;
				}
				dp[i | j] = (-1ll * dp[i] * cur + dp[i | j]) % mod;
			}
		}
		for (int i = 1; i < (1 << n); i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i & (1 << j)) res[i] ++;
			}
			res[i] = 1ll * res[i] * dp[i] % mod;
		}
		for (int i = 1; i < (1 << n); i++)
		{
			for (int j = 0; j < n; j++)
			{
				pp[j] = 1;
				for (int k = 0; k < n; k++)
				{
					if (i & (1 << k)) pp[j] = 1ll * pp[j] * pro[k][j] % mod;
				}
			}
			msk = (1 << n) - 1 - i;
			for (int j = msk; j; j = (j - 1) & msk)
			{
				cur = 1;
				for (int k = 0; k < n; k++)
				{
					if (j & (1 << k)) cur = 1ll * cur * pp[k] % mod;
				}
				res[i | j] = (1ll * res[i] * cur % mod * dp[j] + res[i | j]) % mod;
			}
		}
		printf("%d\n", (res[(1 << n) - 1] + mod) % mod);
	}
	return Accepted;
}