#include <bits/stdc++.h>
using namespace std;

int n, i;
char t [300002];
long long x, y, z;

int main ()
	{
	scanf ("%d%lld%lld",&n,&x,&y);
	scanf ("%s",t);
	for (i=0; i!=n; i++)
		if (t[i]=='0' && t[i]!=t[i+1])
			z++;
	if (z==0)
		printf ("0\n");
	else
		printf ("%lld\n",((z-1LL)*min(x,y))+y);
	return 0;
	}