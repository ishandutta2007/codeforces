#pragma comment(linker, "/STACK:102400000,102400000") 
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
const int N = 1e5 + 10;
const int M = 1e5 + 10;
struct Node
{
	int x, y, r, pre;
};
class Graph
{
public:
	int top[N];
	Node e[M];
	int k;
	void init(int sz = N)
	{
		memset(top, -1, sizeof(int)*sz);
		k = 0;
	}
	void addEdge(int x, int y, int w, int w2 = 0)
	{
		e[k] = Node{ x,y,w,top[x] };
		top[x] = k++;
		e[k] = Node({ y,x,w2,top[y] });
		top[y] = k++;
	}
	Node& operator [](int i)
	{
		return e[i];
	}
} g;
int layer[N];
int s, t;
int current[N];
bool bfs(int sz = N)
{
	memset(layer, -1, sizeof(int)*sz);
	layer[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = g.top[x]; ~i; i = g[i].pre)
		{
			int y = g[i].y;
			int r = g[i].r;
			if (r > 0 && layer[y] == -1)
			{
				layer[y] = layer[x] + 1;
				q.push(y);
				if (y == t) return true;
			}
		}
	}
	return false;
}
int dfs(int x, int tot = INF)
{
	if (x == t) return tot;
	int ret = 0;
	for (int i = current[x]; ~i; i = g[i].pre)
	{
		int y = g[i].y, r = g[i].r;
		if (layer[y] == layer[x] + 1 && r > 0)
		{
			current[x] = i;
			int tmp = dfs(y, min(r, tot - ret));
			g[i].r -= tmp;
			g[i ^ 1].r += tmp;
			ret += tmp;
			if (ret == tot) return ret;
		}
	}
	layer[x] = -1;
	return ret;
}
int solve(int sz = N)
{
	int ret = 0;
	while (bfs(sz))
	{
		memcpy(current, g.top, sizeof(int)*sz);
		ret += dfs(s);
	}
	return ret;
}
tuple<int, int, int> exam[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	s = 0, t = n + m + 1;
	g.init(t + 1);
	int tot = 0;
	for (int i = 1; i <= m; i++)
	{
		int st, ed, day;
		scanf("%d%d%d", &st, &ed, &day);
		exam[i] = { st,ed,day };
		ans[ed] = m + 1;
		tot += day;
	}
	for (int i = 1; i <= m; i++)
	{
		int st, ed, day;
		tie(st, ed, day) = exam[i];
		g.addEdge(s, i, day);
		for (int o = st; o < ed; o++)
		{
			if (ans[o]) continue;
			g.addEdge(i, o + m, 1);
		}
	}
	for (int i = 1; i <= n; i++) g.addEdge(m + i, t, 1);
	if (solve(t + 1) != tot)
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < g.k; i += 2)
	{
		int x = g[i].x;
		int y = g[i].y;
		if (x >= 1 && x <= m && y > m && y <= n + m)
		{
			if (g[i].r == 0)
			{
				ans[y - m] = x;
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}