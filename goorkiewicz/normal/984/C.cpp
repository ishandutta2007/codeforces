#include <bits/stdc++.h>
using namespace std;

int n, i;
long long p, q, b, d;
bool out [100001];

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		{
		scanf ("%lld%lld%lld",&p,&q,&b);
		q/=__gcd(q,p);
		d=__gcd(q,b);
		while (d!=1LL)
			{
			if (q%d!=0LL)
				d=__gcd(q,d);
			else
				q/=d;
			}
		if (q==1LL)
			out[i]=true;
		}
	for (i=0; i!=n; i++)
		{
		if (out[i]==true)
			printf ("Finite\n");
		else
			printf ("Infinite\n");
		}
	return 0;
	}