#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 1e3 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int n, m;
LL k;
int a[M][M];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
inline int id(int x, int y)
{
	return (x - 1) * m + y;
}
void dfs(int x, int y, int val, int& rest)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > m) return;
	if (rest == 0) return;
	if (a[x][y] < val) return;
	a[x][y] = -val;
	rest--;
	for (int o = 0; o < 4; o++)
	{
		dfs(x + dx[o], y + dy[o], val, rest);
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	uf.init();
	scanf("%d%d%lld", &n, &m, &k);
	vector<tuple<int, int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			vp.emplace_back(a[i][j], i, j);
		}
	}
	sort(vp.begin(), vp.end());
	while (!vp.empty())
	{
		int x, y;
		int val;
		tie(val, x, y) = vp.back();
		while (!vp.empty())
		{
			int tv, x, y;
			tie(tv, x, y) = vp.back();
			if (tv != val) break;
			vp.pop_back();
			for (int o = 0; o < 4; o++)
			{
				if (a[x][y] <= a[x + dx[o]][y + dy[o]])
				{
					uf.Union(id(x, y), id(x + dx[o], y + dy[o]));
				}
			}
			int sz = uf.treesize(id(x, y));
			if (k % val) continue;
			if (k / val > sz) continue;
			int rest = k / val;
			dfs(x, y, val, rest);
			puts("YES");
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (a[i][j] < 0)
						a[i][j] = -a[i][j];
					else
						a[i][j] = 0;
					printf("%d%c", a[i][j], " \n"[j == m]);
				}

			}
			return 0;
		}
	}
	puts("NO");
	return 0;
}