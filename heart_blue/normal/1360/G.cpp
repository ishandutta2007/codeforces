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
		memset(top, -1, sizeof(int) * sz);
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
	memset(layer, -1, sizeof(int) * sz);
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
		memcpy(current, g.top, sizeof(int) * sz);
		ret += dfs(s);
	}
	return ret;
}
char str[52][52];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, a, b;
		scanf("%d%d%d%d", &n, &m, &a, &b);
		if (n * a != b * m)
		{
			puts("NO");
			continue;
		}
		s = 0, t = n + m + 1;
		int sz = t + 1;
		g.init(sz);
		for (int i = 1; i <= n; i++) g.addEdge(s, i, a);
		for (int i = 1; i <= m; i++) g.addEdge(i + n, t, b);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				g.addEdge(i, j + n, 1);
		}
		int tot = solve(sz);
		if (tot != n * a)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		MEM(str, '0');
		for (int i = 0; i < g.k; i += 2)
		{
			if (g[i].x > 0 && g[i].r == 0)
			{
				str[g[i].x][g[i].y - n] = '1';
			}
		}
		for (int i = 1; i <= n; i++)
		{
			str[i][m + 1] = 0;
			puts(str[i] + 1);
		}
	}
	return 0;
}