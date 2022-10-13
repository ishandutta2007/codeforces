#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, flow[200200], done[200200], used[200200], from[200200];
vector <int> a[200200], c[200200], id[200200];

int main()
{
	int x, y, z;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(y); c[x].push_back(z); id[x].push_back(i);
		a[y].push_back(x); c[y].push_back(z); id[y].push_back(i);
		flow[x] += z; flow[y] += z; 
		from[i] = x;
	}
	
	for (int i = 0; i < n; i++) flow[i] /= 2;
	queue <int> q;
	q.push(1); done[1] = 1;
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int i = 0; i < int(a[x].size()); i++)
		{
			int y = a[x][i], curId = id[x][i];
			if (used[curId] || done[y]) continue;
			flow[y] -= c[x][i]; used[curId] = x;
			if (!flow[y]) q.push(y), done[y] = 1;
		}
	}
	
	for (int i = 0; i < m; i++) cout << (from[i] != used[i]) << endl;
}