#include <bits/stdc++.h>

using namespace std;

const int MAXN = 75;

int T,n;
int a[MAXN];

int cross(int xa,int ya,int xb,int yb)
{
	return xa * yb - ya * xb;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int ans = 1;
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++)
			{
				int cnt = 2;
				for (int k = 1;k <= n;k++)
					if (k != i && k != j && !cross(k - i,a[k] - a[i],j - i,a[j] - a[i]))
						cnt++;
				ans = max(ans,cnt);
			}
		printf("%d\n",n - ans);
	}
	return 0;
}