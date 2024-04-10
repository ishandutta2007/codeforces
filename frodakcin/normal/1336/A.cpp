#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int MN = 2e5 + 100;
using ll = long long;
std::vector<int> a[MN];
int N, K;
int d[MN], s[MN];

int val[MN];
int dfs(int n, int p = 0)
{
	s[n] = 1;
	for(int x : a[n])
		if(x != p)
			d[x] = d[n]+1, s[n] += dfs(x, n);
	val[n] = d[n] - s[n];
	return s[n];
}
ll v;
int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i = 0, x, y;i < N-1;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	d[1] = 1;
	dfs(1);
	std::sort(val+1, val+N+1, std::greater<int>());
	for(int i = 1;i <= K;++i)
		v += val[i];
	printf("%lld\n", v);
	return 0;
}