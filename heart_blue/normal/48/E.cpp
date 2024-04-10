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
const int N = 4e2 + 10;
int dis[N][N];
int dp[N][N];
int in[N][N];
int a[N][2];
int b[N][2];
int n, m, r;
int flag = 0;
int bfs(int x, int y)
{
	MEM(dis, 0x3f);
	dis[x][y] = 0;
	queue<pair<int, int>> q;
	q.emplace(x, y);
	while (!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 1; i <= min(x, n); i++)
		{
			int dx = x - i + a[i][0];
			int dy = y + a[i][1];
			if (dx + dy > r) continue;
			if (dis[dx][dy] > dis[x][y] + 1)
			{
				dis[dx][dy] = dis[x][y] + 1;
				q.emplace(dx, dy);
			}
		
		}
		for (int i = 1; i <= min(y, m); i++)
		{
			int dx = x + b[i][0];
			int dy = y - i + b[i][1];
			if (dx + dy > r) continue;
			if (dis[dx][dy] > dis[x][y] + 1)
			{
				dis[dx][dy] = dis[x][y] + 1;
				q.emplace(dx, dy);
			}
		}
	}
	if (dis[0][0] == 0x3f3f3f3f) return INF;
	else return dis[0][0];
}
void dfs(int x, int y)
{
	if (in[x][y]) flag = 1;
	if (dp[x][y] != -1) return;
	if (x + y > r)
	{
		dp[x][y] = 0;
		return;
	}
	if (x + y == 0)
	{
		dp[x][y] = -INF;
		return;
	}
	dp[x][y] = 0;
	in[x][y] = 1;
	for (int i = 1; i <= min(x, n); i++)
	{
		int dx = x - i + a[i][0];
		int dy = y + a[i][1];
		dfs(dx, dy);
		dp[x][y] = max(dp[x][y], dp[dx][dy] + 1);
	}
	for (int i = 1; i <= min(y, m); i++)
	{
		int dx = x + b[i][0];
		int dy = y - i + b[i][1];
		dfs(dx, dy);
		dp[x][y] = max(dp[x][y], dp[dx][dy] + 1);
	}
	in[x][y] = 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, t;
	scanf("%d%d%d", &h, &t, &r);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i][0], &a[i][1]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &b[i][0], &b[i][1]);
	}
	int ans1 = bfs(h, t);
	if (ans1 != INF) printf("Ivan\n%d\n", dis[0][0]), exit(0);
	MEM(dp, -1);
	dfs(h, t);
	if (flag) puts("Draw");
	else printf("Zmey\n%d\n", dp[h][t]);

	return 0;
}