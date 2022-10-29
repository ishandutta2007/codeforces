#include <algorithm>
#include <iostream>
const int N = 1e5+1;
int n, m, a[N], c[N], idx[N];

long long buy(int type, int cnt)
{
	if (a[type] >= cnt)
	{
		a[type] -= cnt;
		return 1LL * cnt * c[type];
	}
	long long res = 1LL * a[type] * c[type];
	cnt -= a[type];
	a[type] = 0;
	if (type == idx[n])
		--n;
	return res + buy(idx[n], cnt); 
}

int main()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i];
	for (int i = 1; i <= n; ++i)
		idx[i] = i;
	std::sort(idx + 1, idx + n + 1, [](int lhs, int rhs){
		if (c[lhs] != c[rhs])
			return c[lhs] > c[rhs];
		return lhs > rhs;
	});
	long long cnt = 0;
	for (int i = 1; i <= m; ++i)
	{
		int t, d; std::cin >> t >> d;
		cnt += d;
		if (cnt <= sum)
			std::cout << buy(t, d) << std::endl;
		else
			std::cout << 0 << std::endl;
	}
	return 0;
}