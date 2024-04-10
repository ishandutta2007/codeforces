#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n,m;
int cnt[MAXN];
int k[MAXN];
int ans[MAXN];

vector<int> c[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			cnt[i] = 0;
		for (int i = 1;i <= m;i++)
		{
			scanf("%d",&k[i]);
			c[i].resize(k[i]);
			for (int j = 0;j < k[i];j++)
				scanf("%d",&c[i][j]);
			ans[i] = c[i][0];
			cnt[c[i][0]]++;
		}
		int flag = 0;
		for (int i = 1;i <= n;i++)
			if (cnt[i] > (m + 1) / 2)
				flag = i;
		if (flag)
		{
			for (int i = 1;i <= m;i++)
			{
				if (cnt[flag] <= (m + 1) / 2)
					break;
				if (c[i][0] == flag)
				{
					if (k[i] > 1)
					{
						ans[i] = c[i][1];
						cnt[flag]--;
					}
				}
			}
		}
		if (cnt[flag] > (m + 1) / 2)
			puts("NO");
		else
		{
			puts("YES");
			for (int i = 1;i <= m;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}