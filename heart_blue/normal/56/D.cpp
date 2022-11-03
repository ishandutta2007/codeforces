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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][N];
pair<int, int> pre[N][N];
char s1[N];
char s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	for (int i = 1; i <= m; i++)
	{
		dp[0][i] = i;
		pre[0][i] = { 0,i - 1 };
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = i;
		pre[i][0] = { i - 1,0 };
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = INF;
			if (dp[i][j] > dp[i - 1][j] + 1)
			{
				dp[i][j] = dp[i - 1][j] + 1;
				pre[i][j] = { i - 1,j };
			}
			if (dp[i][j] > dp[i][j - 1] + 1)
			{
				dp[i][j] = dp[i][j - 1] + 1;
				pre[i][j] = { i,j - 1 };
			}
			int o = s1[i] == s2[j] ? 0 : 1;
			if (dp[i][j] > dp[i - 1][j - 1] + o)
			{
				dp[i][j] = dp[i - 1][j - 1] + o;
				pre[i][j] = { i - 1,j - 1 };
			}
		}
	}
	printf("%d\n", dp[n][m]);
	int x = n, y = m;
	while (x > 0 || y > 0)
	{
		auto [px, py] = pre[x][y];
		if (x == px)
		{
			printf("INSERT %d %c\n", x + 1, s2[py + 1]);
		}
		else if (y == py)
		{
			printf("DELETE %d\n", x);
		}
		else
		{
			if (dp[x][y] != dp[px][py])
				printf("REPLACE %d %c\n", x, s2[y]);
		}
		x = px;
		y = py;
	}
	return 0;
}