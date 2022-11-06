#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5
#define mp make_pair

int n, ans, A[N], B[N];

inline bool cmp_0(int u, int v)
{
	return mp(A[u], -u) < mp(A[v], -v);
}

inline bool cmp_1(int u, int v)
{
	return mp(A[u] + B[u], -u) < mp(A[v] + B[v], -v);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", A + i, B + i);
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
		{
			if (B[i] * B[j] <= 0)
				ans += cmp_0(i, j) ^ cmp_1(i, j);
			else if (B[i] > 0)
			{
				int u = i, v = j;
				if (A[u] > A[v] || A[u] == A[v] && u < v)
					swap(u, v);
				if (A[u] + B[u] > A[v] || A[u] + B[u] == A[v] && u < v)
				{
					ans ++;
					if (cmp_1(u, v)) ans ++;
				}
			}
			else
			{
				int u = i, v = j;
				if (A[u] < A[v] || A[u] == A[v] && u > v)
					swap(u, v);
				if (A[u] + B[u] < A[v] || A[u] + B[u] == A[v] && u > v)
				{
					ans ++;
					if (cmp_1(v, u)) ans ++;
				}
			}
		}
	printf("%d\n", ans);
	return 0;
}