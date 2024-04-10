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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][N][12][2];
char s1[N], s2[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s%s", s1 + 1, s2 + 1);
	MEM(dp, 0);
	s1[0] = s2[0] = 'a';
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int t = 0; t <= k; t++)
			{
				int tmp1 = max(dp[i - 1][j - 1][t][0], dp[i - 1][j - 1][t][1]);
				int tmp2 = max(dp[i][j - 1][t][0], dp[i - 1][j][t][0]);
				int tmp3 = max(dp[i][j - 1][t][1], dp[i - 1][j][t][1]);
				dp[i][j][t][0] = max(tmp1, max(tmp2, tmp3));
			}
			if (s1[i] != s2[j]) continue;
			for (int t = 1; t <= k; t++)
			{
				dp[i][j][t][1] = max(dp[i - 1][j - 1][t - 1][0] + 1, dp[i - 1][j - 1][t - 1][1] + 1);
				if (s1[i - 1] == s2[j - 1]) dp[i][j][t][1] = max(dp[i][j][t][1], dp[i - 1][j - 1][t][1] + 1);
			}
		}
	}
	cout << max(dp[n][m][k][0], dp[n][m][k][1]) << endl;
	return 0;
}