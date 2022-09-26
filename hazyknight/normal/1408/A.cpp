#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int T,n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int ans[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for (int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		for (int i = 1;i <= n;i++)
			scanf("%d",&c[i]);
		ans[1] = a[1];
		for (int i = 2;i < n;i++)
		{
			if (ans[i - 1] == a[i])
				ans[i] = b[i];
			else
				ans[i] = a[i];
		}
		if (a[n] != ans[n - 1] && a[n] != ans[1])
			ans[n] = a[n];
		if (b[n] != ans[n - 1] && b[n] != ans[1])
			ans[n] = b[n];
		if (c[n] != ans[n - 1] && c[n] != ans[1])
			ans[n] = c[n];
		for (int i = 1;i <= n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}