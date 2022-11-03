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
const int N = 3e5 + 10;
LL dp[N][2];
LL x[N][2];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL n, k;
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i][0]);
	for (int i = 1; i <= n; i++) scanf("%lld", &x[i][1]);
	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i][1] = INF;
		// 0 0 0
		// 1 1 1
		for (int o = 0; o < 2; o++)
		{
			if (dp[i - 1][o] <= k)
			{
				int tot = x[i][o] + dp[i - 1][o];
				int maxpos = x[i][o]; // check
				int lowpos = tot / k; // check
				if (tot%k == 0) lowpos--; // check
				if (maxpos * k >= x[i][o ^ 1] && x[i][o ^ 1] >= lowpos)
				{
					if (x[i][o ^ 1] == lowpos)
					{
						dp[i][o] = min(dp[i][o], tot % k == 0 ? k : tot % k);
					}
					else
					{
						dp[i][o] = 1;
					}
				}
			}
		}
		// 0 0 1
		// 1 1 0;
		for (int o = 0; o < 2; o++)
		{
			if (dp[i - 1][o] > k) continue;
			int tot = dp[i - 1][o] + x[i][o];
			int maxpos = x[i][o] + 1; // check
			int lowpos = tot / k; // check
			if (tot%k) lowpos++;
			if (maxpos * k >= x[i][o ^ 1] && x[i][o ^ 1] >= lowpos)
			{
				dp[i][o ^ 1] = min(dp[i][o ^ 1], max(1LL, x[i][o ^ 1] / maxpos));
			}
		}
		// 0 1 0
		// 1 0 1
		for (int o = 0; o < 2; o++)
		{
			if (dp[i - 1][o] > k) continue;
			int tot = x[i][o ^ 1];
			int maxpos = tot; // check
			int lowpos = tot / k;
			if (tot%k) lowpos++;
			if (maxpos * k >= x[i][o] && x[i][o] >= lowpos)
			{
				dp[i][o] = min(dp[i][o], max(1LL, x[i][o] / maxpos));
			}
		}
		// 0 1 1
		// 1 0 0
		for (int o = 0; o < 2; o++)
		{
			if (dp[i - 1][o] > k) continue;
			if (x[i][o ^ 1] == 1) continue;
			int tot = x[i][o ^ 1];
			int maxpos = tot - 1;
			int lowpos = tot / k;
			if (tot%k == 0) lowpos--;
			if (maxpos * k >= x[i][o] && x[i][o] >= lowpos)
			{
				if (x[i][o] == lowpos)
				{
					dp[i][o ^ 1] = min(dp[i][o ^ 1], tot % k == 0 ? k : tot % k);
				}
				else
				{
					dp[i][o ^ 1] = 1;
				}
			}
		}
		if (dp[i][0] == INF && dp[i][1] == INF)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}