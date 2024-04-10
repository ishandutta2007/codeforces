#include <bits/stdc++.h>
using namespace std;

int n, i;
char s [1002];

int main ()
	{
	scanf ("%d",&n);
	scanf ("%s",s);
	for (i=0; s[i+1]!=0; i++)
		if (s[i]!=s[i+1])
			{
			printf ("YES\n%c%c\n",s[i],s[i+1]);
			return 0;
			}
	printf ("NO\n");
	return 0;
	}