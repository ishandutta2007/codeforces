#include <iostream>

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		std::string s; std::cin >> s;
		int res = 0;
		for (int i = 0; i + 5 <= s.length(); ++i)
			if (s.substr(i, 5) == "twone")
				s[i + 2] = '$', ++res;
		for (int i = 0; i + 3 <= s.length(); ++i)
			if (s.substr(i, 3) == "one" || s.substr(i, 3) == "two")
				s[i + 1] = '$', ++res;
		std::cout << res << std::endl;
		for (int i = 0; i < s.length(); ++i)
			if (s[i] == '$')
				std::cout << i + 1 << " ";
		std::cout << std::endl;
	}
}