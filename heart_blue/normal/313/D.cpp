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
const int N = 3e2 + 10;
LL dp[N][N];
LL cost[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	MEM(cost, 0x3f);
	LL inf = dp[0][0];
	LL ans = inf;
	int n, m, k;
	cin >> n >> m >> k;
	dp[0][0] = 0;
	while (m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		cost[l][r] = min(cost[l][r], c * 1LL);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > i; j--)
		{
			cost[i][j - 1] = min(cost[i][j - 1], cost[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		for (int j = 0; j <= i; j++)
		{
			for (int o = i + 1; o <= n; o++)
			{
				dp[o][o - i + j] = min(dp[o][o - i + j], dp[i][j] + cost[i + 1][o]);
			}
		}
	}
	for (int i = k; i <= n; i++) ans = min(ans, dp[n][i]);
	if (ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}