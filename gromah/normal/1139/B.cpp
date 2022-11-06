#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define INF 0x7fffffff

int n, A[N];
LL ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = n, ret = INF; i; i --)
	{
		ret = max(min(A[i], ret - 1), 0);
		ans += ret;
	}
	printf("%lld\n", ans);
	return 0;
}