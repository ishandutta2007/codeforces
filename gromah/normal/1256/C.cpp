#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, m, d, last, C[N], Suf[N], Pos[N], Col[N];

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= m; i ++)
		scanf("%d", C + i);
	for (int i = m; i; i --)
		Suf[i] = Suf[i + 1] + C[i];
	for (int i = 1; i <= m; i ++)
	{
		Pos[i] = min(last + d, n + 1 - Suf[i]);
		last = Pos[i] + C[i] - 1;
	}
	if (last + d <= n)
		puts("NO");
	else
	{
		puts("YES");
		for (int i = 1; i <= m; i ++)
			for (int j = 0; j < C[i]; j ++)
				Col[Pos[i] + j] = i;
		for (int i = 1; i <= n; i ++)
			printf("%d%c", Col[i], i == n ? '\n' : ' ');
	}
	return 0;
}