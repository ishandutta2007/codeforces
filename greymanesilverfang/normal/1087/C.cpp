#include <algorithm>
#include <iostream>

int main()
{
	std::pair<int,int> p[3];
	for (int i = 0; i < 3; ++i)
		std::cin >> p[i].first >> p[i].second;
	int minx = std::min(p[1].first, std::min(p[0].first, p[2].first)),
	    maxx = std::max(p[1].first, std::max(p[0].first, p[2].first));
	std::sort(p, p + 3);
	int miny = std::min(p[1].second, std::min(p[0].second, p[2].second)),
	    maxy = std::max(p[1].second, std::max(p[0].second, p[2].second));
	std::cout << maxx - minx + maxy - miny + 1;
	for (int i = miny; i <= maxy; ++i)
		std::cout << std::endl << p[1].first << ' ' << i;
	for (int i = minx; i <= p[1].first - 1; ++i)
		std::cout << std::endl << i << ' ' << p[0].second;
	for (int i = p[1].first + 1; i <= maxx; ++i)
		std::cout << std::endl << i << ' ' << p[2].second;
	return 0;
}