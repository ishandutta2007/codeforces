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
const int N = 2e5 + 10;
const int M = 2e5 + 10;
struct Edge
{
	int x, y, r, c, pre;
};
class Graph
{
public:
	int top[N];
	Edge e[M];
	int k;
	void init(int n = N)
	{
		k = 0;
		memset(top, -1, sizeof(int)*n);
	}
	inline void addEdge(int x, int y, int r, int c)
	{
		e[k] = Edge{ x,y,r,c,top[x] };
		top[x] = k++;
		e[k] = Edge{ y,x,0,-c,top[y] };
		top[y] = k++;
	}
	inline Edge& operator [] (int i)
	{
		return e[i];
	}
} g;
int dis[N];
int pre[N];
int delta[N];
int s, t;
bool spfa(int n)
{
	memset(dis, 0xaf, sizeof(int)*n);
	deque<int> q;
	q.push_back(s);
	dis[s] = 0;
	delta[s] = INF;
	while (!q.empty())
	{
		int x = q.front();
		q.pop_front();
		for (int i = g.top[x]; ~i; i = g[i].pre)
		{
			int y = g[i].y;
			int r = g[i].r;
			int c = g[i].c;
			if (r > 0 && dis[y] < dis[x] + c)
			{
				dis[y] = dis[x] + c;
				delta[y] = min(r, delta[x]);
				pre[y] = i;
				if (!q.empty() && dis[y] >= dis[q.front()]) q.push_front(y);
				else q.push_back(y);
			}
		}
	}
	return dis[t] != 0xafafafaf;
}
int ans = 0;
void solve(int n, int &maxflow, int &maxcost)
{
	maxflow = 0;
	maxcost = 0;
	while (spfa(n))
	{
		maxflow += delta[t];
		maxcost += delta[t] * dis[t];
		ans = max(ans, maxcost);
		int x = t;
		while (x != s)
		{
			int o = pre[x];
			g[o].r -= delta[t];
			g[o ^ 1].r += delta[t];
			x = g[o].x;
		}
	}
}
vector<int> v1, v2, v;
void build()
{
	g.init(t + 1);
	int n = v.size();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0) continue;
		g.addEdge(s, i + 1, 1, 0);
	}
	for (int i = 0; i < v1.size(); i++)
	{
		g.addEdge(i + 1 + n, t, 1, 0);
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0) continue;
		for (int j = 0; j < v1.size(); j++)
		{
			if (v[i] >= v1[j])
			{
				g.addEdge(i + 1, j + 1 + n, 1, v[i] - v1[j]);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	s = 0, t = n + m + 1;
	while (n--)
	{
		string str;
		int x;
		cin >> str >> x;
		if (str == "ATK") v1.push_back(x);
		else v2.push_back(x);
	}
	while (m--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	if (!v1.empty()) sort(v1.begin(), v1.end());
	if (!v2.empty()) sort(v2.begin(), v2.end());
	if (!v.empty()) sort(v.begin(), v.end());
	int maxflow, maxcost;
	build();
	solve(t + 1, maxflow, maxcost);
	ans = max(ans, maxcost);
	int flag = 1;
	int ptr = 0;
	for (auto &x : v2)
	{
		while (ptr < v.size() && v[ptr] <= x) ptr++;
		if (ptr == v.size())
		{
			flag = 0;
			break;
		}
		v[ptr] = -v[ptr];
		ptr++;
	}
	if (flag)
	{
		build();
		solve(t + 1, maxflow, maxcost);
		if (maxflow == v1.size())
		{
			int tmp = 0;
			for (auto &x : v) tmp += max(0, x);
			for (auto &x : v1) tmp -= x;
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}