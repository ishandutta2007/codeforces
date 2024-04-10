#include <bits/stdc++.h>
using namespace std;

int q, n, m, s, t;

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d%d%d",&n,&s,&t);
		m = min(s,t);
		printf ("%d\n",n-m+1);
		}
	return 0;
	}