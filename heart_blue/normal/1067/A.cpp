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
const int N = 4e3 + 10;
LL dp[2][210][2];
const int MOD = 998244353;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n == 2)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y)
		{
			if (x == -1) puts("200");
			else puts("1");
		}
		else
		{
			if (x == -1 || y == -1) puts("1");
			else puts("0");
		}
		return 0;
	}
	int x;
	scanf("%d", &x);
	if (x == -1)
	{
		for (int i = 1; i <= 200; i++) dp[0][i][0] = 1;
	}
	else
	{
		dp[0][x][0] = 1;
	}
	int o = 0;
	for (int i = 2; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		o ^= 1;
		MEM(dp[o], 0);
		LL sum = 0;
		for (int j = 1; j <= 200; j++)
		{
			if (x == -1 || x == j)
			{
				dp[o][j][0] += sum;
				if (dp[o][j][0] >= MOD)
				{
					dp[o][j][0] -= MOD;
				}
			}
			sum += dp[o ^ 1][j][0] + dp[o ^ 1][j][1];
			while (sum >= MOD)
				sum -= MOD;
		}
		sum = 0;
		for (int j = 200; j > 0; j--)
		{
			sum += dp[o ^ 1][j][1];
			if (sum >= MOD) sum -= MOD;
			if (x == -1 || x == j)
			{
				dp[o][j][1] += sum + dp[o ^ 1][j][0];
				while (dp[o][j][1] >= MOD)
					dp[o][j][1] -= MOD;
			}
		}
	}
	scanf("%d", &x);
	LL ans = 0;
	LL sum = 0;
	for (int i = 200; i >= 1; i--)
	{
		sum += dp[o][i][1];
		if (x == -1 || x == i)
		{
			ans += sum + dp[o][i][0];
		}
	}
	printf("%lld\n", ans % MOD);
	return 0;
}