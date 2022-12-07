#include <bits/stdc++.h>
using namespace std;

int n, q, i;
int t [1001];

int main ()
	{
	scanf ("%d%d",&n,&q);
	while (q--)
		{
		scanf ("%d",&i);
		t[i]++;
		}
	int out = 1000000001;
	for (i=1; i<=n; i++)
		out=min(out,t[i]);
	printf ("%d\n",out);
	return 0;
	}