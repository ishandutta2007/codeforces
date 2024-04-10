#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
const int N = 5e5 + 10;
struct Q
{
	int v, w;
};
ll ans;
vector<Q> e[N];
vector<int> pos[N];
int dfn[N], f[N], low[N], siz[N], ns[N];
int n;
void dfs1(int u)
{
	static int id = 0;
	dfn[u] = ++id;
	siz[u] = 1;
	for (auto [v, w] : e[u])
		if (v != f[u])
		{
			f[v] = u;
			dfs1(v);
			siz[u] += siz[v];
		}
	low[u] = dfn[u] + siz[u] - 1;
}
void dfs2(int u, int lf)
{
	for (auto [v, w] : e[u])
		if (v != f[u])
		{
			dfs2(v, w);
		}
	if (lf)
	{
		int w = lf, res = siz[u], tot = 0;
		while (pos[w].size())
		{
			int v = pos[w].back();
			if (dfn[v] < dfn[u] || dfn[v] > low[u])
				break;
			res -= siz[v];
			tot += ns[v];
			pos[w].pop_back();
		}
		ans += (ll)res * tot;
		ns[u] = res;
		pos[w].push_back(u);
	}
	else
	{
		for (int w = 1; w <= n; w++)
		{
			int res = n, tot = 0;
			while (pos[w].size())
			{
				int v = pos[w].back();
				res -= siz[v];
				tot += ns[v];
				pos[w].pop_back();
			}
			ans += (ll)res * tot;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	cin >> n;
	for (i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	dfs1(1);
	dfs2(1, 0);
	cout << ans << endl;
}