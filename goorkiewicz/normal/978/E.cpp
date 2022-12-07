#include <bits/stdc++.h>
using namespace std;

int n, i, w, d, now, out;
int MIN, MAX;

int main ()
	{
	scanf ("%d%d",&n,&w);
	MIN=0;
	MAX=0;
	now=0;
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&d);
		now+=d;
		MAX=max(MAX,now);
		MIN=min(MIN,now);
		}
	out=(w-MAX+MIN+1);
	if (out<=0)
		printf ("0\n");
	else
		printf ("%d\n",out);
	return 0;
	}