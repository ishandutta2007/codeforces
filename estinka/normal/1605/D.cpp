#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
typedef long long ll;
using namespace std;

const int maxn = 2e5 + 5;
vector<vector<int> > g(maxn);
vector<int> d1, d2;
void dfs(int u, bool b, int p = -1)
{
	if (b) d1.push_back(u);
	else d2.push_back(u);
	for (int v : g[u]) if (v != p)
	{
		dfs(v, !b, u);
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
		d1.clear(), d2.clear();
		int n;
		cin >> n;
		vector<vector<int> > b(18);
		int m = -1;
		for (int i = 1; i <= n; i++)
		{
			g[i].clear();
			for (int j = 0; j < b.size(); j++) if ((1 << (j + 1)) > i)
			{
				b[j].push_back(i);
				m = j;
				break;
			}
		}
		for (int i = 0, a, b; i < n - 1; i++)
		{
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(1, false);
		vector<int> a1, a2;
		if (d1.size() > d2.size()) a1 = b[m];
		else a2 = b[m];
		for (int i = m - 1; i >= 0; i--)
		{
			if ((d1.size() - a1.size()) >= (1 << i))
			{
				for (int j : b[i]) a1.push_back(j);
			}
			else
			{
				for (int j : b[i]) a2.push_back(j);
			}
		}
		vector<int> p(n + 1);
		for (int i = 0; i < d1.size(); i++) p[d1[i]] = a1[i];
		for (int i = 0; i < d2.size(); i++) p[d2[i]] = a2[i];
		for (int i = 1; i <= n; i++) cout << p[i] << " ";
		cout << "\n";
	}
	return 0;
}