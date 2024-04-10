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
class BIT
{
	int a[N];
public:
	void add(int x, int val)
	{
		while (x < N)
		{
			a[x] += val;
			x += x & -x;
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x)
		{
			ret += a[x];
			x -= x & -x;
		}
		return ret;
	}
} b;
vector<pair<int, int>> vp[N];
vector<int> v[N];
int sum[N];
pair<int, int> pos[N];
int node[N];
int deg[N];
int dfs(int x, int o = 0, int fa = 0)
{
	v[o].push_back(x);
	for (auto [y, id] : vp[x])
	{
		if (y == fa) continue;
		node[id] = y;
		if (fa == 0)
		{
			o++;
			v[o].push_back(0);
		}
		dfs(y, o, x);
	}
	return o;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].emplace_back(y, i);
		vp[y].emplace_back(x, i);
		deg[x]++;
		deg[y]++;
	}
	int rt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] > deg[rt])
			rt = i;
	}
	int sz = dfs(rt);
	for (int i = 1; i <= sz; i++)
	{
		sum[i] = sum[i - 1] + v[i].size() - 1;
		for (int j = 1; j < v[i].size(); j++)
		{
			int x = v[i][j];
			pos[x] = { i,j };
		}
	}
	pos[rt] = { 1,0 };
	for (int i = 1; i <= n; i++) b.add(i, 1);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d", &op, &x);
		if (op <= 2)
		{
			int val = 1;
			if (op == 2) val = -1;
			x = node[x];
			auto [r, c] = pos[x];
			b.add(sum[r - 1] + c, val);
		}
		else
		{
			scanf("%d", &y);
			auto [r1, c1] = pos[x];
			auto [r2, c2] = pos[y];
			int ans;
			if (r1 == r2 && (c1 * c2 != 0))
			{
				ans = abs(c1 - c2);
				if (c1 > c2) swap(c1, c2);
				if (b.sum(sum[r2 - 1] + c2) - b.sum(sum[r1 - 1] + c1) != ans)
					ans = -1;
			}
			else
			{
				ans = c1 + c2;
				if (b.sum(sum[r1 - 1] + c1) - b.sum(sum[r1 - 1]) +
					b.sum(sum[r2 - 1] + c2) - b.sum(sum[r2 - 1])
					!= ans)
					ans = -1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}