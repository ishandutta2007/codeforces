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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 9;
const int N = 1e5 + 10;
vector<int> v[N];
int low[N], dfn[N];
int in[N], s[N];
int sz[N];
int cnt, scccnt, top;
int flag[N];
int ans = 0;
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
void dfs(int x)
{
	dfn[x] = low[x] = ++cnt;
	in[x] = 1;
	s[top++] = x;
	for (auto &y : v[x])
	{
		if (dfn[y])
		{
			if (in[y]) low[x] = min(low[x], dfn[y]);
		}
		else
		{
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		scccnt++;
		while (1)
		{
			int y = s[--top];
			in[y] = 0;
			sz[scccnt]++;
			if (x == y) break;
		}
		if (sz[scccnt] > 1)
		{
			int &o = flag[uf.Find(x)];
			ans += o;
			o = 0;
		}
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fill(flag, flag + N, 1);
	int n, m;
	cin >> n >> m;
	uf.init();
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		if (uf.Find(x) != uf.Find(y))
		{
			uf.Union(x, y);
		}
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			dfs(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (uf.Find(i) == i)
			ans += uf.treesize(i) - 1;
	}
	printf("%d\n", ans);
	return 0;
}