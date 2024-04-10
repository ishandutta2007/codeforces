#include <cstdio>
#include <vector>
#include <algorithm>

void solve()
{
	int n; scanf("%d", &n);
	std::vector<int> a;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		int x; scanf("%d", &x);
		a.push_back(x);
		sum += x;
	}
	if (sum == 0)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	std::sort(a.begin(), a.end(), [&](int x, int y){
		return x * sum > y * sum;
	});
	for (int x : a)
		printf("%d ", x);
	printf("\n");
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve();
}