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
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int n, m;
char str[N][N];
int dp[N][N][8];
int dfs(int x, int y, int o)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if (str[x][y] == '1') return 0;
	if (dp[x][y][o] != -1) return dp[x][y][o];
	return dp[x][y][o] = dfs(x + dx[o], y + dy[o], o) + 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int o = 0; o < 8; o++)
			{
				int t = (o + 3) % 8;
				int minv = min(dfs(i, j, o), dfs(i, j, (o + 2) % 8));
				for (int k = 1; k < minv; k++)
				{
					int x = i + dx[o] * k;
					int y = j + dy[o] * k;
					if (dfs(x, y, t) >= (o % 2 == 0 ? k + 1 : 2 * k + 1))
						ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}