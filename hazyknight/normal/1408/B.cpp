#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 105;
 
int T,n,K;
int a[MAXN];
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&K);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		int cnt = 0;
		for (int i = 1;i < n;i++)
			if (a[i] != a[i + 1])
				cnt++;
		if (K == 1)
		{
			if (cnt)
				puts("-1");
			else
				puts("1");
			continue;
		}
		printf("%d\n",max(1,cnt / (K - 1) + (cnt % (K - 1) != 0)));
	}
	return 0;
}