#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 1000005;
int n, i, j;
ll a [N];
ll b [N];
ll m [N];

int main ()
	{
	scanf ("%d", &n);
	
	for (i=1; i<=n; i++)
		scanf ("%lld", &b[i]);
	
	m[0] = 0;
	for (i=1; i<=n; i++)
		{
		a[i] = m[i-1] + b[i];
		m[i] = m[i-1];
		if (b[i] > 0)
			m[i] = a[i];
		}

	for (i=1; i<=n; i++)
		printf ("%lld ", a[i]);
	printf ("\n");
	return 0;
	}