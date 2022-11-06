#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000 + 5

int n, ans, A[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int l = 1, r, Max; l <= n; l = r + 1)
	{
		for (Max = A[l], r = l; r <= n && Max > r; Max = max(Max, A[++ r])) ;
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}