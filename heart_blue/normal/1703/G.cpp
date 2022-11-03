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
const int N = 2e5 + 10;
LL dp[N][40];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		LL ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			MEM(dp[i], 0);
			for (int j = 0; j <= 30; j++)
			{
				dp[i][j] = dp[i - 1][j] - k + (x >> j);
				if (j > 0)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (x >> j));
				}
				ans = max(ans, dp[i][j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}