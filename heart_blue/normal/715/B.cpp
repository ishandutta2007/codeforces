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
const int N = 1e3 + 10;
const int M = 2e4 + 10;
LL dis[N];
int vis[N];
struct Node
{
	int x, y, w, pre;
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
LL solve(int s, int t, int o)
{
	typedef pair<LL, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	MEM(dis, 0x3f);
	dis[s] = 0;
	pq.push({ dis[s],s });
	MEM(vis, 0);
	while (!pq.empty())
	{
		LL d;
		int x;
		tie(d, x) = pq.top();
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = g.top[x]; ~i; i = g[i].pre)
		{
			int y = g[i].y;
			int w = g[i].w;
			if (w == 0) w = o;
			if (dis[y] > dis[x] + w)
			{
				dis[y] = dis[x] + w;
				pq.push({ dis[y],y });
			}
		}
	}
	return dis[t];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, l, s, t;
	cin >> n >> m >> l >> s >> t;
	g.init(n);
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x, y, w, w);
	}
	if (solve(s, t, l + 1) < l) puts("NO");
	else if (solve(s, t, 1) > l) puts("NO");
	else
	{
		for (int i = 0; i < g.k; i += 2)
		{
			if (g[i].w == 0)
			{
				g[i].w = g[i ^ 1].w = 1;
				if (solve(s, t, l + 1) <= l)
				{
					g[i].w = g[i ^ 1].w = l - dis[t] + 1;
					break;
				}
			}
		}
		puts("YES");
		for (int i = 0; i < g.k; i += 2)
		{
			int x = g[i].x;
			int y = g[i].y;
			int w = g[i].w;
			if (w == 0) w = l + 1;
			printf("%d %d %d\n", x, y, w);
		}
	}
	return 0;
}