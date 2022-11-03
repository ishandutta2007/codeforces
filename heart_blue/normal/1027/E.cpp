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
const int N = 5e2 + 10;
const LL MOD = 998244353;
int dp[N][N][2];
int dfs(int x, int y, int o)
{
	if (dp[x][y][o] != -1) return dp[x][y][o];
	if (x == 0) return o;
	int &ret = dp[x][y][o] = 0;
	for (int i = 1; i <= min(x, y); i++)
	{
		ret += dfs(x - i, y, o | (y == i));
		if (ret >= MOD) ret -= MOD;
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	MEM(dp, -1);
	for (int i = 1; i <= n; i++) dfs(n, i, 0);
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i*j >= k) break;
			ans += 1LL*dp[n][i][0] * dp[n][j][0] * 2 % MOD;
		}
	}
	cout << ans % MOD << '\n';
	return 0;
}