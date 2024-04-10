#include <bits/stdc++.h>
using namespace std;

int q, n, i, j;
char s [101];

int main ()
	{
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&n);
		scanf ("%s",s);
		for (i=0, j=n-1; i!=n; i++, j--)
			if (abs(s[i]-s[j])>2 || abs(s[i]-s[j])%2!=0)
				break;
		if (i==n)
			printf ("YES\n");
		else
			printf ("NO\n");
		}
	return 0;
	}