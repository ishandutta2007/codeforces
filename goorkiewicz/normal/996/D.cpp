#include <bits/stdc++.h>
using namespace std;

int n, i, j, out;
int t [201];

int main ()
	{
	scanf ("%d",&n);
	n+=n;
	for (i=0; i!=n; i++)
		scanf ("%d",&t[i]);
	for (i=0; i<n; i++)
		{
		for (j=(i+1); j<n; j++)
			if (t[j]==t[i])
				break;
		if (j==n)
			continue;
		for (j--; j>i; j--)
			{
			swap (t[j],t[j+1]);
			out++;
			}
		}
	printf ("%d\n",out);
	return 0;
	}