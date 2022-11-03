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
const int N = 2e2 + 10;
LL dp[2][N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0);
	int n, k, d;
	cin >> n >> k >> d;
	for (int i = 1; i <= k; i++)
	{
		if (i < d) dp[0][i][0] = 1;
		else dp[0][i][1] = 1;
	}
	LL ans = dp[0][n][1];
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		o ^= 1;
		MEM(dp[o], 0);
		for (int s = 1; s <= n; s++)
		{
			for (int j = 1; j <= k; j++)
			{
				if (j > s) break;
				if (j >= d)
				{
					dp[o][s][1] += dp[o ^ 1][s - j][1] + dp[o ^ 1][s - j][0];
				}
				else
				{
					dp[o][s][1] += dp[o ^ 1][s - j][1];
					dp[o][s][0] += dp[o ^ 1][s - j][0];
				}
				dp[o][s][1] %= INF;
				dp[o][s][0] %= INF;
			}
		}
		ans += dp[o][n][1];
		if (ans >= INF) ans -= INF;
	}
	cout << ans << endl;
	return 0;
}