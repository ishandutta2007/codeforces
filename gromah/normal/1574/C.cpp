#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, m;
LL sum, x, y, A[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", A + i);
	sort(A + 1, A + n + 1);
	for (int i = 1; i <= n; i ++)
		sum += A[i];
	for (scanf("%d", &m); m; m --)
	{
		scanf("%lld%lld", &x, &y);
		int pos = lower_bound(A + 1, A + n + 1, x) - A;
		LL ans = 2123456789123456789LL;
		if (pos > 1)
		{
			LL tmp = x - A[pos - 1] + max(0LL, y - (sum - A[pos - 1]));
			ans = min(ans, tmp);
		}
		if (pos <= n)
		{
			LL tmp = max(0LL, y - (sum - A[pos]));
			ans = min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}