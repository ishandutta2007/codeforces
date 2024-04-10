#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define INF 0x3f3f3f3f

int m, a, b, Dis[N], Max[N];
LL ans;

int main()
{
	scanf("%d%d%d", &m, &a, &b);
	for (int i = 1; i < a; i ++)
		Max[i] = INF;
	for (int i = 0, nxt; i < a; i = nxt)
	{
		nxt = (i - b % a + a) % a;
		if (Max[nxt] != INF) break;
		Max[nxt] = b <= i ? Max[i] : max(Max[i], i + (b - i + a - 1) / a * a);
	}
	for (int i = 0; i < a; i ++)
	{
		if (Max[i] > m) continue ;
		int d = (m - i) / a, di = (Max[i] - i) / a;
		int t = di * a + i;
		ans += 1LL * (m - Max[i] + 1) * (di + 1);
		int k = d - di;
		ans += 1LL * k * (m - di * a - i + 1) - 1LL * k * (k + 1) / 2 * a;
	}
	printf("%lld\n", ans);
	return 0;
}