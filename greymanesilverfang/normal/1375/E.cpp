#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 2000;
int a[N], b[N];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		b[i] = i;
	std::sort(b, b + n, [](int x, int y)->bool{
		return std::make_pair(a[x], x) > std::make_pair(a[y], y);
	});
	std::vector<std::pair<int,int>> ans;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < b[i]; ++j)
			if (a[j] > a[b[i]])
				ans.emplace_back(j, b[i]);
	printf("%d\n", ans.size());
	for (std::pair<int,int> p : ans)
		printf("%d %d\n", p.first + 1, p.second + 1);
}