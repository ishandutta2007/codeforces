#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, c;
char s [2001][2001];
bool hero [2001];

int main ()
	{
	scanf ("%d%d",&n,&m);
	for (i=0; i!=n; i++)
		scanf ("%s",s[i]);
	for (j=0; j!=m; j++)
		{
		c=(-1);
		for (i=0; i!=n; i++)
			if (s[i][j]=='1')
				{
				if (c==(-1))
					c=i;
				else
					{
					c=(-1);
					break;
					}
				}
		if (c!=(-1))
			hero[c]=true;
		}
	for (i=0; i!=n; i++)
		if (hero[i]==false)
			{
			printf ("YES\n");
			return 0;
			}
	printf ("NO\n");
	return 0;
	}