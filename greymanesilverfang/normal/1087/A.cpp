#include <iostream>

int main()
{
	std::string t; std::cin >> t;
	std::string s;
	while (!t.empty())
		if (t.length() & 1)
		{
			s.insert(s.begin(), t.front());
			t.erase(t.begin());
		}
		else 
		{
			s.insert(s.begin(), t.back());
			t.erase(t.end() - 1);
		}
	std::cout << s;
	return 0;
}