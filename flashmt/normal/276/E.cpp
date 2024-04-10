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
using namespace std;

int n, dist[100100], branch[100100], sz[100100];
vector <int> a[100100];
int *f[100100], fromRoot[100100];

void visit(int x, int par, int idBranch)
{
	branch[x] = idBranch;
	sz[idBranch]++;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		dist[y] = dist[x] + 1;
		visit(y, x, idBranch);
	}
}

void add(int f[], int x, int val, int mx)
{
	for (int i = x + 1; i <= mx + 1; i += i & -i) f[i] += val;
}

int get(int f[], int x)
{
	int res = 0;
	for (int i = x + 1; i; i -= i & -i) res += f[i];
	return res;
}

int main()
{
	//freopen("e.in","r",stdin);
	int Q, x, y, type, v, d;
	
	cin >> n >> Q;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for (int i = 0; i < int(a[1].size()); i++) 
	{
		dist[a[1][i]] = 1;
		visit(a[1][i], 1, i);
		f[i] = new int[sz[i] + 5];
		for (int j = 0; j <= sz[i] + 1; j++) f[i][j] = 0;
	}
	
	while (Q--)
	{
		scanf("%d%d", &type, &v);
		if (type)
		{
			int ans = get(fromRoot, dist[v]);
			if (v != 1) ans += get(f[branch[v]], dist[v]);
			printf("%d\n", ans);
		}
		else
		{
			scanf("%d%d", &x, &d);
			if (v != 1)
			{
				int idBranch = branch[v];
				int from = max(1, dist[v] - d), to = min(sz[idBranch], dist[v] + d);
				d -= dist[v];
				from = max(from, d + 1);
				if (from <= to)
				{
					add(f[idBranch], from, x, sz[idBranch]);
					add(f[idBranch], to + 1, -x, sz[idBranch]);
				}
			}
			if (d < 0) continue;
			add(fromRoot, 0, x, n);
			add(fromRoot, d + 1, -x, n);
		}
	}
}