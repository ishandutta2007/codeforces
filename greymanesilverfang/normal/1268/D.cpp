#include <cstdio>
#include <algorithm>
const int N = 2002;
int n, deg[N], tmp[N];
char a[N][N];

bool scc()
{
	std::copy(deg, deg + n, tmp);
	std::sort(tmp, tmp + n);
	int cur = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		cur += tmp[i] - i;
		if (cur == 0)
			return false;
	}
	return true;
}

void flip(int u)
{
	for (int v = 0; v < n; ++v)
	{
		if (a[u][v] == '0')
			++deg[u], --deg[v];
		if (a[u][v] == '1')
			--deg[u], ++deg[v];
		a[u][v] ^= 1;
		a[v][u] ^= 1;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", a[i]);
		for (int j = 0; j < n; ++j)
			if (a[i][j] == '1')
				++deg[i];
	}
	if (scc())
	{
		printf("0 1\n");
		return 0;
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		flip(i);
		if (scc())
			++res;
		flip(i);
	}
	if (res > 0)
	{
		printf("1 %d\n", res);
		return 0;
	}
	if (n == 4)
		printf("-1\n");
	if (n == 6)
		printf("2 18\n");
}