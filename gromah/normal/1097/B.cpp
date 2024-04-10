#include <cstdio>
#include <algorithm>
using namespace std;

int n, A[16];

bool dfs(int dep, int cur)
{
	if (dep > n)
	{
		return cur % 360 == 0;
	}
	if (dfs(dep + 1, cur + A[dep])) return 1;
	if (dfs(dep + 1, cur - A[dep])) return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	bool ok = dfs(1, 0);
	puts(ok ? "YES" : "NO");
	return 0;
}