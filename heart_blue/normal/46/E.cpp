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
const int N = 2e3 + 10;
int a[N][N];
LL dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = a[i][j] + dp[i][j - 1];
		}
		if (i > 1)
		{
			if (i & 1)
			{
				for (int j = 2; j <= m; j++)
				{
					dp[i][j] += dp[i - 1][j - 1];
				}
				dp[i][1] = -INF * INF;
			}
			else
			{
				for (int j = 1; j < m; j++)
				{
					dp[i][j] += dp[i - 1][j + 1];
				}
				dp[i][m] = -INF * INF;
			}
		}
		if (i & 1)
		{
			for (int j = m; j > 1; j--)
			{
				dp[i][j - 1] = max(dp[i][j - 1], dp[i][j]);
			}
		}
		else
		{
			for (int j = 1; j < m; j++)
			{
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
			}
		}
	}
	LL ans = -INF*INF;
	for (int i = 1; i <= m; i++)
		ans = max(ans, dp[n][i]);
	printf("%lld\n", ans);
	return 0;
}