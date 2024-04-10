#include <iostream>

int main()
{
	int a, b, c, d; std::cin >> a >> b >> c >> d;
	std::cout << (a == d && (a != 0 || c == 0));
	return 0;
}