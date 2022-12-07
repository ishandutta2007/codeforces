#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int q, n, i, s, t, u, v;
ll cnt [N];
ll lim [N];
ll out;
map < pair <int,int> , int> M;

int main ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++)
		scanf ("%lld", &lim[i]);
	scanf ("%d", &q);
	for (i=1; i<=n; i++)
		out += lim[i];
	while (q--)
		{
		scanf ("%d%d%d", &s, &t, &u);
		
		v = M[{s, t}];

		M[{s, t}] = u;

		if (v!=0)
			{
			out -= max(0ll, lim[v] - cnt[v]);
			cnt[v]--;
			out += max(0ll, lim[v] - cnt[v]);
			}
		if (u!=0)
			{
			out -= max(0ll, lim[u] - cnt[u]);
			cnt[u]++;
			out += max(0ll, lim[u] - cnt[u]);
			}
		printf ("%lld\n", out);
		}
	return 0;
	}