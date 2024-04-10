#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 1000000 + 5

int n, m, k, C[N], Left[N];
bool Flag[N];
LL ans = -1;

int Calc(int step)
{
	if (Flag[0]) return -1;
	int ret = 0;
	for (int l = 0, r, last = 0; l < n; l = r, ret ++)
	{
		r = Left[min(l + step, n)];
		if (l == r)
			return -1;
	}
	return ret;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, x; i <= m; i ++)
	{
		scanf("%d", &x);
		Flag[x] = 1;
	}
	for (int i = 1; i <= n; i ++)
		Left[i] = Flag[i] ? Left[i - 1] : i;
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d", C + i);
		int t = Calc(i);
		if (~t && (!~ans || ans > 1LL * t * C[i]))
			ans = 1LL * t * C[i];
	}
	printf("%lld\n", ans);
	return 0;
}