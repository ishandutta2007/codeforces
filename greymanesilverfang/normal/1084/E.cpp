#include <iostream>

int main()
{
	int n, k; std::cin >> n >> k;
	std::string s, t; std::cin >> s >> t;
	long long rs = 0, rt = 0, res = 0;
	for (int i = 1; i <= n; ++i)
	{
		(rs *= 2) += s[i - 1] - 'a';
		(rt *= 2) += t[i - 1] - 'a';
		if (rt - rs + 1 >= k)
		{
			std::cout << res + 1LL * (n - i + 1) * k;
			return 0;
		}
		res += rt - rs + 1;
	}
	std::cout << res;
	return 0;
}