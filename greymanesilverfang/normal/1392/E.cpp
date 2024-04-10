#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 30;
long long a[N][N];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i % 2 == 1)
				a[i][j] = 0;
			else
				a[i][j] = 1LL << i + j - 3;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%lld ", a[i][j]);
		printf("\n");
		fflush(stdout);
	}
	int q; scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		long long k; scanf("%lld", &k);
		std::vector<std::pair<int,int>> v(1, std::make_pair(1, 1));
		int cur = 0;
		while (v.back() != std::make_pair(n, n))
		{
			v.push_back(v.back());
			if (v.back().second == n || a[v.back().first][v.back().second + 1] >> cur & 1 ^ k >> cur & 1)
				++v.back().first;
			else 
				++v.back().second;
			++cur;
		}
		for (std::pair<int,int> p : v)
		{
			printf("%d %d\n", p.first, p.second);
			fflush(stdout);
		}
	}
}