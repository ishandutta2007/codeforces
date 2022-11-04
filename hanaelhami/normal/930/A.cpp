#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define shit shitekhar

const int maxn = 2e5 + 20;

int h[maxn] , t[maxn];

vector<int> adj[maxn];

void dfs(int v)
{
	t[h[v]]++;
	for(auto u : adj[v])
	{
		h[u] = h[v] + 1;
		dfs(u);
	}
}

int main()
{
	int n;
	cin >> n;

	for(int i = 2; i <= n; i++)
	{
		int p;
		cin >> p;

		adj[p].pb(i);
	}

	dfs(1);

	int res = 0;

	for(int i = 0; i < maxn; i++)
		res += (t[i] % 2);

	cout << res << endl;

}