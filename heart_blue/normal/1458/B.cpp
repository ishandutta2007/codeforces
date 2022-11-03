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
const int N = 1e2 + 10;
int dp[N][N * N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	MEM(dp, -1);
	dp[0][0] = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		tot += a;
		for (int j = i; j >= 0; j--)
		{
			for (int k = 0; k <= tot; k++)
			{
				if (dp[j][k] != -1)
				{
					dp[j + 1][k + a] = max(dp[j + 1][k + a], dp[j][k] + b * 2);
					dp[j][k] += b;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 0; j <= tot; j++)
		{
			if (dp[i][j] == -1) continue;
			ans = max(ans, min(dp[i][j], j * 2));
		}
		printf("%.2f ", ans / 2.0);
	}
	return 0;
}