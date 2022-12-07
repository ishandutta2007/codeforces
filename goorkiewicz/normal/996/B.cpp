#include <bits/stdc++.h>
using namespace std;

int n, i, d;
int t [100001];

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	d = 1000000001;
	for (i=0; i!=n; i++)
		d = min (d,t[i]);
	for (i=(d%n); true; i=((i+1)%n))
		{
		if (t[i]-d<=0)
			{
			printf ("%d\n",((d%n)+1));
			return 0;
			}
		else
			d++;
		}
	return 0;
	}