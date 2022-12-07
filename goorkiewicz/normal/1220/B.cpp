#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n, i, y, x;
ll v;
ll a [1005];
ll t [1005][1005];

int main ()
	{
	scanf ("%d",&n);
	for (y=1; y<=n; y++)
		for (x=1; x<=n; x++)
			scanf ("%lld",&t[y][x]);
	
	v = ((t[1][2] * t[1][3]) / t[2][3]);
	while (a[1]*a[1]!=v)
		a[1]++;
	for (i=2; i<=n; i++)
		a[i] = t[1][i] / a[1];
	for (i=1; i<=n; i++)
		printf ("%lld ",a[i]);
	return 0;
	}