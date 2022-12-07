#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i;
ll cost, h, ha, har, hard;
char a;
char s [100001];

int main ()
	{
	scanf ("%d%s",&n,s+1);
	for (i=1; i<=n; i++)
		{
		scanf ("%lld",&cost);
		a = s[i];
		if (a=='h')
			h+=cost;
		if (a=='a')
			ha=min(h,ha+cost);
		if (a=='r')
			har=min(ha,har+cost);
		if (a=='d')
			hard=min(har,hard+cost);
		}
	printf ("%lld\n",hard);
	return 0;
	}