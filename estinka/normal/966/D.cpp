#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
const int maxn = 3e5 + 79, inf = 1e9;
vector<vector<int> > g(maxn);
vector<int> vis2(maxn, 0);
vector<int> p(maxn, -1), d(maxn, inf); 
void good(vector<int> path)
{
	if (path.empty()) cout << "-1\n";
	else
	{
		cout << path.size() - 1 << "\n";
		for (int i = 0; i < path.size(); i++) cout << path[i] + 1 << " ";
		cout << "\n";
	}
	exit(0);
}
vector<int> vv;
pair<int, int> dfs(int vr) // (number of vertices, number of edges)
{
	vv.push_back(vr);
	pair<int, int> p(1, g[vr].size());
	vis2[vr] = true;
	for (int i : g[vr])
	{
		if (vis2[i]) continue;
		pair<int, int>p2 = dfs(i);
		p.first += p2.first;
		p.second += p2.second;
	}
	return p;
}
void get(int vr, vector<int>& path, int start = 0)
{
	while (vr != start)
	{
		path.push_back(vr);
		vr = p[vr];
	}
	path.push_back(start);
	reverse(path.begin(), path.end());
}
void bfs(int vr)
{
	queue<int> q;
	q.push(vr); d[vr] = 0;
	while (!q.empty())
	{
		int vr = q.front();
		q.pop();
		for (int i : g[vr])
		{
			if (d[i] == inf)
			{
				p[i] = vr;
				d[i] = d[vr] + 1;
				q.push(i);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	vector<int> path; bfs(0);
	if (d[n - 1] != inf) get(n - 1, path);
	if (d[n - 1] <= 4) good(path);
	for (int i = 0; i < n; i++)
	{
		if (d[i] == 2)
		{
			vector<int> p2(1, 0);
			get(i, p2);
			p2.push_back(n - 1);
			good(p2);
		}
	} vis2[0] = true;
	for (int i : g[0])
	{
		if (vis2[i]) continue;
		vv.clear();
		pair<int, int> c = dfs(i);
		if (c.first * 1ll * (c.first - 1) == (ll)c.second) continue;
		for (int j : vv)
		{
			if (g[j].size() == c.first) continue;
			d.assign(n, inf); d[0] = 0; p.assign(n, -1);
			bfs(j);
			int v2 = -1;
			for (int k = 0; k < n; k++) if (d[k] == 2) v2 = k;
			vector<int> p2;
			get(v2, p2, j);
			p2.insert(p2.begin(), 0);
			p2.push_back(j);
			p2.push_back(n - 1); 
			good(p2);
		}
	}
	good(path);
	return 0;
}