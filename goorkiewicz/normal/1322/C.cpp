#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
int q, n, m, i, j;
ll t [N];
vector <int> e [N];
map < vector <int>, ll > M;

void solve ()
	{
	scanf ("%d%d", &n, &m);
	
	M.clear();
	for (i=1; i<=n; i++)
		e[i].clear();

	for (i=1; i<=n; i++)
		scanf ("%lld", &t[i]);
	
	while (m--)
		{
		scanf ("%d%d", &i, &j);
		e[j].push_back(i);
		}

	for (i=1; i<=n; i++)
		{
		sort(e[i].begin(), e[i].end());
		if (!e[i].empty())
			M[e[i]] += t[i];
		}
	
	ll out = 0;
	for (const auto& p : M)
		out = __gcd(out, p.second);

	printf ("%lld\n", out);
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}