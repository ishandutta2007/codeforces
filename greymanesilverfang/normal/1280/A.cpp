#include <iostream>
const int MOD = 1e9+7;

int main()
{
	int t; std::cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int x; std::cin >> x;
		std::string s; std::cin >> s;
		long long res = s.length();
		for (int l = 1; l <= x; ++l)
		{
			res = (res + (res + MOD - l) * (s[l - 1] - '1')) % MOD;
			if (s.length() < x)
			{
				std::string tmp = s.substr(l, s.length());
				for (int i = '1'; i < s[l - 1]; ++i)
					s += tmp;
			}
		}
		std::cout << res << std::endl;
	}
}