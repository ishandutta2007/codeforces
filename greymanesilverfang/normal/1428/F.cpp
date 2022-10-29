#include <cstdio>
#include <vector>
#include <algorithm>
const int MAX = 6e5;
char s[MAX];

int main()
{
	int n; scanf("%d%s", &n, &s[1]);
	std::vector<std::pair<int,int>> v;
	long long res = 0, sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == '1')
		{
			std::pair<int,int> p(i, 1);
			if (s[i - 1] == '1')
			{
				p = v.back();
				++p.second;
				while (!v.empty() && p.second > v.back().second)
					v.pop_back();
			}
			if (!v.empty())
				sum += p.first - v.back().first + p.second * 2 - v.back().second - 1;
			else
				sum += i;
			v.push_back(p);
		}
		res += sum;
	}
	printf("%lld\n", res);
}