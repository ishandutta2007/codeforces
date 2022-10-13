#include <bits/stdc++.h>
using namespace std;

int n, m, d[100100], inDegree[100100];
vector <int> edgesTo[100100], a[100100];

int get(int x)
{
	return x == d[x] ? x : d[x] = get(d[x]);
}

void visit(int x, int par)
{
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		visit(y, x);
		if (inDegree[y]) edgesTo[y].push_back(x);
		else inDegree[x] ^= 1, edgesTo[x].push_back(y);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int m, x, y;
	
	cin >> n >> m;
	
	if (m % 2)
	{
		cout << "No solution\n";
		return 0;
	}
	
	for (int i = 1; i <= n; i++) d[i] = i;
	
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		
		if (get(x) == get(y)) edgesTo[y].push_back(x), inDegree[y] ^= 1;
		else
		{
			d[get(x)] = get(y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
	}
	
	visit(1, 0);
	
	for (int x = 1; x <= n; x++)
		for (int i = 0; i < int(edgesTo[x].size()); i += 2)
			cout << edgesTo[x][i] << ' ' << x << ' ' << edgesTo[x][i + 1] << endl;
}