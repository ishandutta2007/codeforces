#include <cstdio>
#include <set>

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	std::set<int> s;
	for (int i = 1; i <= n; ++i)
	{
		int a; scanf("%d", &a);
		if (a != 0)
			s.insert(a);
	}
	int cur = 0;
	for (int i = 1; i <= k; ++i)
		if (!s.empty())
		{
			printf("%d\n", *s.begin() - cur);
			cur = *s.begin();
			s.erase(s.begin());
		}
		else 
			printf("0\n");
	return 0;
}