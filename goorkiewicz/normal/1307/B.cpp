#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i;
ll x, m;
ll t [N];

void solve ()
	{
	scanf ("%d%lld", &n, &x);
	m = 0;
	for (i=1; i<=n; i++)
		{
		scanf ("%lld", &t[i]);
		m = max(m, t[i]);
		}
	for (i=1; i<=n; i++)
		if (t[i] == x)
			{
			printf ("1\n");
			return;
			}
	if (x%m == 0)
		{
		printf ("%lld\n", (x/m));
		return;
		}
	if (m < x)
		{
		printf ("%lld\n", (x + m - 1)/m);
		return;
		}
	printf ("2\n");
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}