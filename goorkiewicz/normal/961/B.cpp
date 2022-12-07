#include <bits/stdc++.h>
using namespace std;

int n, i, k, t, out;
int a [100001];
int p1 [100001];
int p2 [100001];

int main ()
	{
	scanf ("%d%d",&n,&k);
	for (i=1; i<=n; i++)
		scanf ("%d",&a[i]);
	for (i=1; i<=n; i++)
		p1[i]=p1[i-1]+a[i];
	for (i=1; i<=n; i++)
		{
		p2[i]=p2[i-1];
		scanf ("%d",&t);
		if (t==1)
			p2[i]+=a[i];
		}
	for (i=1; i<=n; i++)
		out=max(out, p2[i-1]+p2[n]-p2[i+k-1] + p1[i+k-1]-p1[i-1]);
	printf ("%d\n",out);
	return 0;
	}