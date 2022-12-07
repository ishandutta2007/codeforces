#include <bits/stdc++.h>
using namespace std;

int n, i, x, out;
char s [101];

int main ()
	{
	scanf ("%d",&n);
	scanf ("%s",s);
	for (i=0; i!=n; i++)
		{
		if (s[i]=='x')
			x++;
		if (s[i]!='x')
			x=0;
		if (x==3)
			{
			x--;
			out++;
			}
		}
	printf ("%d\n",out);
	return 0;
	}