#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int T,n;

ll k;
ll a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld",&n,&k);
		for (int i = 1;i <= n;i++)
			scanf("%lldd",&a[i]);
		sort(a + 1,a + n + 1);
		ll g = 0;
		for (int i = 1;i < n;i++)
			g = __gcd(g,a[i + 1] - a[i]);
		if ((a[1] - k) % g == 0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}