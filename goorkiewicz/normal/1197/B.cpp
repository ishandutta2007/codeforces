#include <bits/stdc++.h>
using namespace std;

int n, i, s;
int t [200005];

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&t[i]);
		if (t[i]>t[s])
			s = i;
		}
	for (i=s; i<n; i++)
		if (t[i]<t[i+1])
			return printf ("NO\n"), 0;
	for (i=s; i>1; i--)
		if (t[i]<t[i-1])
			return printf ("NO\n"), 0;
	printf ("YES\n");
	return 0;
	}