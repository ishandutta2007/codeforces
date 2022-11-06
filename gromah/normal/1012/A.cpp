#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N << 1];
LL ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i ++)
		scanf("%d", A + i);
	sort(A + 1, A + 2 * n + 1);
	ans = 1LL * (A[n] - A[1]) * (A[2 * n] - A[n + 1]);
	for (int i = 2; i <= n; i ++)
	{
		LL tmp = 1LL * (A[2 * n] - A[1]) * (A[i + n - 1] - A[i]);
		ans = min(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}