#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define Mod 1000000007

int k, _a, _b, a, b, Inv_b, ans, Dp[N][N];

int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1)
	{
		if (v & 1) res = 1LL * res * u % Mod;
		u = 1LL * u * u % Mod;
	}
	return res;
}

int Inc(int u, int v)
{
	return u + v - (u + v >= Mod ? Mod : 0);
}

int main()
{
	scanf("%d%d%d", &k, &_a, &_b);
	a = 1LL * _a * Power(_a + _b, Mod - 2) % Mod;
	b = 1LL * _b * Power(_a + _b, Mod - 2) % Mod;
	Inv_b = Power(b, Mod - 2);
	Dp[1][0] = 1;
	for (int i = 1; i <= k; i ++)
		for (int j = 0; j <= k; j ++)
		{
			if (i + j < k)
				Dp[i][i + j] = Inc(Dp[i][i + j], 1LL * Dp[i][j] * b % Mod);
			else if (i < k)
				ans = Inc(ans, 1LL * Dp[i][j] * b % Mod * (i + j) % Mod);
			if (i < k)
				Dp[i + 1][j] = Inc(Dp[i + 1][j], 1LL * Dp[i][j] * a % Mod);
			else ans = Inc(ans, 1LL * Dp[i][j] * (k + j + 1LL * a * Inv_b % Mod) % Mod);
		}
	printf("%d\n", ans);
	return 0;
}