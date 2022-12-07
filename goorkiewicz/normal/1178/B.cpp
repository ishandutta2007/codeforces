#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i;
ll w, wo, wow;
char s [1000002];

int main ()
	{
	scanf ("%s",s+1);
	n = strlen(s+1);
	for (i=1; i<=n; i++)
		{
		if (s[i]=='v' && s[i-1]=='v')
			{
			w++;
			wow+=wo;
			}
		if (s[i]=='o')
			wo+=w;
		}
	printf ("%lld\n",wow);
	return 0;
	}