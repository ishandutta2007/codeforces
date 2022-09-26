#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

int T,n,m;
int k[MAXN];
int c[MAXN];

ll ans;
ll sum[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans = 0;
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			scanf("%d",&k[i]);
		sort(k + 1,k + n + 1);
		for (int i = 1;i <= m;i++)
			scanf("%d",&c[i]);
		for (int i = 1;i <= n;i++)
			sum[i] = sum[i - 1] + c[k[i]];
		ll tot = 0;
		ans = 1e18;
		int MIN = 1e9;
		for (int i = n,j = m;i >= 1;i--)
		{
			MIN = min(MIN,k[i] - i);
			if (MIN < -i + 1)
				break;
			tot += c[n - i + 1];
			ans = min(ans,sum[i - 1] + tot);
		}
		printf("%lld\n",ans);
	}
	return 0;
}