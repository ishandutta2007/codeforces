#include <bits/stdc++.h>
using namespace std;

int q, n, k, ang;
int out [180];

int main ()
	{
	for (n=3; n<=1000; n++)
		for (k=1; k<n; k++)
			if ((180*k)%n==0 && out[(180*k)/n]==0)
				{
				ang = (180*k)/n;
				if (ang>90 && k==n-1)
					continue;
				out[ang]=n;
				}
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&ang);
		printf ("%d\n", out[ang]==0 ? -1 : out[ang]);
		}
	return 0;
	}