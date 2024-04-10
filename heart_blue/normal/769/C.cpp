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
char str[N][N];
int dis[N][N];
int pre[N][N];
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,-1,1,0 };
string s = "DLRU";
int kx, ky;
int n, m;
string ans;

void bfs(int x, int y)
{
	MEM(dis, 0);
	queue<pair<int, int>> q;
	q.emplace(x, y);
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (str[tx][ty] == '*') continue;
			if (dis[tx][ty] == 0)
			{
				dis[tx][ty] = dis[x][y] + 1;
				pre[tx][ty] = i;
				q.emplace(tx, ty);
			}
		}
	}
	dis[x][y] = 0;
}
void solve(int x, int y)
{
	bfs(x, y);
	string ans2;
	while (kx != x || ky != y)
	{
		int o = pre[kx][ky];
		ans2.push_back(s[o]);
		o = 3 - o;
		kx += dx[o];
		ky += dy[o];
	}
	reverse(ans2.begin(), ans2.end());
	ans += ans2;
	puts(ans.c_str());
	exit(0);
}
void dfs(int x, int y, int rest)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > m) return;
	if (str[x][y] == '*') return;
	if (dis[x][y] == rest)
	{
		solve(x, y);
	}
	for (int i = 0; i < 4; i++)
	{
		ans.push_back(s[i]);
		dfs(x + dx[i], y + dy[i], rest - 1);
		ans.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d%d%d", &n, &m, &k);
	if (k & 1)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	kx = -1, ky = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == 'X')
			{
				kx = i, ky = j;
			}
		}
	}
	bfs(kx, ky);
	dfs(kx, ky, k);
	puts("IMPOSSIBLE");
	
	return 0;
}