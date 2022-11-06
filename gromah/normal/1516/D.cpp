#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define LOGN 18

int n, q, g1cnt, A[N], F[N], Q[N], Cnt[N], Go[N][LOGN];

void Prepare()
{
	F[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!F[i])
			Q[++Q[0]] = F[i] = i;
		for (int j = 1; j <= Q[0] && i * Q[j] < N; j++)
		{
			F[i * Q[j]] = Q[j];
			if (i % Q[j] == 0)
				break;
		}
	}
}

inline void Add(int x, int k)
{
	g1cnt -= Cnt[x] > 1;
	Cnt[x] += k;
	g1cnt += Cnt[x] > 1;
}

int main()
{
	Prepare();
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", A + i);
	for (int i = 1, l = 1; i <= n; i++)
	{
		for (int x = A[i], last = 0; x > 1; last = F[x], x /= F[x])
			if (F[x] != last)
				Add(F[x], 1);
		for (; g1cnt; l ++)
			for (int x = A[l], last = 0; x > 1; last = F[x], x /= F[x])
				if (F[x] != last)
					Add(F[x], -1);
		Go[i][0] = l - 1;
	}
	for (int t = 1; t < LOGN; t++)
		for (int i = 1; i <= n; i++)
			Go[i][t] = Go[Go[i][t - 1]][t - 1];
	for (int i = 1, l, r; i <= q; i++)
	{
		scanf("%d%d", &l, &r);
		int ans = 1;
		for (int t = LOGN - 1; t >= 0; t--)
			if (Go[r][t] >= l)
				r = Go[r][t], ans += (1 << t);
		printf("%d\n", ans);
	}

	return 0;
}