#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[1111];
long long mn[1111][1111], pre[1111], ans, l, r;
void upd(long long ll, long long rr)
{
	l = max(l, ll);
	r = min(r, rr);
}
long long getmin(int l, int r)
{
	if (l > r) return 1e18;
	return mn[l][r];
}
int main()
{
	test = 1;
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (i & 1) pre[i] = pre[i - 1] + a[i];
			else pre[i] = pre[i - 1] - a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			mn[i][i] = pre[i];
			for (int j = i + 1; j <= n; j++)
			{
				mn[i][j] = min(mn[i][j - 1], pre[j]);
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0) continue;
			for (int j = i + 1; j <= n; j++)
			{
				if (j & 1) continue;
				l = -1e18; r = 1e18;
				upd(pre[i] - a[i], pre[i] - 1);
				upd(pre[j], pre[j] + a[j] - 1);
				upd(-1e18, getmin(i + 1, j - 1));
				if (l <= r) ans += (r - l + 1);
			}
		}
		printf("%lld\n", ans);
	}
	return Accepted;
}