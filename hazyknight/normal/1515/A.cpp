#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int T,n,x;
int w[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&x);
		for (int i = 1;i <= n;i++)
			scanf("%d",&w[i]);
		int sum = 0;
		for (int i = 1;i <= n;i++)
		{
			sum += w[i];
			if (sum == x)
				swap(w[i],w[i + 1]);
		}
		if (sum == x)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1;i <= n;i++)
			printf("%d ",w[i]);
		printf("\n");
	}
	return 0;
}