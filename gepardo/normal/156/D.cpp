#include <iostream>
#include <vector>
#define int long long

using namespace std;

int n, m;
vector < vector<int> > g;
int pl = 0, cnt = 0;
int modulo;
int ans = 1;
vector <bool> used;

void dfs(int v)
{
	used[v] = true;
	pl++;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to]) continue;
		dfs(to);
	}
}

main()
{
	cin >> n >> m >> modulo;
	g.resize(n);
	used.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i]) continue;
		cnt++;
		pl = 0;
		dfs(i);
		ans = (ans * pl) % modulo;
	}
	

	if (cnt == 1) cout << 1 % modulo;
		else
		{
			cnt -= 2;
			for (int i = 0; i < cnt; i++)
				ans = (ans * n) % modulo;
			cout << ans;	
		}

}