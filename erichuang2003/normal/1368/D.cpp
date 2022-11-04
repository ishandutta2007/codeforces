#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n,a;
int cnt[20];
int b[MAXN];

ll ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		for (int j = 19;j >= 0;j--)
			if (a >> j & 1)
				cnt[j]++;
	}
	for (int i = 0;i <= 19;i++)
		for (int j = 1;j <= cnt[i];j++)
			b[j] += 1 << i;
	for (int i = 1;i <= n;i++)
		ans += (ll)b[i] * b[i];
	printf("%lld\n",ans);
	return 0;
}