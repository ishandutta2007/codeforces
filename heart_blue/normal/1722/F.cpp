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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;
char str[N][N];
bool bfs(int n, int m, int x, int y)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.emplace(x, y);
	str[x][y] = '.';
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		v.emplace_back(x, y);
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int tx = x + i;
				int ty = y + j;
				if (tx < 1 || tx > n) continue;
				if (ty < 1 || ty > m) continue;
				if (str[tx][ty] != '*') continue;
				q.emplace(tx, ty);
				str[tx][ty] = '.';
			}
		}
	}
	if (v.size() != 3) return false;
	int u = INF, d = 0, l = INF, r = 0;
	for (auto [x, y] : v)
	{
		u = min(u, x);
		d = max(d, x);
		l = min(l, y);
		r = max(r, y);
	}
	return d - u == 1 && r - l == 1;

}
bool solve(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != '*') continue;
			if (!bfs(n, m, i, j))
				return false;

		}
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
		}
		if (solve(n, m)) puts("YES");
		else puts("NO");
	}
	return 0;
}