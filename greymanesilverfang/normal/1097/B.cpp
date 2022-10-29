#include <bitset>
#include <iostream>

int main()
{
	int n; std::cin >> n;
	std::bitset<360> dp;
	dp.flip(0);
	for (int i = 1; i <= n; ++i)
	{
		int a; std::cin >> a;
		dp = dp >> a | dp >> 360 - a
		   | dp << a | dp << 360 - a;
	}
	if (dp[0])
		std::cout << "YES";
	else 
		std::cout << "NO";
	return 0;
}