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
const int M = 1e5 + 10;
struct Node
{
	int x, y, c, r, pre;
};
class Graph
{
public:
	int top[N];
	Node e[M];
	int n;
	void init(int sz = N)
	{
		n = 0;
		memset(top, -1, sizeof(int) * sz);
	}
	void addEdge(int x, int y, int c, int w)
	{
		e[n] = Node{ x,y,c,w,top[x] };
		top[x] = n++;
		e[n] = Node{ y,x,-c,0,top[y] };
		top[y] = n++;
	}
	Node& operator [] (int i)
	{
		return e[i];
	}
} g;
int s, t;
int dis[N];
int delta[N];
int in[N];
int pre[N];
int b[N];
bool bfs(int sz = N)
{
	deque<int> q;
	q.push_back(s);
	memset(in, 0, sizeof(int) * sz);
	memset(dis, 0xdf, sizeof(int) * sz);
	int inf = dis[0];
	in[s] = 1;
	dis[s] = 0;
	delta[s] = INF;
	pre[s] = -1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop_front();
		in[x] = 0;
		for (int i = g.top[x]; ~i; i = g[i].pre)
		{
			int y = g[i].y;
			int r = g[i].r;
			int c = g[i].c;
			if (r > 0 && dis[y] < dis[x] + c)
			{
				dis[y] = dis[x] + c;
				delta[y] = min(delta[x], r);
				pre[y] = i;
				if (!in[y])
				{
					in[y] = 1;
					if (!q.empty() && dis[y] >= dis[q.front()]) q.push_front(y);
					else q.push_back(y);
				}
			}
		}
	}
	return dis[t] != inf;
}
void solve(int& flow, int& cost, int sz = N)
{
	flow = 0;
	cost = 0;
	while (bfs(sz))
	{
		int d = delta[t];
		flow += d;
		cost += d * dis[t];
		int x = t;
		while (pre[x] != -1)
		{
			int o = pre[x];
			g[o].r -= d;
			g[o ^ 1].r += d;
			x = g[o].x;
		}
	}
}
int id(char c)
{
	if (islower(c)) return c - 'a' + 1;
	else return c - 'A' + 27;
}
int cost[200][200];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	s = 0, t = k * 2 + 1;
	g.init(t + 1);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++)
	{
		cost[id(s1[i])][id(s2[i])]++;
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			g.addEdge(i, j + k, cost[i][j], 1);
		}
	}
	for (int i = 1; i <= k; i++) g.addEdge(s, i, 0, 1);
	for (int i = 1; i <= k; i++) g.addEdge(i + k, t, 0, 1);
	int flow = 0, cost = 0;
	solve(flow, cost, t + 1);
	printf("%d\n", cost);
	string ans;
	for (int i = 1; i <= k; i++)
	{
		for (int j = g.top[i]; ~j; j = g[j].pre)
		{
			int y = g[j].y;
			int r = g[j].r;
			if (y > k&& r == 0)
			{
				y -= k;
				if (y <= 26) putchar(y + 'a' - 1);
				else putchar(y - 26 + 'A' - 1);
				break;
			}
		}
	}
	return 0;
}