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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int dp[N][N];
int last[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	int inf = dp[0][0];
	dp[0][0] = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
		dp[i][1] = sum[i];
		for (int j = 2; j <= i; j++)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + x);
		}
		for (int j = 0; j < i; j++)
		{
			for (int k = last[j]; k >= 0; k--)
			{
				if (sum[i] - sum[j] >= dp[j][k])
				{
					dp[i][k + 1] = min(dp[i][k + 1], sum[i] - sum[j]);
				}
				else break;
				last[j] = k;
			}
		}
		for (int j = 1; j <= i; j++)
		{
			if (dp[i][j] < inf)
				last[i] = j;
		}
	}
	int ans = n;
	for (int i = n; i >= 1; i--)
	{
		if (dp[n][i] < inf)
		{
			ans = i;
			break;
		}
	}
	printf("%d\n", n - ans);
	return 0;
}