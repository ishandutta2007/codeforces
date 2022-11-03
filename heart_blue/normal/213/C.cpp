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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
int dp[N * 2][N][N];
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	MEM(dp, 0xef);
	dp[2][1][1] = 0;
	for (int i = 2; i <= n * 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j < 1) continue;
			if (i - j > n) continue;
			for (int k = 1; k <= n; k++)
			{
				if (i - k < 1) continue;
				if (i - k > n) continue;
				if (j == k) dp[i][j][k] += a[j][i - j];
				else dp[i][j][k] += a[j][i - j] + a[k][i - k];
				for (int o1 = 0; o1 < 2; o1++)
				{
					for (int o2 = 0; o2 < 2; o2++)
					{
						int& tmp = dp[i + 1][j + o1][k + o2];
						tmp = max(tmp, dp[i][j][k]);
					}
				}
			}
		}
	}
	printf("%d\n", dp[2 * n][n][n]);
	return 0;
}