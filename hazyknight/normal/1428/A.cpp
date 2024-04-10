#include <bits/stdc++.h>

using namespace std;

int T,xa,xb,ya,yb;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		int ans = abs(xa - xb) + abs(ya - yb);
		if (xa == xb || ya == yb);
		else ans += 2;
		printf("%d\n",ans);
	}
	return 0;
}