#include <bits/stdc++.h>
using namespace std;

int m, n, levels, w, lab[1010];
vector <int> adjacent[1010];
string a[1010][11];
vector < pair < int, pair<int,int> > > edges;

int get(int x)
{
	return x == lab[x] ? x : lab[x] = get(lab[x]);
}

void visit(int x, int par)
{
	cout << x + 1 << ' ' << par + 1 << endl;
	for (int i = 0; i < int(adjacent[x].size()); i++)
	{
		int y = adjacent[x][i];
		if (y != par) visit(y, x);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	
	cin >> m >> n >> levels >> w;
	for (int level = 0; level < levels; level++)
		for (int i = 0; i < m; i++)
			cin >> a[level][i];
			
	for (int u = 0; u < levels; u++)
		for (int v = u + 1; v < levels; v++)
		{
			int d = 0;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					d += a[u][i][j] != a[v][i][j];
					
			if (d * w < m * n) edges.push_back(make_pair(d * w, make_pair(u, v)));
		}
		
	sort(edges.begin(), edges.end());
	for (int i = 0; i < levels; i++) lab[i] = i;
	
	long long ans = 0;
	for (int i = 0; i < int(edges.size()); i++)
	{
		int x = edges[i].second.first, y = edges[i].second.second;
		int dx = get(x), dy = get(y);
		if (dx != dy)
		{
			lab[dx] = dy;
			adjacent[y].push_back(x);
			adjacent[x].push_back(y);
			ans += edges[i].first;
		}
	}
	
	set <int> labs;
	for (int i = 0; i < levels; i++) labs.insert(get(i));
	ans += labs.size() * n * m;
	
	cout << ans << endl;
	for (int i = 0; i < levels; i++)
		if (get(i) == i) visit(i, -1);
}