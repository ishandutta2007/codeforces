#include <bits/stdc++.h>
using namespace std;

int q;
long long l, r, d;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%lld%lld%lld",&l,&r,&d);
		if (d<l)
			{
			printf ("%lld\n",d);
			continue;
			}
		r -= r%d;
		r+=d;
		printf ("%lld\n",r);
		}
	return 0;
	}