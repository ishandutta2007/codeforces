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
const int N = 1e2 + 10;
int dp[N][N * N];
int cnt[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	dp[0][0] = 1;
	int sum = 0;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i < N; i++)
	{
		if (cnt[i] == 0) continue;
		for (int j = tot + cnt[i]; j > 0; j--)
		{
			for (int k = min(j - 1, tot); k >= 0; k--)
			{
				if (j - k > cnt[i]) break;
				int x = (j - k) * i;
				for (int t = sum + x; t >= x; t--)
					dp[j][t] = min(2, dp[j][t] + dp[k][t - x]);
			}
		}
		tot += cnt[i];
		sum += cnt[i] * i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j * i <= sum; j++)
		{
			if (cnt[j] >= i && dp[i][j * i] == 1)
			{
				ans = max(ans, i);
				int restsum = sum - i * j;
				int restcnt = n - i;
				if (restsum > 0 &&
					restsum % restcnt == 0 &&
					dp[restcnt][restsum] == 1 &&
					cnt[restsum / restcnt] >= restcnt)
				{
					ans = max(ans, i + restcnt);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}