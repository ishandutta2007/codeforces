#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int oo = 1 << 28;

int n, p[100100][18], up[100100], down[100100], depth[100100];
int maxChild[100100], maxChild2[100100], maxChild3[100100], bestUp[100100][18], bestDown[100100][18];
vector <int> a[100100];

void visit(int x, int par)
{
	p[x][0] = par;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		depth[y] = depth[x] + 1;
		visit(y, x);
		down[x] = max(down[x], down[y] + 1);
	}
}

int lca(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	for (int j = 17; j >= 0; j--)
		if (depth[x] - (1 << j) >= depth[y])
			x = p[x][j];
		
	if (x == y) return x;
	
	for (int j = 17; j >= 0; j--)
		if (p[x][j] != p[y][j])
			x = p[x][j], y = p[y][j];
	
	return p[x][0];
}

void calcUp(int x)
{
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == p[x][0]) continue;
		if (down[y] > down[maxChild[x]]) maxChild2[x] = maxChild[x], maxChild[x] = y;
		else
			if (down[y] > down[maxChild2[x]]) maxChild2[x] = y;
			else
				if (down[y] > down[maxChild3[x]]) maxChild3[x] = y;
	}
	
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == p[x][0]) continue;
		if (y != maxChild[x]) 
		{
			up[y] = max(up[x] + 1, down[maxChild[x]] + 2);
			bestUp[y][0] = down[maxChild[x]] + 2;
			bestDown[y][0] = down[maxChild[x]] + 1;
		}
		else 
		{
			up[y] = max(up[x] + 1, down[maxChild2[x]] + 2);
			if (maxChild2[x]) 
			{
				bestUp[y][0] = down[maxChild2[x]] + 2;
				bestDown[y][0] = down[maxChild2[x]] + 1;
			}
			else
			{
				bestUp[y][0] = 1;
				bestDown[y][0] = 0;
			}
		}
		
		calcUp(y);
	}
}

int getAncestor(int x, int k)
{
	for (int i = 17; i >= 0; i--)
		if (k >> i & 1) x = p[x][i];
	return x;
}

int getUp(int y, int x)
{
	int res = 0, tmpDepth = depth[y];
	for (int j = 17; j >= 0; j--)
		if (depth[y] - (1 << j) >= depth[x])
		{
			res = max(res, bestUp[y][j] + tmpDepth - depth[y]);
			y = p[y][j];
		}
	return res;
}

int getDown(int y, int x)
{
	int res = -oo;
	if (depth[y] <= depth[x]) return res;
	for (int j = 17; j >= 0; j--)
		if (depth[y] - (1 << j) >= depth[x])
		{
			int tmp = bestDown[y][j];
			y = p[y][j];
			res = max(res, tmp + depth[y] - depth[x]);
		}
	return res;
}

int query(int x, int y)
{
	if (x == y) return max(down[x], up[x]);
	
	int ans = 0, u = lca(x, y), dist = depth[x] + depth[y] - 2 * depth[u], topHalf = dist / 2 - 1 + dist % 2;
	if (depth[x] > depth[y]) swap(x, y);
	int midpoint = getAncestor(y, dist / 2);
	
	if (u == x)
	{
		int yy = getAncestor(y, depth[y] - depth[x] - 1);
		ans = max(up[x], down[y]);
		ans = max(ans, getUp(y, midpoint));
		
		int z = p[midpoint][0];
		if (midpoint != maxChild[z]) ans = max(ans, down[maxChild[z]] + 1 + topHalf);
		else ans = max(ans, down[maxChild2[z]] + 1 + topHalf);
		ans = max(ans, getDown(z, yy) + 1);
		
		if (yy != maxChild[x]) ans = max(ans, down[maxChild[x]] + 1);
		else ans = max(ans, down[maxChild2[x]] + 1);
	}
	else
	{
		int xx = getAncestor(x, depth[x] - depth[u] - 1);
		int yy = getAncestor(y, depth[y] - depth[u] - 1);
		ans = max(up[u] + depth[x] - depth[u], max(down[x], down[y]));
		ans = max(ans, getUp(x, xx));
		
		if (midpoint == u) ans = max(ans, getUp(y, yy));
		else
		{
			ans = max(ans, getUp(y, midpoint));
			int z = p[midpoint][0];
			if (z != u)
			{
				if (midpoint != maxChild[z]) ans = max(ans, down[maxChild[z]] + 1 + topHalf);
				else ans = max(ans, down[maxChild2[z]] + 1 + topHalf);
			} 
			ans = max(ans, getDown(z, yy) + depth[x] - depth[u] + 1);
		}
		
		if (xx != maxChild[u] && yy != maxChild[u]) ans = max(ans, down[maxChild[u]] + 1 + depth[x] - depth[u]);
		else
			if (xx != maxChild2[u] && yy != maxChild2[u]) ans = max(ans, down[maxChild2[u]] + 1 + depth[x] - depth[u]);
			else ans = max(ans, down[maxChild3[u]] + 1 + depth[x] - depth[u]);
	}
	
	return ans;
}

int main()
{
	int x, y, Q;
	
	cin >> n;
	
	down[0] = up[0] = -oo;
	for (int i = 1; i <= n; i++) 
	{
		a[i].clear();		
		maxChild[i] = maxChild2[i] = maxChild3[i] = up[i] = down[i] = depth[i] = 0;
		for (int j = 0; j < 18; j++) bestDown[i][j] = bestUp[i][j] = -oo;
	}
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y); a[y].push_back(x);
	}
	
	visit(1, 0);
	for (int j = 0; j < 17; j++)
		for (int i = 1; i <= n; i++)
			p[i][j + 1] = p[p[i][j]][j];
			
	calcUp(1);
	for (int j = 0; j < 17; j++)
		for (int i = 1; i <= n; i++)
		{
			bestUp[i][j + 1] = max(bestUp[i][j], bestUp[p[i][j]][j] + (1 << j));
			bestDown[i][j + 1] = max(bestDown[i][j] + (1 << j), bestDown[p[i][j]][j]);
		}
		
	cin >> Q;
	while (Q--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}

}