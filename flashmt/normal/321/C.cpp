#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, color[100100], cnt[100100], visited[100100], R;
vector <int> region[100100], a[100100];

void dfs(int x, int c)
{
	region[R].push_back(x);
	visited[x] = c;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (color[y] < 0 && visited[y] < c) dfs(y, c);
	}
}

int findCenter(int x, int par, int n)
{
	int ok = 1;
	cnt[x] = 1;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y != par && color[y] < 0)
		{
			int u = findCenter(y, x, n);
			if (u) return u;
			cnt[x] += cnt[y];
			if (cnt[y] * 2 > n) ok = 0;
		}
	}
	
	if (ok && (n - cnt[x]) * 2 <= n) return x;
	return 0;
}

int main()
{
	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	memset(color, -1, sizeof(color));
	memset(visited, -1, sizeof(visited));
	for (int c = 0; c < 26; c++)
	{
		R = 0;
		for (int i = 1; i <= n; i++)
			if (color[i] < 0 && visited[i] < c)
			{
				region[R].clear();
				dfs(i, c);
				R++;
			}
			
		for (int i = 0; i < R; i++)
			color[findCenter(region[i][0], 0, region[i].size())] = c;
	}
	
	for (int i = 1; i <= n; i++) printf("%c ", char(color[i] + 'A'));
}