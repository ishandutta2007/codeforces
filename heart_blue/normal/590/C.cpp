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
LL dis[N][N][4];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char c[N][N];
queue<pair<int, int>> q[4];
int n, m;
LL check(int o)
{
	LL d[4] = { 0,INF*INF,INF*INF,INF*INF };
	while (!q[o].empty())
	{
		int x, y;
		tie(x, y) = q[o].front();
		q[o].pop();
		if (isdigit(c[x][y]))
		{
			LL &oo = d[c[x][y] - '0'];
			oo = min(oo, dis[x][y][o]);
		}
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= n) continue;
			if (ty < 0 || ty >= m) continue;
			if (c[tx][ty] == '#') continue;
			if (dis[tx][ty][o] > dis[x][y][o] + 1)
			{
				dis[tx][ty][o] = dis[x][y][o] + 1;
				q[o].push({ tx,ty });
			}
		}
	}
	return min(INF, d[1] + d[2] + d[3] - 2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	MEM(dis, 0x1f);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		for (int j = 0; j < m; j++)
		{
			if (isdigit(c[i][j]))
			{
				q[c[i][j] - '0'].push({ i,j });
				dis[i][j][c[i][j] - '0'] = 0;
			}
		}
	}
	LL ans = min(check(1), min(check(2), check(3)));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] != '.') continue;
			ans = min(ans, dis[i][j][1] + dis[i][j][2] + dis[i][j][3] - 2);
		}
	}
	if (ans >= INF) ans = -1;
	cout << ans << endl;
	return 0;
}