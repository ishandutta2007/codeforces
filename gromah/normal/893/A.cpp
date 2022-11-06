#include <cstdio>

int n;

bool dfs(int x, int a, int b, int c)
{
	if (x == 0) return 1;
	int cur;
	scanf("%d", &cur);
	if (cur == c) return 0;
	else if (cur == a) return dfs(x - 1, a, c, b);
	else return dfs(x - 1, c, b, a);
}

int main()
{
	scanf("%d", &n);
	bool ok = dfs(n, 1, 2, 3);
	puts(ok ? "YES" : "NO");
	return 0;
}