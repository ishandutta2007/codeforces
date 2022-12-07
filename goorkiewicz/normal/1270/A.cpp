#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q, n, i, a, k1, k2, m1, m2;

bool solve ()
	{
	scanf ("%d%d%d", &n, &k1, &k2);
	m1 = m2 = 0;
	for (i=1; i<=k1; i++)
		{
		scanf ("%d", &a);
		m1 = max(m1, a);
		}
	for (i=1; i<=k2; i++)
		{
		scanf ("%d", &a);
		m2 = max(m2, a);
		}
	return (m1 > m2);
	}

int main ()
	{
	int q;
	scanf ("%d", &q);
	while (q--)
		printf ("%s\n", solve() ? "YES" : "NO");
	return 0;
	}