#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;

vector<int> adj[maxn];

set<pair<ll , int> > st[maxn];

ll res = 0 , t[maxn];

int h[maxn];

void merge(int a , int b)
{
	if(st[a].size() < st[b].size())
		st[a].swap(st[b]) , swap(t[a] , t[b]);
	auto it = st[a].begin();
	for(auto x : st[b])
	{
		x.first += t[b];
		x.first -= t[a];
		auto z = st[a].insert(it , x);
		it = z;
	}
	st[b].clear();
}

int dfs(int v , int p = -1)
{
	int node = v;
	for(auto u : adj[v])
		if(u != p)
		{
			h[u] = h[v] + 1;
			int x = dfs(u , v);
			if(h[x] < h[node])
				node = x;
			else if(h[x] > h[v])
			{
				cout << -1 << endl;
				exit(0);
			}
		}
	if(node != v)
		merge(node , v);
	else while(!st[v].empty())
	{
		pair<ll , int> e = *st[v].begin();
		st[v].erase(st[v].begin());
		if(h[e.second] >= h[v])
			continue;
		node = e.second;
		res += e.first + t[v];
		t[v] -= e.first + t[v];
		merge(node , v);
		break;
	}
	return node;
}

int main()
{
	int n , m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		scanf("%d%d", &a, &b);
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	for(int i = 0; i < m; i++)
	{
		int v , u , c;
		scanf("%d%d%d", &v, &u, &c);
		v--;
		u--;
		st[v].insert({c , u});
	}
	dfs(0);
	cout << res << endl;
}