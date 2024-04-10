#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		if (n == 1 && m == 1)
		{
			puts("0");
			continue;
		}
		if (n == 1 || m == 1)
		{
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}