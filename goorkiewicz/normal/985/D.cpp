#include <bits/stdc++.h>
using namespace std;

long long h, H, a, b, c, w, k, sand;

bool check (long long x)
	{
	w=min(H,x);
	w--;
	x+=w;
	sand=0LL;
	k=(x/2);
	sand+=(((k+1LL)*k)/2LL);
	k=(x-(x/2));
	sand+=(((k+1LL)*k)/2LL);
	sand-=(((w+1LL)*w)/2LL);
	if (sand>=h)
		return true;
	return false;
	}

int main ()
	{
	scanf ("%lld%lld",&h,&H);
	a=(-1LL);
	b=2000000001;
	while (b-a>1)
		{
		c=((a+b)/2);
		if (check(c)==false)
			a=c;
		else
			b=c;
		}
	printf ("%lld\n",b);
	return 0;
	}