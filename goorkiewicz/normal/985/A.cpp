#include <bits/stdc++.h>
using namespace std;

int n, i, out1, out2;
int t [101];

int main ()
	{
	scanf ("%d",&n);
	n/=2;
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	sort (t,t+n);
	for (i=0; i!=n; i++)
		out1+=abs(((2*i)+1)-t[i]);
	for (i=0; i!=n; i++)
		out2+=abs(((2*i)+2)-t[i]);
	printf ("%d\n",min(out1,out2));
	return 0;
	}