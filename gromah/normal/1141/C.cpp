#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, Max, A[N], Ord[N];
bool ok = true;

int main()
{
	scanf("%d", &n);
	for (int i = 2, x; i <= n; i ++)
	{
		scanf("%d", &x);
		A[i] = A[i - 1] + x;
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + n + 1, [](int u, int v) {
		return A[u] < A[v];
	});
	for (int i = 2; ok && i <= n; i ++)
		ok = A[Ord[i]] == A[Ord[i - 1]] + 1;
	if (!ok) puts("-1");
	else for (int i = 1; i <= n; i ++)
		printf("%d%c", A[i] - A[Ord[1]] + 1, i == n ? '\n' : ' ');
	return 0;
}