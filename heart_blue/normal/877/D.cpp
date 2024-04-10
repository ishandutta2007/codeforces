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
const int N = 2e3 + 10;
char board[N][N];
int dis[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dis, 0x3f);
	int inf = 0x3f3f3f3f;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	dis[x][y] = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	cin >> x >> y;
	int &ans = dis[x][y];
	while (!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();
		for (int o = 0; o < 4; o++)
		{
			for (int i = 1; i <= k; i++)
			{
				int tx = x + dx[o] * i;
				int ty = y + dy[o] * i;
				if (tx <= 0 || tx > n) break;
				if (ty <= 0 || ty > m) break;
				if (board[tx][ty] == '#') break;
				if (dis[tx][ty] <= dis[x][y]) break;
				if (dis[tx][ty] > dis[x][y] + 1)
				{
					dis[tx][ty] = dis[x][y] + 1;
					q.push({ tx,ty });
				}
			}
		}
	}
	if (ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}