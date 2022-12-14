#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
#include <bitset>
typedef long long ll;
using namespace std;

vector<vector<int> > g;
vector<vector<pair<int, int> > > g2;
vector<int> p, r, ans;
bool bad = false;
void dfs(int u)
{
	for (int v : g[u])
	{
		if (v != p[u])
		{
			p[v] = u;
			dfs(v);
		}
	}
}
void dfs2(int u)
{
	for (pair<int, int> v : g2[u])
	{
		if (r[v.first] == -1)
		{
			r[v.first] = r[u] ^ v.second;
			dfs2(v.first);
		}
		else if (r[v.first] != (r[u] ^ v.second))
		{
			bad = true;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		g.assign(n, {}), g2.assign(n, {}), p.assign(n, -1), r.assign(n, -1), ans.assign(n, -1);
		bad = false;
		vector<pair<pair<int, int>, int> > e;
		for (int i = 0, x, y, v; i < n - 1; i++)
		{
			cin >> x >> y >> v;
			x--, y--;
			g[x].push_back(y), g[y].push_back(x);
			if (v != -1)
			{
				e.push_back({ {x, y}, v });
				int p = 0;
				for (int j = 0; j < 30; j++) if (v & (1 << j)) p ^= 1;
				g2[x].push_back({ y, p });
				g2[y].push_back({ x, p });
			}
		}
		dfs(0);
		for (int i = 0; i < e.size(); i++)
		{
			int x = e[i].first.first, y = e[i].first.second, v = e[i].second;
			if (p[x] == y) ans[x] = v;
			else ans[y] = v;
		}
		for (int i = 0, x, y, p; i < m; i++)
		{
			cin >> x >> y >> p;
			x--, y--;
			g2[x].push_back({ y, p });
			g2[y].push_back({ x, p });
		}
		for (int i = 0; i < n; i++) if (r[i] == -1)
		{
			r[i] = 0;
			dfs2(i);
		}
		if (bad)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 1; i < n; i++)
		{
			if (ans[i] == -1) ans[i] = r[p[i]] ^ r[i];
			cout << i + 1 << " " << p[i] + 1 << " " << ans[i] << "\n";
		}
		//cout << "\n";
	}
	return 0;
}