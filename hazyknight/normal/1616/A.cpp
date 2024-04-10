#include <bits/stdc++.h>

using namespace std;

int T,n;
int cnt[205];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i <= 200;i++)
			cnt[i] = 0;
		for (int a,i = 1;i <= n;i++)
		{
			scanf("%d",&a);
			if (!cnt[a + 100])
				cnt[a + 100] = 1;
			else
				cnt[-a + 100] = 1;
		}
		int ans = 0;
		for (int i = 0;i <= 200;i++)
			ans += cnt[i];
		printf("%d\n",ans);
	}
	return 0;
}