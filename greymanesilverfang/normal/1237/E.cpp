#include <iostream>

bool isp4(int x) // is power of 4
{
	return __builtin_popcount(x) == 1 && __builtin_clz(x) & 1;
}

int main()
{
	int n; std::cin >> n;
	std::cout << (isp4(3 * n + 1) || isp4(3 * n + 4) || isp4(6 * n + 4) || isp4(6 * n + 10)) ? 1 : 0;
}