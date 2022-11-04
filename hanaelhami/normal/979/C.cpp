#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

vector<int> adj[maxn];

int sz[maxn] , par[maxn];

void dfs(int v)
{
	sz[v] = 1;
	for(auto u : adj[v])
		if(u != par[v])
		{
			par[u] = v;
			dfs(u);
			sz[v] += sz[u];
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , v , u;
	cin >> n >> v >> u;
	v-- , u--;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	par[v] = v;
	dfs(v);

	ll k = sz[u];
	while(par[u] != v)
		u = par[u];

	ll res = 1LL * n * (n - 1);

	res -= k * (n - sz[u]);

	cout << res << endl;
}