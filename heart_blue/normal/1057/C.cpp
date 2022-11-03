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
const int N = 51;
int dp[N][N * N];
int a[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s, k;
	scanf("%d%d%d", &n, &s, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%s", str + 1);
	MEM(dp, 0x3f);
	int inf = dp[0][0];
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][a[i]] = abs(i - s);
	}
	for (int o = 1; o < N; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != o) continue;
			for (int j = 1; j <= n; j++)
			{
				if (str[j] == str[i]) continue;
				if (a[j] <= a[i]) continue;
				for (int t = 0; t <= k; t++)
				{
					if (dp[i][t] == inf) continue;
					int &tmp = dp[j][t + a[j]];
					tmp = min(tmp, dp[i][t] + abs(i - j));
				}
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; i++)
	{
		for (int j = k; j < N * N; j++)
		{
			if (dp[i][j] != inf)
				ans = min(ans, dp[i][j]);
		}
	}
	if (ans == inf)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}