//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int q, i;
long long n, k, x, d, sum;

int main ()
	{
	scanf ("%lld%d",&n,&q);
	while (q--)
		{
		scanf ("%lld%lld",&x,&d);
		sum+=(n*x);
		if (d<0)
			{
			k=(n/2);
			sum+=((((k+1)*k)/2LL)*d);
			k=((n-1LL)/2LL);
			sum+=((((k+1)*k)/2LL)*d);
			}
		if (d>=0)
			{
			k=(n-1LL);
			sum+=((((k+1)*k)/2LL)*d);
			}
		}
	printf ("%lf\n",((double)(sum))/((double)(n)));
	return 0;
	}