#include <cstdio>
#include <vector>
#include <algorithm>
const int MAX = 2e5;
char s[MAX];

void solve()
{
	int n, k; scanf("%d%d%s", &n, &k, s + 1);
	int cnt = 0, L = -1;
	std::vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		if (s[i] == 'W')
			++cnt;
		if (s[i] == 'L' && s[i - 1] == 'W')
			L = i;
		if (s[i] == 'W' && s[i - 1] == 'L' && L != -1)
			v.push_back(i - L);
	}
	cnt = std::min(cnt + k, n);
	if (cnt == 0)
	{
		printf("0\n");
		return;
	}
	std::sort(v.begin(), v.end(), [&](int x, int y){
		return x > y;
	});
	while (!v.empty() && v.back() <= k)
	{
		k -= v.back();
		v.pop_back();
	}
	printf("%d\n", cnt * 2 - 1 - v.size());
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve();
}