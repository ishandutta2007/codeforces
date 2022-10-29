#include <cstdio>
#include <vector>
const int N = 3e5;
char s[N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		int n; scanf("%d%s", &n, s + 1);
		std::vector<int> v;
		char cur = 'M'; // middle lol
		for (int i = 1; i <= n; ++i)
			if (s[i] != cur)
			{
				cur = s[i];
				v.push_back(1);
			}
			else
				++v.back();
		if (v.size() == 1)
			v.back() += 2;
		else if (s[1] == s[n])
		{
			v.front() += v.back();
			v.pop_back();
		}
		int ans = 0;
		for (int x : v)
			ans += x / 3;
		printf("%d\n", ans);
	}
}