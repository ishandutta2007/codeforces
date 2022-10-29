#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
std::map<std::pair<std::string,int>,std::vector<int>> group_map;

int get_mask(std::string &s)
{
	int res = 0;
	for (char c : s)
		res |= 1 << c - 'a';
	return res;
}

int main()
{
	int n; std::cin >> n; 
	for (int i = 1; i <= n; ++i)
	{
		std::string s, t; std::cin >> s >> t;
		int mask = get_mask(t);
		while (!s.empty() && mask >> s.back() - 'a' & 1)
			s.pop_back();
		group_map[std::make_pair(s, mask)].push_back(i);
	}
	std::cout << group_map.size() << std::endl;
	for (auto p : group_map)
	{
		std::cout << p.second.size();
		for (int x : p.second)
			std::cout << ' ' << x;
		std::cout << std::endl;
	}
	return 0;
}