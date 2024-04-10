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
const int N = 3e2 + 10;
int n, m;
char str[N][N];
int dx[] = { 0,1,0,-1,-1,1,-1,1 };
int dy[] = { 1,0,-1,0,1,1,-1,-1 };
vector<pair<int, int>> vp;
void dfs(int x, int y)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > m) return;
	if (str[x][y] == '0') return;
	str[x][y] = '0';
	vp.emplace_back(x, y);
	for (int i = 0; i < 8; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
int check()
{
	if (vp.size() <= 1) return 0;
	int lx = INF, rx = -INF;
	int ly = INF, ry = -INF;
	for (auto& [x, y] : vp)
	{
		lx = min(lx, x);
		rx = max(rx, x);
		ly = min(ly, y);
		ry = max(ry, y);
	}
	if (rx - lx != ry - ly) return 0;
	if ((rx - lx) * 4 != vp.size()) return 0;
	for (auto& [x, y] : vp)
	{
		if (x == lx || x == rx || y == ly || y == ry) continue;
		return 0;
	}
	return 1;
}
void refrain()
{
	int o1 = vp.front().first & 1;
	int o2 = vp.front().second & 1;
	for (auto& [x, y] : vp)
	{
		if ((x + y) % 2 != (o1 + o2) % 2)
		{
			vp.clear();
			return;
		}
	}
	for (auto& [x, y] : vp)
	{
		x -= o1, y -= o2;
		tie(x, y) = make_pair((x + y) / 2, (x - y) / 2);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				vp.clear();
				dfs(i, j);
				if (vp.empty()) continue;
				ans += check();
				refrain();
				ans += check();
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}