#include <bits/stdc++.h>
using namespace std;

int q;
long long k, c;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%lld%lld",&k,&c);
		printf ("%lld\n",(k-1)*9+c);
		}
	return 0;
	}