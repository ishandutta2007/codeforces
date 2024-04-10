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
LL dis[N][N];
char str[N][N];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
	}
	MEM(dis, 0x7f);
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int flag = 0;
			for (int o = 0; o < 4; o++)
			{
				int x = i + dx[o];
				int y = j + dy[o];
				if (x < 1 || x > n) continue;
				if (y < 1 || y > m) continue;
				if (str[x][y] == str[i][j])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				q.emplace(i, j), dis[i][j] = 0;
		}
	}
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int o = 0; o < 4; o++)
		{
			int tx = x + dx[o];
			int ty = y + dy[o];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (dis[tx][ty] > dis[x][y] + 1)
			{
				q.emplace(tx, ty);
				dis[tx][ty] = dis[x][y] + 1;
			}
		}
	}
	while (t--)
	{
		int x, y;
		LL s;
		scanf("%d%d%lld", &x, &y, &s);
		s = max(0LL, s - dis[x][y]) & 1;
		putchar(str[x][y] ^ s);
		puts("");
	}
	return 0;
}