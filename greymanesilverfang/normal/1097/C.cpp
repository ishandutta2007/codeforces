#include <algorithm>
#include <iostream>
#define _cnt(i) cnt[(i) + 500000]
int f[500001], cnt[1000001];

int main()
{
	int n; std::cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		std::string bracket; std::cin >> bracket;
		int len = bracket.length(), min = 0;
		for (int i = 1; i <= len; ++i)
			min = std::min(min, f[i] = f[i - 1] + (bracket[i - 1] == '(' ? 1 : -1));
		if (min != f[0] && min != f[len])
			continue;
		int score = f[0] - f[len];
		if (_cnt(-score) > 0)
		{
			--_cnt(-score);
			++res;
		}
		else 
			++_cnt(score);
	}
	std::cout << res;
	return 0;
}