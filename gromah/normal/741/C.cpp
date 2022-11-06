#include <cstdio>
#define N 200000 + 5

int n, A[N], Col[N], E[N][2];

int main()
{
	scanf("%d", &n);
	for (int i = 1, u, v; i <= n; i ++)
	{
		scanf("%d%d", &u, &v);
		u --, v --;
		A[u] = v, A[v] = u;
		E[i][0] = u, E[i][1] = v;
	}
	for (int i = 0; i < 2 * n; i ++)
	{
		if (Col[i]) continue ;
		Col[i] = 1, Col[i ^ 1] = -1;
		for (int j = A[i ^ 1]; j != i; j = A[j ^ 1])
			Col[j] = 1, Col[j ^ 1] = -1;
	}
	for (int i = 1; i <= n; i ++)
		printf("%d %d\n", Col[E[i][0]] == 1 ? 1 : 2, Col[E[i][1]] == 1 ? 1 : 2);
	return 0;
}