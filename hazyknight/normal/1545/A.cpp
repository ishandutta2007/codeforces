#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;
int a[MAXN];
int sum[MAXN][2];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= 100000;i++)
			sum[i][0] = sum[i][1] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum[a[i]][i & 1]++;
		}
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i++)
			sum[a[i]][i & 1]--;
		bool ok = 1;
		for (int i = 1;i <= 100000;i++)
			if (sum[i][0] || sum[i][1])
				ok = 0;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}