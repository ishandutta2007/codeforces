#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000000 + 5

int Case, n, nz, ans, Cnt[N], TC[N], SC[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			Cnt[i] = TC[i] = SC[i] = 0;
		for (int i = 1, x; i <= n; i ++)
		{
			scanf("%d", &x);
			Cnt[x] ++;
		}
		nz = 0;
		for (int i = 1; i <= n; i ++)
			if (Cnt[i])
				TC[Cnt[i]] ++, nz ++;
		for (int i = 1; i <= n; i ++)
			SC[i] = SC[i - 1] + TC[i];
		ans = n;
		for (int s = 2; s <= n; s ++)
		{
			int cnz = 0, tmp = 0;
			for (int i = 1, last_r = 1; last_r <= n; i ++)
			{
				int l = max(i * (s - 1), last_r), r = min(i * s, n);
				if (l <= r)
				{
					cnz += SC[r] - SC[l - 1];
					tmp += (SC[r] - SC[l - 1]) * i;
				}
				last_r = r + 1;
			}
			if (cnz == nz)
				ans = min(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}