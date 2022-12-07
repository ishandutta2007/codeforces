#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
int q, n, i, j, d;
int t [N];

void solve ()
	{
	scanf ("%d%d", &n, &d);
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);
	
	while (true)
		{
		for (i=2; i<=n; i++)
			if (t[i] > 0)
				{
				t[i]--;
				t[i-1]++;
				if (--d == 0)
					{
					printf ("%d\n", t[1]);
					return;
					}
				break;
				}
		if (i > n)
			break;
		}

	printf ("%d\n", t[1]);
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--) solve();
	return 0;
	}