#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 1000005;
int q, n, i, j;
int a [N];
int b [N];

void solve ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		scanf ("%d", &a[i]);
	for (i=1; i<=n; i++)
		scanf ("%d", &b[i]);
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	for (i=1; i<=n; i++)
		printf ("%d ", a[i]);
	printf ("\n");
	for (i=1; i<=n; i++)
		printf ("%d ", b[i]);
	printf ("\n");
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}