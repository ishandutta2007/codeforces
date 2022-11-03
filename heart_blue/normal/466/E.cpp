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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
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
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int flag[N];
int in[N];
int out[N];
int deg[N];
int depth[N];
int key[N];
int minv[N];
int cnt = 0;
vector<int> v[N];
void dfs(int x, int fa = 0)
{
	in[x] = ++cnt;
	depth[x] = depth[fa] + 1;
	for (auto& y : v[x])
	{
		dfs(y, x);
	}
	out[x] = cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<tuple<int, int, int>> qr;
	int n, q;
	scanf("%d%d", &n, &q);
	while (q--)
	{
		int op, x, y;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d", &x, &y);
			v[y].push_back(x);
			deg[x]++;
		}
		if (op == 2)
		{
			scanf("%d", &x);
			y = x;
		}
		if (op == 3)
		{
			scanf("%d%d", &x, &y);
		}
		qr.emplace_back(op, x, y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			v[0].push_back(i);
	}
	dfs(0);
	int cur = 0;
	uf.init();
	for (auto [op, x, y] : qr)
	{
		if (op == 1)
		{
			uf.Union(y, x);
		}
		if (op == 2)
		{
			cur++;
			minv[cur] = depth[uf.Find(x)];
			key[cur] = x;
		}
		if (op == 3)
		{
			int id = y;
			int d = minv[id];
			int pos = in[key[id]];
			if (d > depth[x])
			{
				puts("NO");
				continue;
			}
			if (in[x] <= pos && pos <= out[x]) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}