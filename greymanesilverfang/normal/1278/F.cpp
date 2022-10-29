#include <cstdio>
#include <vector>
const int MOD = 998244353;

int add(int x, int y)
{
	int res = x + y;
	return res < MOD ? res : res - MOD;
}

int mul(int x, int y)
{
	return (long long) x * y % MOD;
}

int pow(int base, int p)
{
	int res = 1;
	while (p > 0)
	{
		if (p & 1)
			res = mul(res, base);
		base = mul(base, base);
		p /= 2;
	}
	return res;
}

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	std::vector<int> dp(std::min(k, n) + 1, 0); 
	dp[1] = n;
	for (int i = 2; i <= k; ++i)
		for (int j = std::min(i, n); j >= 1; --j)
			dp[j] = add(mul(dp[j - 1], n - j + 1), mul(dp[j], j));
	int res = 0;
	for (int i = 1; i < dp.size(); ++i)
		res = add(res, mul(dp[i], pow(pow(m, MOD - 2), i)));
	printf("%d\n", res);
}