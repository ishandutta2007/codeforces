#include <iostream>
#include <set>

long long f(int n, int gap)
{
	int cnt = n / gap;
	return 1LL * n * (cnt - 1) / 2 + cnt;
}

int main()
{
	int n; std::cin >> n;
	std::set<long long> res;
	for (int i = 1; i <= n / i; ++i)
		if (n % i == 0)
		{
			res.insert(f(n, i));
			res.insert(f(n, n / i));
		}
	for (long long x : res)
		std::cout << x << ' ';
	return 0;
}