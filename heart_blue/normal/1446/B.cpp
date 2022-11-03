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
const int N = 5e3 + 10;
char s1[N], s2[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s", s1 + 1, s2 + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = max(2, dp[i - 1][j - 1] + 2);
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1] - 1, dp[i - 1][j] - 1);
				dp[i][j] = max(0, dp[i][j]);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}