#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n, i;
int one, zero;
char s [100005];

int main ()
	{
	scanf ("%d",&n);
	scanf ("%s",s+1);
	for (i=1; i<=n; i++)
		{
		if (s[i]=='n')
			one++;
		if (s[i]=='r')
			zero++;
		}
	while (one--)
		printf ("1 ");
	while (zero--)
		printf ("0 ");
	printf ("\n");	
	return 0;
	}