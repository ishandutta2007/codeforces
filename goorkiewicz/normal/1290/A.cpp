#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1000000001;
const int N = 3505;
int q, n, m, i, j, k, f, w, a, b, res;
int t [N];
int out [N];

void solve ()
	{
	scanf ("%d%d%d", &n, &m, &k);
	for (i=0; i<=k; i++)
		out[i] = inf;
	
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);
	
	k = min(k, m-1);
	w = m - k;
	for (i=1; i<=w; i++)
		{
		a = w - i;
		b = n - a;
		for (j=0; j<=k; j++)
			out[j] = min(out[j], max(t[i+j], t[b-k+j]));
		}
	res = 0;
	for (i=0; i<=k; i++)
		res = max(res, out[i]);
	printf ("%d\n", res);
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}