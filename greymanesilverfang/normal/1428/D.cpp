#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
const int MAX = 2e5;
int a[MAX], prv[MAX];

int main()
{
	int n; scanf("%d", &n);
	std::stack<int> st2, st3;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] == 3)
		{
			if (!st3.empty())
			{
				prv[i] = st3.top();
				st3.pop();
			}
			st3.push(i);
			continue;
		}
		if (a[i] == 2)
		{
			if (!st3.empty())
			{
				prv[i] = st3.top();
				st3.pop();
			}
			st2.push(i);
			continue;
		}
		if (a[i] == 1)
		{
			if (!st2.empty())
			{
				prv[i] = st2.top();
				st2.pop();
				continue;
			}
			if (!st3.empty())
			{
				prv[i] = st3.top();
				st3.pop();
				continue;
			}
		}
	}
	if (!(st2.empty() && st3.empty()))
	{
		printf("-1\n");
		return 0;
	}
	std::vector<std::pair<int,int>> res;
	int cur = n;
	for (int i = 1; i <= n; ++i)
	{
		int tmp = i;
		if (a[i] == 1)
			if (prv[i] == 0)
			{
				res.push_back({cur, i});
				--cur;
			}
			else
				while (prv[i] != 0)
				{
					if (a[i] == 1 && a[prv[i]] == 3)
					{
						res.push_back({cur, i});
						--cur;
					}
					res.push_back({cur, i});
					res.push_back({cur, prv[i]});
					--cur;
					i = prv[i];
				}
		i = tmp;
	}
	printf("%d\n", res.size());
	for (auto p : res)
		printf("%d %d\n", p.first, p.second);
}