#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n;
int a[MAXN];
int lst[MAXN];
int MAX[MAXN];
int ans[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			MAX[i] = lst[i] = 0;
			ans[i] = 1e9;
		}
		for (int a,i = 1;i <= n;i++)
		{
			scanf("%d",&a);
			MAX[a] = max(MAX[a],i - lst[a]);
			lst[a] = i;
		}
		for (int i = 1;i <= n;i++)
			MAX[i] = max(MAX[i],n + 1 - lst[i]);
		for (int i = 1;i <= n;i++)
			ans[MAX[i]] = min(ans[MAX[i]],i);
		for (int i = 1;i <= n;i++)
			ans[i + 1] = min(ans[i + 1],ans[i]);
		for (int i = 1;i <= n;i++)
			printf("%d ",ans[i] == 1e9 ? -1 : ans[i]);
		printf("\n");
	}
	return 0;
}