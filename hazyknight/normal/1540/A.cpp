#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
int T,n;
int d[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&d[i]);
		sort(d + 1,d + n + 1);
		ll ans = d[n];
		for (int i = 1;i < n;i++)
			ans -= (ll)(d[i + 1] - d[i]) * i * (n - i);
		printf("%lld\n",ans);
	}
	return 0;
}