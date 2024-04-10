#include <bits/stdc++.h>
using namespace std;

int n, i;
int t [1001];

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	sort (t,t+n);
	printf ("%d\n",t[(n-1)/2]);
	return 0;
	}