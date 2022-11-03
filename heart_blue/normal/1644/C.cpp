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
const int N = 5e3 + 10;
int dp[N][N];
int maxv[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x;
		scanf("%d%d", &n, &x);
		fill(dp[0], dp[0] + n + 1, -(int)INF);
		fill(maxv, maxv + n + 1, -(int)INF);
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			for (int j = 0; j <= i; j++)
			{
				dp[i][j] = max(a, dp[i - 1][j] + a);
				if (j > 0)
					dp[i][j] = max(a + x, dp[i - 1][j - 1] + a + x);
				maxv[j] = max(maxv[j], dp[i][j]);
			}
		}
		maxv[0] = max(0, maxv[0]);
		for (int i = 1; i <= n; i++)
			maxv[i] = max(maxv[i], maxv[i - 1]);
		for (int i = 0; i <= n; i++)
			printf("%d%c", maxv[i], " \n"[i == n]);

	}
	return 0;
}