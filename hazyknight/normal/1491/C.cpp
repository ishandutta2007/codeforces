#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int T,n;
int S[MAXN];
long long f[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&S[i]);
			f[i] = 0;
		}
		long long ans = 0;
		for (int i = 1;i <= n;i++)
		{
			if (S[i] - f[i] > 1)
			{
				ans += S[i] - f[i] - 1;
				f[i] += S[i] - f[i] - 1;
			}
			for (int j = min(n,i + S[i]);j > i + 1;j--)
				f[j]++;
			f[i + 1] += f[i] - S[i] + 1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}