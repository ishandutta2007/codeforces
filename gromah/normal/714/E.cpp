#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 3000 + 5
#define INF 1234567890987654321LL

int n, size, A[N], B[N], C[N];
LL Min, Dp[N][N], T[N][N];

inline LL Abs(LL x)
{
	return x > 0 ? x : -x;
}

inline LL Modify(int id, int x, LL k)
{
	for (; x <= n; x += (x & -x))
		T[id][x] = min(T[id][x], k);
}

inline LL Query(int id, int x)
{
	LL res = INF;
	for (; x; x -= (x & -x))
		res = min(res, T[id][x]);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		A[i] -= i;
		B[i] = A[i];
	}
	sort(B + 1, B + n + 1);
	size = unique(B + 1, B + n + 1) - B - 1;
	for (int i = 1; i <= n; i ++)
		C[i] = lower_bound(B + 1, B + size + 1, A[i]) - B;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			T[i][j] = INF;
	for (int i = 1; i <= n; i ++)
		for (int j = i; j; j --)
		{
			if (i == j)
			{
				LL extra = 0;
				Dp[i][i] = Query(i - 1, C[i]);
				for (int k = i - 1; k; k --)
				{
					extra += Abs(A[i] - A[k]);
					Dp[i][i] = min(Query(k - 1, C[i]) + extra, Dp[i][i]);
				}
			}
			else
			{
				Dp[i][j] = Dp[i - 1][j] + Abs(A[i] - A[j]);
			}
			Modify(i, C[j], Dp[i][j]);
		}
	Min = Dp[n][1];
	for (int i = 2; i <= n; i ++)
		Min = min(Min, Dp[n][i]);
	printf("%I64d\n", Min);
	return 0;
}