#include <bits/stdc++.h>
using namespace std;

long long a, b, x, y, Gcd;

int main ()
	{
	scanf ("%lld%lld%lld%lld",&a,&b,&x,&y);
	Gcd = __gcd (x,y);
	x/=Gcd;
	y/=Gcd;
	printf ("%lld\n",min((a/x),(b/y)));
	return 0;
	}