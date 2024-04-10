#include <iostream>
const int N = 2001, INF = 1e9+7;
long long g[N][N], f[N][N];

int main()
{
	int n, k; std::cin >> n >> k;
	std::string s; std::cin >> s;
	f[0][0] = g[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= k; ++j)
		{
			g[i][j] = f[i - 1][j] * (s[n - i] - 'a') + g[i - 1][j];
			f[i][j] = g[i][j];
			for (int p = 1; p <= i + 1 - p && p * (i + 1 - p) <= j; ++p)
			{
				f[i][j] += f[i - p][j - p * (i + 1 - p)] * ('z' - s[n - i + p - 1]);
				if (p < i + 1 - p)
					f[i][j] += f[p - 1][j - p * (i + 1 - p)] * ('z' - s[n - p]);
			}
			g[i][j] %= INF;
			f[i][j] %= INF;
		}
	std::cout << f[n][k];
	return 0;
}