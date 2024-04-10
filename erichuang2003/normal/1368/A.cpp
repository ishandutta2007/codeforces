#include <bits/stdc++.h>

using namespace std;

int T,a,b,n;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&a,&b,&n);
		int cnt = 0;
		while (a <= n && b <= n)
		{
			cnt++;
			if (a > b)
				swap(a,b);
			a += b;
		}
		printf("%d\n",cnt);
	}
	return 0;
}