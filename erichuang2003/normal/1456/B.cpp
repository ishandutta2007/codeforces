#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n,ans;
int a[MAXN];
int b[MAXN];

int main()
{
	scanf("%d",&n);
	if (n > 100)
	{
		puts("1");
		return 0;
	}
	ans = n + 1;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		b[i] = b[i - 1] ^ a[i];
	}
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
		{
			int v = b[j] ^ b[i - 1];
			if (i > 1 && v < a[i - 1])
				ans = min(ans,j - i);
			if (j < n && v > a[j + 1])
				ans = min(ans,j - i);
		}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < i;j++)
			for (int k = i + 1;k <= n;k++)
				if ((b[k] ^ b[i]) < (b[i] ^ b[j - 1]))
					ans = min(ans,k - j - 1);
	printf("%d\n",ans == n + 1 ? -1 : ans);
	return 0;
}