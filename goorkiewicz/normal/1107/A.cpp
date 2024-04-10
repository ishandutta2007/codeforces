#include <bits/stdc++.h>
using namespace std;

int q, n, i, j;
char s [301];

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d%s",&n,s+1);
		if (n==1)
			{
			printf ("NO\n"), 0;
			continue;
			}
		if (n==2 && s[1]>=s[2])
			{
			printf ("NO\n"), 0;
			continue;
			}
		printf ("YES\n2\n");
		printf ("%c ",s[1]);
		for (i=2; i<=n; i++)
			printf ("%c",s[i]);
		printf ("\n");
		}
	return 0;
	}