#include <cstdio>
#include <map>
const int N = 2e6;
int sum[N];

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n; scanf("%d", &n);
		std::map<int,int> pos;
		pos[0] = 0;
		for (int i = 1; i <= 2 * n; ++i)
		{
			int a; scanf("%d", &a);
			sum[i] = sum[i - 1] + (3 - a * 2);
			if (i <= n)
				pos[sum[i]] = i;
		}
		int ans = 2 * n;
		for (int i = n; i <= 2 * n; ++i)
		{
			auto it = pos.find(sum[i] - sum[2 * n]);
			if (it != pos.end())
				ans = std::min(ans, i - it->second);
		}
		printf("%d\n", ans);
	}
}