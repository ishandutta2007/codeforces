//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, i, j, out;
int c [1001];
int a [1001];

int main ()
	{
	scanf ("%d%d",&n,&m);
	for (i=0; i!=n; i++)
		scanf ("%d",&c[i]);
	for (j=0; j!=m; j++)
		scanf ("%d",&a[j]);
	j=0;
	for (i=0; i!=n; i++)
		if (c[i]<=a[j])
			{
			j++;
			out++;
			}
	printf ("%d\n",out);
	return 0;
	}