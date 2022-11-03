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
const int N = 2e3 + 10;
int dis[N][N];
LL dis2[N][N];
vector<pair<int, pair<int, int>>> vp;
vector<pair<int, LL>> v[N];
class UnionFind
{
private:
	int p[N];
public:
	int size(int x)
	{
		int px = Find(x);
		return -p[px];
	}
	void init()
	{
		MEM(p, -1);
	}
	int Find(int x)
	{
		int root = x;
		while (p[root] >= 0) root = p[root];
		while (x != root)
		{
			int tmp = p[x];
			p[x] = root;
			x = tmp;
		}
		return root;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (size(px) > size(py)) swap(px, py);
		int total = size(px) + size(py);
		p[px] = py;
		p[py] = -total;
	}
} uf;
void dfs(int x, int fa, int o, LL len)
{
	dis2[o][x] = len;
	for (auto &p : v[x])
	{
		int y;
		LL w;
		tie(y, w) = p;
		if (y == fa) continue;
		dfs(y, x, o, len + w);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &dis[i][j]);
			if (dis[i][j] > 0)
			{
				vp.push_back({ dis[i][j],{i,j} });
			}
			if ((i == j) ^ (dis[i][j] == 0))
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	int cnt = 0;
	sort(vp.begin(), vp.end());
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p.second;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
			cnt++;
			v[x].push_back({ y,p.first });
			v[y].push_back({ x,p.first });
		}

	}
	if (cnt + 1 != n)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, -1, i, 0);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dis[i][j] != dis2[i][j])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}