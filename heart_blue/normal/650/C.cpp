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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e6 + 10;
int n, m;
class UnionSet
{
public:
	int fa[N];
	void init()
	{
		MEM(fa, -1);
	}
	int treesize(int x)
	{
		return -fa[Find(x)];
	}
	int Find(int x)
	{
		int root = x;
		while (fa[root] >= 0) root = fa[root];
		while (x != root)
		{
			int tmp = fa[x];
			fa[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
	}
} uf;
vector<pair<int, int>> v1[N];
vector<pair<int, int>> v2[N];
vector<int> v[N];
int deg[N];
int dis[N];
int a[N];
int *p[N];
void check(vector<pair<int, int>> vp[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		sort(vp[i].begin(), vp[i].end());
		for (int j = 0; j + 1 < m; j++)
		{
			if (vp[i][j].first == vp[i][j + 1].first)
			{
				int pos1 = vp[i][j].second;
				int pos2 = vp[i][j + 1].second;
				if (uf.Find(pos1) != uf.Find(pos2))
					uf.Union(pos1, pos2);
			}
		}
	}
}
void build(vector<pair<int, int>> vp[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < m; j++)
		{
			if (vp[i][j].first != vp[i][j + 1].first)
			{
				int pos1 = vp[i][j].second;
				int pos2 = vp[i][j + 1].second;
				pos1 = uf.Find(pos1);
				pos2 = uf.Find(pos2);
				v[pos1].push_back(pos2);
				deg[pos2]++;
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	uf.init();
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			v1[i].push_back({ x,tot });
			v2[j].push_back({ x,tot });
			a[tot++] = x;
		}
	}
	check(v1, n, m);
	check(v2, m, n);
	build(v1, n, m);
	build(v2, m, n);
	queue<int> q;
	for (int i = 0; i < tot; i++)
	{
		if (uf.Find(i) == i && deg[i] == 0)
		{
			q.push(i);
			dis[i] = 1;
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto &y : v[x])
		{
			dis[y] = max(dis[y], dis[x] + 1);
			if (deg[y]-- == 1)
				q.push(y);
		}
	}
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d%c", dis[uf.Find(cur++)], " \n"[j == m - 1]);
		}
	}

	return 0;
}