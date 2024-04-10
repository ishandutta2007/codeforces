#include <bits/stdc++.h>

using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int a,i = 1;i <= n;i++)
			scanf("%d",&a);
		printf("%d\n",n / 2 * 6);
		for (int i = 1;i <= n;i += 2)
		{
			printf("1 %d %d\n",i,i + 1);
			printf("2 %d %d\n",i,i + 1);
			printf("1 %d %d\n",i,i + 1);
			printf("1 %d %d\n",i,i + 1);
			printf("2 %d %d\n",i,i + 1);
			printf("1 %d %d\n",i,i + 1);
		}
	}
	return 0;
}