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
const int N = 3e5 + 10;
class UnionFind
{
public:
	int p[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int vis[N];
vector<int> v[N];
int dis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (k--)
	{
		int x;
		scanf("%d", &x);
		vis[x] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(i + n);
		v[y].push_back(i + n);
		v[i + n].push_back(x);
		v[i + n].push_back(y);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	vis[s] = 1;
	vis[t] = 1;
	int l = 0, r = 1e7;
	int ans = -1;
	queue<int> q;
	MEM(dis, 0x3f);
	uf.init();
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
		{
			dis[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto& y : v[x])
		{
			uf.Union(x, y);
			if (dis[y] > dis[x] + 1)
			{
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
		if (uf.Find(s) == uf.Find(t))
		{
			ans = dis[x] + 1;
		}
		if (ans >= 0) break;
	}

	printf("%d\n", ans);
	return 0;
}