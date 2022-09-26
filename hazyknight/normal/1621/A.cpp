#include <bits/stdc++.h>

using namespace std;

int T,n,k;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		if ((n + 1) / 2 >= k)
		{
			for (int i = 1;i <= n;i++,printf("\n"))
				for (int j = 1;j <= n;j++)
					if (i == j && (i & 1) && k)
					{
						k--;
						printf("R");
					}
					else
						printf(".");
		}
		else
			puts("-1");
	}
	return 0;
}