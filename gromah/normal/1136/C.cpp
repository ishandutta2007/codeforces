#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5

int n, m, sz, A[N][N], B[N][N], T[N], P[N];
bool ok = true;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", A[i] + j);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			scanf("%d", B[i] + j);
	for (int t = 2; ok && t <= n + m; t ++)
	{
		sz = 0;
		for (int i = 1; i <= n; i ++)
			if (1 <= t - i && t - i <= m)
				sz ++, T[sz] = A[i][t - i], P[sz] = B[i][t - i];
		sort(T + 1, T + sz + 1);
		sort(P + 1, P + sz + 1);
		for (int i = 1; ok && i <= sz; i ++)
			ok = T[i] == P[i];
	}
	puts(ok ? "YES" : "NO");
	return 0;
}