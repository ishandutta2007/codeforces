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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char chess[N][N];
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(chess, 'X');
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> chess[i][j];
		}
	}
	int sx, sy;
	int ex, ey;
	cin >> sx >> sy >> ex >> ey;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = ex + dx[i];
		int y = ey + dy[i];
		if (chess[x][y] == '.') cnt++;
	}
	if (sx == ex && sy == ey)
	{
		if (cnt > 0) puts("YES");
		else puts("NO");
		return 0;
	}
	if (abs(sx - ex) + abs(sy - ey) == 1)
	{
		if (chess[ex][ey] == 'X')
		{
			puts("YES");
		}
		else
		{
			if (cnt > 0) puts("YES");
			else puts("NO");
		}
		return 0;
	}
	MEM(flag, 0);
	list<pair<int, int>> lp;
	lp.push_back({ sx,sy });
	flag[sx][sy] = 1;
	while (!lp.empty())
	{
		int x, y;
		tie(x, y) = lp.front();
		lp.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (flag[tx][ty]) continue;
			flag[tx][ty] = 1;
			if (chess[tx][ty] == 'X') continue;
			lp.push_back({ tx,ty });
		}
	}
	if (flag[ex][ey])
	{
		if (chess[ex][ey] == 'X') puts("YES");
		else if (cnt > 1) puts("YES");
		else puts("NO");
	}
	else puts("NO");
	return 0;
}