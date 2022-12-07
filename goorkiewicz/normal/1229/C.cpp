#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, m, q, i, j, u, v;
ll out;
ll deg1 [N];
ll deg2 [N];
vector <int> e [N];

int main ()
	{
	scanf ("%d%d",&n,&m);

	while (m--)
		{
		scanf ("%d%d",&u,&v);
		if (u<v) swap(u, v);
		e[v].push_back(u);
		deg1[u]++;
		deg2[v]++;
		}

	for (i=1; i<=n; i++)
		out += (deg1[i]*deg2[i]);

	printf ("%lld\n",out);
	scanf ("%d",&q);
	while (q--)
		{
		scanf ("%d",&u);
		out -= (deg1[u]*deg2[u]);
		deg1[u] += deg2[u];
		deg2[u] = 0;
		for (int v : e[u])
			{
			e[v].push_back(u);
			out -= (deg1[v]*deg2[v]);
			deg1[v]--;
			deg2[v]++;
			out += (deg1[v]*deg2[v]);
			}
		e[u].clear();
		printf ("%lld\n",out);
		}
	return 0;
	}