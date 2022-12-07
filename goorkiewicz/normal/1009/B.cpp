//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int i, jed;
char s [100001];

int main ()
	{
	scanf ("%s",s);
	for (i=0; s[i]!=0; i++)
		if (s[i]=='1')
			jed++;
	for (i=0; s[i]!=0; i++)
		{
		if (s[i]=='0')
			printf ("0");
		if (s[i]=='2')
			{
			while (jed>0)
				{
				printf ("1");
				jed--;
				}
			printf ("2");
			}
		}
	while (jed>0)
		{
		printf ("1");
		jed--;
		}
	printf ("\n");
	return 0;
	}