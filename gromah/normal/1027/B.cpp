#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int n, q;
LL ans;

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1, x, y; i <= q; i ++)
	{
		scanf("%d%d", &x, &y);
		ans = 0;
		if (x + y & 1)
		{
			ans += (1LL * n * n + 1 >> 1);
			int r = x - 1 >> 1;
			ans += 1LL * r * n;
			if (x & 1)
				ans += y >> 1;
			else ans += (n >> 1) + (y + 1 >> 1);
		}
		else
		{
			int r = x - 1 >> 1;
			ans += 1LL * r * n;
			if (x & 1)
				ans += (y + 1) >> 1;
			else ans += (n + 1 >> 1) + (y >> 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}