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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
class BIT
{
public:
	int a[N];
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
} b1, b2;
vector<int> v[N];
int depth[N];
int dfn[N];
int out[N];
int bfn[N];
int top[N];
int ro[N];
int cnt = 0;
void dfs(int x = 1, int fa = 0)
{
	dfn[x] = ++cnt;
	depth[x] = depth[fa] + 1;
	if (fa)
	{
		if (fa == 1) top[x] = x;
		else top[x] = top[fa];
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
void bfs()
{
	cnt = 1;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		bfn[x] = cnt++;
		ro[depth[x]] = bfn[x];
		for (auto& y : v[x])
		{
			if (depth[x] + 1 == depth[y])
			{
				q.push(y);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	fill(ro, ro + N, n);
	dfs();
	bfs();
	while (q--)
	{
		int op;
		scanf("%d", &op);
		if (op == 0)
		{
			int v, x, d;
			scanf("%d%d%d", &v, &x, &d);
			if (v == 1)
			{
				int l = 1, r = ro[d + 1];
				b2.add(l, x);
				b2.add(r + 1, -x);
				continue;
			}
			int id = dfn[v];
			int lo = min(out[v], id + d);
			int up = max(dfn[top[v]], id - d);
			if (id - d < dfn[top[v]])
			{
				int delta = dfn[top[v]] - (id - d);
				int l = 1, r = ro[delta];
				b2.add(l, x);
				b2.add(r + 1, -x);
				up = max(up, dfn[top[v]] + (delta - 1));
			}
			if (up <= lo)
			{
				b1.add(up, x);
				b1.add(lo + 1, -x);
			}
		}
		else
		{
			int v;
			scanf("%d", &v);
			printf("%d\n", b1.sum(dfn[v]) + b2.sum(bfn[v]));
		}
	}
	return 0;
}