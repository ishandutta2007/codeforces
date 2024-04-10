#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j;
int t [200005];

void solve ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);
	for (i=1; i<n; i++)
		if (abs(t[i] - t[i+1]) >= 2)
			{
			printf ("YES\n");
			printf ("%d %d\n", i, i+1);
			return;
			}
	printf ("NO\n");
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}