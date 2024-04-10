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
const int N = 2e2 + 10;
int dp[N][N * 25];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	MEM(dp, 0);
	int tot = n * 25;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		LL x;
		cin >> x;
		int cnt5 = 0, cnt2 = 0;
		while (x % 5 == 0) cnt5++, x /= 5;
		while (x % 2 == 0) cnt2++, x /= 2;

		for (int j = min(i, k); j > 0; j--)
		{
			for (int t = tot; t >= cnt5; t--)
			{
				if (dp[j - 1][t - cnt5])
					dp[j][t] = max(dp[j][t], dp[j - 1][t - cnt5] + cnt2);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= tot; i++)
	{
		ans = max(ans, min(i, dp[k][i] - 1));
	}
	cout << ans << endl;
	return 0;
}