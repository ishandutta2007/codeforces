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
const int N = 3e5 + 10;
int dis[N];
int flag[N];
vector<int> v[N];
vector<int> vp;
class UnionSet
{
public:
	int fa[N];
	int len[N];
	void init()
	{
		MEM(fa, -1);
		MEM(len, 0);
	}
	int getLen(int x)
	{
		x = Find(x);
		return len[x];
	}
	void setLen(int x, int l)
	{
		x = Find(x);
		len[x] = l;
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
		int l1 = getLen(px);
		int l2 = getLen(py);
		if (fa[px] > fa[py]) swap(px, py);
		int sz = fa[px] + fa[py];
		fa[py] = px;
		fa[px] = sz;
		setLen(x, max(max(l1, l2), (l1 + 1) / 2 + (l2 + 1) / 2 + 1));
	}
} uf;
void dfs(int x, int fa = -1)
{
	dis[x] = 0;
	flag[x] = 1;
	vp.push_back(x);
	if (fa != -1) dis[x] = dis[fa] + 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	MEM(dis, 0);
	MEM(flag, 0);
	uf.init();
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		vp.clear();
		dfs(i);
		int key = i;
		for (auto &x : vp)
		{
			if (dis[x] > dis[key])
				key = x;
		}
		vp.clear();
		dfs(key);
		for (auto &x : vp)
		{
			if (dis[x] > dis[key])
				key = x;
		}
		uf.setLen(i, dis[key]);
	}
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int x;
			scanf("%d", &x);
			printf("%d\n", uf.getLen(x));
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (uf.Find(x) != uf.Find(y))
			{
				uf.Union(x, y);
			}
		}
	}
	return 0;
}