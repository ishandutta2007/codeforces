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
const int M = 1e6 + 10;
int flag[200][200];
struct Edge
{
	int x, y, w, pre;
};
class Graph
{
public:
	int top[N];
	Edge e[M];
	int k;
	void init(int sz = N)
	{
		memset(top, -1, sizeof(int)*sz);
		k = 0;
	}
	void addEdge(int x, int y, int w)
	{
		e[k] = Edge{x, y, w, top[x] };
		top[x] = k++;
		e[k] = Edge{y, x, 0, top[y] };
		top[y] = k++;
	}
	Edge& operator [] (int i)
	{
		return e[i];
	}
} g;
int layer[N];
int current[N];
int s, t;
bool bfs(int n)
{
	memset(layer, -1, sizeof(int)*n);
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
		int y = g[i].y;
		int w = g[i].w;
		current[x] = i;
		if (layer[y] == layer[x] + 1 && w > 0)
		{
			int tmp = dfs(y, min(w, tot - ret));
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
	int ret = 0;
	while (bfs(n))
	{
		memcpy(current, g.top, sizeof(int)*n);
		ret += dfs(s, INF);
	}
	return ret;
}
int a[N];
vector<pair<int, int>> vp;
int n, m, k;
void check(int x)
{
	map<int, int> mc;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		while (a[i] % x == 0) cnt++, a[i] /= x;
		if (cnt > 0)
		{
			if (i & 1) g.addEdge(s, k, cnt);
			else g.addEdge(k, t, cnt);
			mc[i] = k++;
		}
	}
	for (auto &p : vp)
	{
		int x, y;
		tie(x, y) = p;
		if (y & 1) swap(x, y);
		if (mc.count(x) && mc.count(y))
		{
			g.addEdge(mc[x], mc[y], INF);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	g.init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	s = 0, t = 1;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		vp.push_back({ x, y });
	}
	k = 2;
	for (int i = 2; i * i <= INF; i++)
	{
		check(i);
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1) continue;
		check(a[i]);
	}
	cout << solve(k) << endl;
	return 0;
}