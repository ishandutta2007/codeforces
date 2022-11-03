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
const int N = 5e2 + 10;
char str[N][N];
char tmp[N][N];
int sum[N][N];
int flag[N][N][11];
int n, m;
int getsum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
int dfs(int x, int y, int o, int t, int key = 0)
{
	int len = 1 << o;
	if (x + len - 1 > n || y + len - 1 > m) return 0;
	if (key == 1)
	{
		return getsum(x, y, x + len - 1, y + len - 1) == len * len ? 1 : 0;
	}
	if (o == 0)
		return str[x][y] == '.' ? 1 : 0;
	if (flag[x][y][o] != -1)
		return flag[x][y][o];
	len /= 2;
	return flag[x][y][o] = dfs(x, y, o - 1, t, t >> 0 & 1) &
		dfs(x + len, y, o - 1, t, t >> 1 & 1) &
		dfs(x, y + len, o - 1, t, t >> 2 & 1) &
		dfs(x + len, y + len, o - 1, t, t >> 3 & 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (str[i][j] == '*')
				sum[i][j]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (str[i][j] == '*')
				sum[i][j]++;
		}
	}
	int ans = 0;
	int cnt = 4;
	for (int t = 0; t < 16; t++)
	{
		MEM(flag, -1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int o = 2; o < 11; o++)
				{
					ans += dfs(i, j, o, t);
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}