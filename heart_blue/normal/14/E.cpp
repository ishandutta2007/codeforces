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
const int N = 2e1 + 10;
LL dp[N][N][N][5][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (i == j) continue;
			dp[2][0][0][j][i < j]++;
		}
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				for (int x = 1; x <= 4; x++)
				{
					for (int o = 0; o < 2; o++)
					{
						if (dp[i][j][k][x][o] == 0) continue;
						LL tmp = dp[i][j][k][x][o];
						for (int y = 1; y <= 4; y++)
						{
							if (x == y) continue;
							if (o == 1)
							{
								if (x < y) dp[i + 1][j][k][y][1] += tmp;
								else dp[i + 1][j + 1][k][y][0] += tmp;
							}
							else
							{
								if (x > y) dp[i + 1][j][k][y][0] += tmp;
								else dp[i + 1][j][k + 1][y][1] += tmp;
							}
						}
					}
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			ans += dp[n][t][t - 1][i][o];
		}
	}
	printf("%lld\n", ans);
	return 0;
}