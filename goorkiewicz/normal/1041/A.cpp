#include <bits/stdc++.h>
using namespace std;

int n, i, x;
int mini, maxi;

int main ()
	{
	scanf ("%d",&n);
	mini=1000000001;
	maxi=-1000000001;
	for (i=0; i!=n; i++)
		{
		scanf ("%d",&x);
		mini=min(mini,x);
		maxi=max(maxi,x);
		}
	printf ("%d\n",(maxi-mini+1)-n);
	return 0;
	}