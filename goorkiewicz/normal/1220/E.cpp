#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, m, i, j, u, s;
ll sum, out;
ll val [N];
int deg [N];
ll best [N];
bool erased [N];
vector <int> e [N];
queue <int> Q;

int main ()
	{
	scanf ("%d%d",&n,&m);
	for (i=1; i<=n; i++)
		{
		scanf ("%lld",&val[i]);
		sum += val[i];
		}
	for (i=1; i<=m; i++)
		{
		int a, b;
		scanf ("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
		deg[a]++;
		deg[b]++;
		}
	scanf ("%d",&s);
	for (i=1; i<=n; i++)
		if (i!=s && deg[i]==1)
			{
			best[i] = val[i];
			Q.push(i);
			}
	while (!Q.empty())
		{
		u = Q.front();
		Q.pop();
		sum -= val[u];
		erased[u] = true;
		out = max(out, best[u]);
		for (int v : e[u])
			if (erased[v]==false)
				{
				deg[v]--;
				best[v] = max(best[v], best[u]+val[v]);
				if (v!=s && deg[v]==1)
					Q.push(v);
				}
		}
	printf ("%lld\n",sum+out);
	return 0;
	}