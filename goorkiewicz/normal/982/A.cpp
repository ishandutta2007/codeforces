#include <bits/stdc++.h>
using namespace std;

int n, i;
char s [1001];

int main ()
	{
	scanf ("%d",&n);
	scanf ("%s",s);
	for (i=0; i!=n; i++)
		{
		if (i+1<n && s[i]=='1' && s[i+1]=='1')
			{
			printf ("NO\n");
			return 0;
			}
		if (s[i]=='0' && (i==0 || s[i-1]=='0') && (i==(n-1) || s[i+1]=='0'))
			{
			printf ("NO\n");
			return 0;
			}
		}
	printf ("YES\n");
	return 0;
	}