#include <cstdio>
#include <vector>
const int N = 1e6+5;
int come[N], left[N];

int main()
{
	int n; scanf("%d", &n);
	int day = 1;
	std::vector<int> ans(1, -1);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int x; scanf("%d", &x);
		if (x > 0)
			if (come[x] < day)
			{
				++count;
				come[x] = day;
			}
			else 
			{
				printf("-1");
				return 0;
			}
		else 
		{
			x = -x;
			if (come[x] != day || left[x] == day)
			{
				printf("-1");
				return 0;
			}
			else 
			{
				--count;
				left[x] = day;
			}
		}
		if (count == 0)
		{
			++day;
			ans.push_back(i);
		}
	}
	if (count != 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n", --day);
	for (int i = 1; i <= day; ++i)
		printf("%d ", ans[i] - ans[i - 1]);
}