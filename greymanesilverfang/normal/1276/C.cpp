#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
const int N = 5e5;
int a[N], val[N];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	std::unordered_map<int,int> cnt;
	for (int i = 1; i <= n; ++i)
		++val[++cnt[a[i]]];
	for (int i = 1; i <= n; ++i)
		val[i] += val[i - 1];
	int max = 0, h = 0, w = 0;
	for (int i = 1; i <= n / i; ++i)
	{
		int j = val[i] / i;
		if (i <= j && max <= i * j)
		{
			max = i * j;
			h = i;
			w = j;
		}
	}
	std::vector<std::vector<int>> res(h + 1);
	for (int i = 1; i <= h; ++i)
		res[i] = std::vector<int>(w + 1);
	std::sort(a + 1, a + n + 1, [&](int x, int y){
		if (cnt[x] != cnt[y])
			return cnt[x] > cnt[y];
		return x < y;
	});
	int x = 1, y = 1;
	for (int i = 1; i <= n; ++i)
		if (i <= h || a[i - h] != a[i])
		{
			res[x][y] = a[i];
			x == h ? x = 1 : ++x;
			y == w ? y = 1 : ++y;
			if (res[x][y] != 0)
				x == h ? x = 1 : ++x;
			if (res[x][y] != 0)
				break;
		}
	printf("%d\n%d %d\n", max, h, w);
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}