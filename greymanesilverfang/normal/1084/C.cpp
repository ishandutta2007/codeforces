#include <iostream>
const int INF = 1e9+7;

int main()
{
	std::string s; std::cin >> s;
	int cnt = 1, res = 1;
	for (char c : s)
		switch (c)
		{
		case 'a':
			(res += cnt) %= INF;
			break;
		case 'b':
			cnt = res;
			break;
		}
	std::cout << res - 1;
	return 0;
}