#include <cstdio>
#include <vector>

const int MN = 1e5 + 100;
int N;
std::vector<int> a[MN];

bool parity[2];
int ln[MN];
void dfs(int n, bool d = 0, int p = 0)
{
	if(a[n].size() == 1)
		parity[d] = 1, ++ln[a[n][0]];
	for(int x : a[n])
		if(x != p)
			dfs(x, d^1, n);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x, y;i < N-1;++i)
		scanf("%d%d", &x, &y), a[x].push_back(y), a[y].push_back(x);
	dfs(1);
	if(parity[0] && parity[1]) printf("3 ");
	else printf("1 ");
	int ans = N-1;
	for(int i = 1;i <= N;++i)
		if(ln[i])
			ans -= ln[i]-1;
	printf("%d\n", ans);
	return 0;
}