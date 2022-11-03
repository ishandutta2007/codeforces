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
	int x, y, r, pos, pre;
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
	void addEdge(int x, int y, int w, int pos = 0, int w2 = 0)
	{
		e[k] = Node{ x,y,w,pos,top[x] };
		top[x] = k++;
		e[k] = Node({ y,x,w2,pos,top[y] });
		top[y] = k++;
	}
	Node& operator [](int i)
	{
		return e[i];
	}
	void refrain(int n1, int n2 = 0, int x = 1)
	{
		for (int i = 0; i < n1; i++)
		{
			int o = i << 1;
			e[o].r = x;
			e[o ^ 1].r = 0;
		}
		for (int i = n1; i < n1 + n2; i++)
		{
			int o = i << 1;
			e[o].r = 1;
			e[o ^ 1].r = 0;
		}
	}
	void addup(int x)
	{
		e[k - 2].r = x;
		e[k - 1].r = 0;
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
int deg[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	s = 0;
	int s1 = n1 + n2 + 1;
	t = s1 + 1;
	g.init(t + 1);
	int flag = 0;
	if (n1 > n2) flag = 1, swap(n1, n2);
	for (int i = 1; i <= n1; i++) g.addEdge(s1, i, 1);
	for (int i = 1; i <= n2; i++) g.addEdge(i + n1, t, INF);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (flag) swap(x, y);
		deg[x]++;
		deg[y + n1]++;
		g.addEdge(x, y + n1, 1, i);
	}
	g.addEdge(s, s1, 0);
	int mind = INF;
	for (int i = 1; i <= n1 + n2; i++)
	{
		mind = min(mind, deg[i]);
	}
	puts("0");
	int ok = 1;
	for (int i = 1; i <= mind; i++)
	{
		if (ok == 0)
		{
			puts("0");
			continue;
		}
		g.refrain(n1, n2, n2 / n1);
		int sum = 0;
		while (1)
		{
			g.addup(n2 - sum);
			int ans = solve(t + 1);
			if (ans == 0)
			{
				break;
			}
			sum += ans;
			if (sum == n2) break;
			g.refrain(n1);
		}
		if (sum != n2)
		{
			ok = 0;
			i--;
			continue;
		}
		printf("%d", i*n2);
		for (int i = 2 * (n1 + n2); i < g.k - 2; i += 2)
		{
			if (g[i].r == 0)
				printf(" %d", g[i].pos);
		}
		puts("");
	}
	return 0;
}