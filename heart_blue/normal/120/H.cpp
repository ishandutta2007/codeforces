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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 2e6 + 10;
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
	int addEdge(int x, int y, int w, int w2 = 0)
	{
		int ret = k;
		e[k] = Node{ x,y,w,top[x] };
		top[x] = k++;
		e[k] = Node({ y,x,w2,top[y] });
		top[y] = k++;
		return ret;
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
vector<string> vs;
map<string, int> ms;
int cur;
void add(int n, char c1 = 0, char c2 = 0, char c3 = 0, char c4 = 0)
{
	char s[] = { c1,c2,c3,c4,0 };
	string str(s);
	if (!ms.count(str))
	{
		vs.push_back(str);
		ms[str] = ++cur;
		g.addEdge(cur, t, 1);
	}
	g.addEdge(n, ms[str], 1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	t = N - 1;
	g.init();
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		g.addEdge(s, i, 1);
	}
	cur = n;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		int len = str.length();
		for (int o1 = 0; o1 < len; o1++)
		{
			add(i, str[o1]);
			for (int o2 = o1 + 1; o2 < len; o2++)
			{
				add(i, str[o1], str[o2]);
				for (int o3 = o2 + 1; o3 < len; o3++)
				{
					add(i, str[o1], str[o2], str[o3]);
					for (int o4 = o3 + 1; o4 < len; o4++)
					{
						add(i, str[o1], str[o2], str[o3], str[o4]);
					}
				}
			}
		}
	}
	int s = solve(t + 1);
	if (s != n) puts("-1"), exit(0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = g.top[i]; ~j; j = g[j].pre)
		{
			int y = g[j].y;
			int r = g[j].r;
			if (y > n&& r == 0)
			{
				puts(vs[y - n - 1].c_str());
				break;
			}
		}
	}
	return 0;
}