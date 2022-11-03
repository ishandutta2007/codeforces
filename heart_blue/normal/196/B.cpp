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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
pair<int,int> dp[N][N];
char c[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0xef);
	int inf = dp[0][0].first;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", c[i]);
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (c[i][j] == 'S')
			{
				sx = i, sy = j;
			}
		}
	}
	queue<pair<int, int>> q;
	dp[sx][sy] = { sx,sy };
	q.push({ sx,sy });
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ox = x + dx[i];
			int oy = y + dy[i];
			int rx = (ox%n + n) % n;
			int ry = (oy%m + m) % m;
			if (c[rx][ry] == '#') continue;
			if (dp[rx][ry].first == inf)
			{
				dp[rx][ry] = { ox,oy };
				q.push({ ox,oy });
			}
			else
			{
				if (dp[rx][ry] == make_pair(ox, oy)) continue;
				else
				{
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}