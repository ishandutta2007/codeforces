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
const int N = 5e2 + 10;
int dp[2][N][N];
char str[N];
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		MEM(dp, 0);
		int n, m;
		scanf("%d%d", &n, &m);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str + 1);
			int o = i & 1;
			MEM(sum, 0);
			MEM(dp[o], 0);
			for (int j = 1; j <= m; j++)
			{
				ans += dp[o][j][j] = (str[j] == '*');
				sum[j] = sum[j - 1] + (str[j] == '*');
			}
			for (int j = 1; j <= m; j++)
			{
				for (int k = j + 1; k <= m; k++)
				{
					if (sum[k] - sum[j - 1] != k - j + 1) continue;
					ans += dp[o][j][k] = dp[o ^ 1][j + 1][k - 1];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}