#include <bits/stdc++.h>

using namespace std;

int T,n,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans = 0;
		int L = 2e9 + 1,cl = 1e9 + 1,R = -2e9 - 1,cr = 1e9 + 1,M = -1,ml = 1e9 + 1;
		for (int l,r,c,i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&l,&r,&c);
			if (l < L)
			{
				L = l;
				cl = c;
			}
			else if (l == L && c < cl)
				cl = c;
			if (r > R)
			{
				R = r;
				cr = c;
			}
			else if (r == R && c < cr)
				cr = c;
			if (r - l + 1 > M)
			{
				M = r - l + 1;
				ml = c;
			}
			else if (r - l + 1 == M && c < ml)
				ml = c;
			if (M == R - L + 1)
				printf("%d\n",min(cl + cr,ml));
			else
				printf("%d\n",cl + cr);
		}
	}
	return 0;
}