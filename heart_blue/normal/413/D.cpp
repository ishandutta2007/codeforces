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
const int N = 2e3 + 100;
int dp[N][N];
int rsum[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	k = 1 << k;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	rsum[n + 1] = 1;
	for (int i = n; i >= 1; i--)
	{
		rsum[i] = rsum[i + 1];
		if (a[i] == 0) rsum[i] = rsum[i] * 2 % INF;
	}
	dp[0][0] = 1;
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (dp[i - 1][j] == 0) continue;
			for (int t = 2; t <= 4; t *= 2)
			{
				if (a[i] == t || a[i] == 0)
				{
					int o = j + t;
					if (j % 4 == 2 && t == 4) o = 4;
					if (o >= k) ans += 1LL * dp[i - 1][j] * rsum[i + 1] % INF;
					else
					{
						int& tmp = dp[i][o] += dp[i - 1][j];
						if (tmp >= INF) tmp -= INF;
					}
				}
			}
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}