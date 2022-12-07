#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 200005;
int q, n, k, i;
ll out;
ll S [N];
vector < pair <int,ll> > e [N];

void dfs (int u, int f)
	{
	S[u] = 1;
	for (pair <int,ll> v : e[u])
		if (v.f != f)
			{
			dfs(v.f, u);
			S[u] += S[v.f];
			if (S[v.f]%2==1)
				out += v.s;
			}
	}

int find_centroid (int u, int f)
	{
	for (pair <int,ll> v : e[u])
		if (v.f != f)
			if (S[v.f] > k)
				return find_centroid(v.f, u);
	
	return u;
	}

void count (int u, int f)
	{
	for (pair <int,ll> v : e[u])
		if (v.f != f)
			{
			out += v.s * S[v.f];
			count(v.f, u);
			}
	}

void solve ()
	{
	scanf ("%d", &k);
	n = k+k;
	for (i=1; i<=n; i++)
		e[i].clear();
	for (i=1; i<n; i++)
		{
		int a, b;
		ll c;
		scanf ("%d%d%lld", &a, &b, &c);
		e[a].push_back({b, c});
		e[b].push_back({a, c});
		}
	
	out = 0;
	dfs(1, 1);
	printf ("%lld ", out);
	
	int c = find_centroid(1, 1);
	dfs(c, c);
	out = 0;
	count(c, c);
	printf ("%lld\n", out);
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}