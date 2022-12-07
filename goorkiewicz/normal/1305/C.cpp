#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, i, j, mod, out;
int t [N];

int main ()
	{
	scanf ("%d%d", &n, &mod);
	
	if (n >= mod+5)
		return printf ("0\n"), 0;
	
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);
	
	out = 1;
	for (i=1; i<=n; i++)
		for (j=1; j<i; j++)
			out = (1ll * out * abs(t[i] - t[j]))%mod;

	out += mod;
	out %= mod;
	
	printf ("%d\n", out);
	return 0;
	}