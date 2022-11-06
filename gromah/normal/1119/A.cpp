#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, ans, A[N], PreMax[N], SufMax[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
	{
		PreMax[A[i]] = max(PreMax[A[i]], i);
		SufMax[A[i]] = max(SufMax[A[i]], i);
	}
	for (int i = 1; i <= n; i ++)
		PreMax[i] = max(PreMax[i - 1], PreMax[i]);
	for (int i = n; i; i --)
		SufMax[i] = max(SufMax[i + 1], SufMax[i]);
	for (int i = 1; i <= n; i ++)
		ans = max(ans, max(PreMax[A[i] - 1], SufMax[A[i] + 1]) - i);
	printf("%d\n", ans);
	return 0;
}