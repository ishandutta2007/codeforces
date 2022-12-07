#include <bits/stdc++.h>
using namespace std;

int q;
long long n, x, y, a;

int main ()
	{
	scanf ("%lld%d",&n,&q);
	while (q--)
		{
		scanf ("%lld%lld",&x,&y);
		if ((x+y)%2==0)
			{
			x--;
			a=(((x*n)+1)/2);
			a+=((y+1)/2);
			}
		else
			{
			x--;
			a=(((n*n)+1)/2);
			a+=((x*n)/2);
			a+=((y+1)/2);
			}
		printf ("%lld\n",a);
		}
	return 0;
	}