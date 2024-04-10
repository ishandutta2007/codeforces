#include <iostream>
const int N = 1e6+2, INF = 998244353;
long long f[N], g[N];

int main()
{
	int n; std::cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		f[i] = f[i - 1] * i % INF;
	g[n + 1] = 1;
	for (int i = n; i >= 1; --i)
		g[i] = g[i + 1] * i % INF;
	long long res = 1;
	for (int i = 1; i <= n; ++i)
		res += (f[i] - 1) * g[i + 1] % INF;
	std::cout << res % INF;
	return 0;
}