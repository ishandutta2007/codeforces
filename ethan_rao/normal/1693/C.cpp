#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pa;
const int N = 2e5 + 5;
vector<int> e[N];
int deg[N], dis[N], ed[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i, j;
	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		e[v].push_back(u);
		++deg[u];
	}
	priority_queue<pa, vector<pa>, greater<pa>> q;
	q.push({0, n});
	memset(dis, 0x3f, sizeof dis);
	dis[n] = 0;
	while (q.size())
	{
		int u = q.top().second;
		q.pop();
		assert(!ed[u]);
		ed[u] = 1;
		for (int v : e[u])
		{
			if (dis[v] > dis[u] + deg[v])
			{
				dis[v] = dis[u] + deg[v];
				q.push({dis[v], v});
			}
			--deg[v];
		}
		while (q.size() && dis[q.top().second] != q.top().first)
			q.pop();
	}
	cout << dis[1] << endl;
}