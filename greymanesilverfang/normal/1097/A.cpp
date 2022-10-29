#include <iostream>

int main()
{
	std::string table; std::cin >> table;
	for (int i = 1; i <= 5; ++i)
	{
		std::string hand; std::cin >> hand;
		if (table[0] == hand[0] || table[1] == hand[1])
		{
			std::cout << "YES";
			return 0;
		}
	}
	std::cout << "NO";
	return 0;
}