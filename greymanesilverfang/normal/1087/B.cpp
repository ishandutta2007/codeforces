#include <iostream>

int main()
{
	int n, k; std::cin >> n >> k;
	for (int a = k - 1; a >= 1; --a)
		if (n % a == 0)
		{
			std::cout << n / a * k + a;
			break;
		}
	return 0;
}