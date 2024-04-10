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
const int M = 1e6 + 10;
int a[200][200];
struct Edge
{
	int x, y, w, pre;
};
class Graph
{
public:
	int top[N];
	Edge e[M];
	int k = 0;
	void addEdge(int x, int y, int w, int w0 = 0)
	{
		e[k] = Edge{ x,y,w,top[x] };
		top[x] = k++;
		e[k] = Edge{ y,x,w0,top[y] };
		top[y] = k++;
	}
	void init(int n = N)
	{
		memset(top, -1, sizeof(int)*n);
	}
	Edge& operator [] (int i)
	{
		return e[i];
	}
} g;
int current[N];
int layer[N];
int s, t;
bool bfs(int n)
{
	memset(layer, -1, sizeof(int)*n);
	queue<int> q;
	q.push(s);
	layer[s] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = g.top[x]; ~i; i = g[i].pre)
		{
			int y = g[i].y;
			int w = g[i].w;
			if (w > 0 && layer[y] == -1)
			{
				layer[y] = layer[x] + 1;
				if (y == t) return true;
				q.push(y);
			}
		}
	}
	return false;
}
int dfs(int x, int tot)
{
	if (x == t) return tot;
	int ret = 0;
	for (int i = current[x]; ~i; i = g[i].pre)
	{
		int y = g[i].y, w = g[i].w;
		if (w > 0 && layer[y] == layer[x] + 1)
		{
			int tmp = dfs(y, min(tot - ret, w));
			ret += tmp;
			g[i].w -= tmp;
			g[i ^ 1].w += tmp;
			if (ret == tot) return ret;
		}
	}
	layer[x] = -1;
	return ret;
}
int solve(int n)
{
	memcpy(current, g.top, sizeof(int)*n);
	int ans = 0;
	while (bfs(n))
	{
		ans += dfs(s, INF);
	}
	return ans;
}
int b[N];
int c[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	s = 0, t = 2 * n + 1;
	g.init(t + 1);
	int tot1 = 0, tot2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		g.addEdge(s, i, x);
		tot1 += x;
		b[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		g.addEdge(i + n, t, x);
		tot2 += x;
		a[i][i] = x;
		c[i] = x;
	}
	if (tot1 != tot2)
	{
		puts("NO");
		return 0;
	}
	int k = g.k;
	for (int i = 1; i <= n; i++) g.addEdge(i, i + n, b[i] + c[i]);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		g.addEdge(x + n, y, INF);
		g.addEdge(y + n, x, INF);
	}
	int ans = solve(t + 1);
	if (ans != tot1)
	{
		puts("NO");
		return 0;
	}
	for (int i = k; i < g.k; i += 2)
	{
		if (g[i ^ 1].w > 0)
		{
			int x = g[i].x;
			int y = g[i].y;
			if (x > n) x -= n;
			if (y > n) y -= n;
			if (x == y) continue;
			a[x][y] += g[i ^ 1].w;
			if (x != y) a[y][y] -= a[x][y];
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}