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
const int N = 1e2 + 10;
int dp[N][N][2][2];
int dfs(int x, int y, int o1, int o2)
{
	if (dp[x][y][o1][o2] != -1)
		return dp[x][y][o1][o2];
	dp[x][y][o1][o2] = 0;
	int ret1 = 1, ret2 = 1;
	if (x > 0)
		ret1 = dfs(x - 1, y, o2, o1 ^ 1);
	if (y > 0)
		ret2 = dfs(x, y - 1, o2, o1);
	if (ret1 == 0 || ret2 == 0)
		dp[x][y][o1][o2] = 1;
	return dp[x][y][o1][o2];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		MEM(dp, -1);
		int cnt0 = 0, cnt1 = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (abs(x) & 1) cnt1++, sum ^= 1;
			else cnt0++;
		}
		if (n % 2 == 0)
		{
			MEM(dp[0][0], 0);
			dp[0][0][0][sum] = 1;
		}
		else
		{
			MEM(dp[0][0], 0);
			dp[0][0][sum ^ 1][1] = 1;
		}
		if (dfs(cnt1, cnt0, 0, 0)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}