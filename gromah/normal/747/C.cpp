#include <cstdio>
#define N 100000 + 5
#define M 1000000 + 1000 + 5

int n, q, T[N], K[N], D[N], Del[M], Sum[N];
bool Flag[N];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1, cur = 1, sum = 0, t, k, d; i <= q; i ++)
	{
		scanf("%d%d%d", &t, &k, &d);
		T[i] = t, K[i] = k, D[i] = d;
		for (; cur <= t; cur ++)
			sum += Del[cur];
		if (sum + k <= n)
		{
			sum += k, Del[t + d] -= k;
			Flag[i] = 1;
		}
		else Sum[i] = -1;
	}
	for (int i = 1; i <= n; i ++)
	{
		int t = 1, last = 0;
		while (t <= q)
		{
			for (; t <= q && (!Flag[t] || T[t] < last || !K[t]); t ++) ;
			K[t] --, Sum[t] += i, last = T[t] + D[t];
		}
	}
	for (int i = 1; i <= q; i ++)
		printf("%d\n", Sum[i]);
	return 0; 
}