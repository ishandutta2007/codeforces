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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;
vector<int> v1[N], v2[N];
int vis1[N], vis2[N];
map<pair<int, int>, int> dis, key, mc;
deque<pair<int, int>> q;
int n, m, k;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void bfs(int x, int y, int d)
{
	if (mc.count({ x,y })) return;
	queue<pair<int, int>> qq;
	qq.emplace(x, y);
	mc[{x, y}] = 1;
	while (!qq.empty())
	{
		auto [x, y] = qq.front();
		qq.pop();
		for (int o = 0; o < 4; o++)
		{
			int tx = x + dx[o];
			int ty = y + dy[o];
			if (key.count({ tx,ty }) == 0) continue;
			if (mc.count({ tx,ty })) continue;
			mc[{tx, ty}] = 1;
			qq.emplace(tx, ty);
			if (!dis.count({ tx,ty }))
			{
				q.emplace_front(tx, ty);
				dis[{tx, ty}] = d;
			}
		}
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int flag = 0;
	while (k--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v1[x].push_back(y);
		v2[y].push_back(x);
		key[{x, y}] = 1;
		if (x == n && y == m)
		{
			flag = 1;
		}
	}
	q.emplace_back(1, 1);
	dis[{1, 1}] = 0;
	while (!q.empty())
	{
		vector<pair<int, int>> vp;
		int d = dis[{q.front().first, q.front().second}];
		while (!q.empty())
		{
			auto [x, y] = q.front();
			if (dis[{x, y}] != d) break;
			q.pop_front();
			vp.emplace_back(x, y);
			bfs(x, y, d);
		}
		for (auto [x, y] : vp)
		{
			for (int i = x - 2; i <= x + 2; i++)
			{
				if (i < 1) continue;
				if (!vis1[i])
				{
					vis1[i] = 1;
					for (auto& j : v1[i])
					{
						if (!dis.count({ i,j }))
						{
							dis[{i, j}] = d + 1;
							q.emplace_back(i, j);
						}
					}
				}
			}
			for (int j = y - 2; j <= y + 2; j++)
			{
				if (j < 1) continue;
				if (!vis2[j])
				{
					vis2[j] = 1;
					for (auto& i : v2[j])
					{
						if (!dis.count({ i,j }))
						{
							dis[{ i, j}] = d + 1;
							q.emplace_back(i, j);
						}
					}
				}
			}
		}
	}
	if (dis.count({ n,m }))
	{
		printf("%d\n", dis[{n, m}]);
		return 0;
	}
	int ans = INF;
	for (auto& y : v1[n])
	{
		if (dis.count({ n,y }))
			ans = min(ans, dis[{n, y}] + 1);
	}
	for (auto& y : v1[n - 1])
	{
		if (dis.count({ n - 1,y }))
			ans = min(ans, dis[{n - 1, y}] + 1);
	}
	for (auto& x : v2[m])
	{
		if (dis.count({ x,m }))
			ans = min(ans, dis[{x, m}] + 1);
	}
	for (auto& x : v2[m - 1])
	{
		if (dis.count({ x,m - 1 }))
			ans = min(ans, dis[{x, m - 1}] + 1);
	}
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}