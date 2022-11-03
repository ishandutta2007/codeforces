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
const int N = 2e2 + 10;
int dp[N][N * N][2];
int v[N];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	int inf = dp[0][0][0];
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	if (v[1] <= a) dp[1][v[1]][0] = 0;
	if (v[1] <= b) dp[1][0][1] = 0;
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += v[i];
		for (int j = 0; j <= sum; j++)
		{
			for (int o = 0; o < 2; o++)
			{
				if (dp[i][j][o] == inf) continue;
				int resta = a - j;
				int restb = b - (sum - j);
				if (resta >= v[i + 1])
					dp[i + 1][j + v[i + 1]][0] = min(dp[i + 1][j + v[i + 1]][0], dp[i][j][o] + o * min(v[i], v[i + 1]));
				if (restb >= v[i + 1])
					dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][o] + (o ^ 1) * min(v[i], v[i + 1]));
			}
		}
	}
	sum += v[n];
	int ans = inf;
	for (int i = 0; i <= sum; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			ans = min(ans, dp[n][i][o]);
		}
	}
	if (ans == inf) ans = -1;
	printf("%d\n", ans);
	return 0;
}