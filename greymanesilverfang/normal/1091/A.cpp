#include <iostream>

int main()
{
	int l, mid, r; std::cin >> l >> mid >> r;
	std::cout << std::min(std::min(l + 1, r - 1), mid) * 3;
	return 0;
}