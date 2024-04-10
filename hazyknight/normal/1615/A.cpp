#include <bits/stdc++.h>

using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int sum = 0;
		for (int i = 1;i <= n;i++)
		{
			int a;
			scanf("%d",&a);
			sum += a;
		}
		printf("%d\n",(sum % n) != 0);
	}
	return 0;
}