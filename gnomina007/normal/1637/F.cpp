#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<queue>
#include<fstream>
#include<iomanip>

using namespace std;

using ll = long long;
using ull = unsigned long long;
void dfs(vector<int>& fath, int cur, vector<vector<int>>&edges)
{
	for (auto a : edges[cur])
	{
		if (fath[cur] != a)
		{
			fath[a] = cur;
			dfs(fath, a, edges);
		}
	}
}
void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int n;
	cin >> n;
	long long ans = 0;
	vector<pair<int, int>>weis(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		weis[i] = { x,i };
	}
	vector<vector<int>>edges(n);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	sort(weis.begin(), weis.end());
	reverse(weis.begin(), weis.end());
	int root = weis[0].second;
	vector<int>degs(n), fath(n);
	fath[root] = -1;
	dfs(fath, root, edges);
	vector<int>used(n), values(n);
	used[root] = 1;
	values[0] = 1;
	for (int i = 1; i < n; i++)
	{
		int cur = weis[i].second;
		if (used[cur])
			values[i] = values[i - 1];
		else
		{
			while (!used[cur])
			{
				used[cur] = 1;
				degs[cur]++;
				degs[fath[cur]]++;
				cur = fath[cur];
			}
			if (degs[cur] == 2)
				values[i] = values[i - 1];
			else
				values[i] = values[i - 1]+1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		values[i] = max(values[i], 2);
		int vt = 0;
		if (i > 0)
			vt = values[i - 1];
		ans += weis[i].first *1LL* (values[i] - vt);
	}
	cout << ans << endl;
}


int main()
{	
	solve();
}