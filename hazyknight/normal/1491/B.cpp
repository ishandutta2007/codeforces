#include <bits/stdc++.h>

using namespace std;


int T,n,u,v;
int a[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&u,&v);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int ans = min(v + u,v + v);
		for (int i = 1;i < n;i++)
			if (abs(a[i] - a[i + 1]) > 1)
				ans = 0;
		for (int i = 1;i < n;i++)
			if (abs(a[i] - a[i + 1]) == 1)
			{
				ans = min(ans,u);
				ans = min(ans,v);
			}
		printf("%d\n",ans);
	}
	return 0;
}