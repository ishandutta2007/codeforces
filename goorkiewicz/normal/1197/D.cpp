#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, n, m, i, s;
ll out, M, k;
ll t [300005];
ll a [300005];

int main ()
	{
	scanf ("%d%d%lld",&N,&m,&k);
	for (i=0; i<N; i++)
		scanf ("%lld",&t[i]);
	for (s=0; s<m; s++)
		{
		n = N-s;
		if (n<=0)
			break;
		for (i=0; i<n; i++)
			a[i] = t[i+s];
		for (i=1; i<n; i++)
			a[i] += a[i-1];
		M = k;
		for (i=0; i<n; i++)
			{
			out = max(out, a[i]-M);
			if ((i+1)%m==0)
				{
				M = min(M, a[i]);
				M+=k;
				}
			}
		}
	printf ("%lld\n",out);
	return 0;
	}