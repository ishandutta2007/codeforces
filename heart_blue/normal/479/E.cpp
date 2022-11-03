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
const int N = 5e3 + 10;
int pos[N];
int dp[2][N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	for (int i = 1; i < b; i++)
	{
		pos[i] = (i + b - 1) / 2;
	}
	for (int i = b + 1; i <= n; i++)
	{
		pos[i] = (i + b) / 2 + 1;
	}
	MEM(dp, 0);
	int o = 0;
	dp[o][a] = 1;
	sum[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum[j] = sum[j - 1] + dp[o][j];
			if (sum[j] >= INF) sum[j] -= INF;
		}
		o ^= 1;
		MEM(dp[o], 0);
		for (int j = 1; j < b; j++)
		{
			dp[o][j] = sum[pos[j]] - dp[o ^ 1][j];
			dp[o][j] %= INF;
			if (dp[o][j] < 0) dp[o][j] += INF;
		}
		for (int j = b + 1; j <= n; j++)
		{
			dp[o][j] = sum[n] - sum[pos[j] - 1] - dp[o ^ 1][j];
			dp[o][j] %= INF;
			if (dp[o][j] < 0) dp[o][j] += INF;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dp[o][i];
		if (ans >= INF) ans -= INF;
	}
	cout << ans << endl;
	return 0;
}