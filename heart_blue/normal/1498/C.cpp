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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
LL dp[N][N];
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
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i - 1][n - j + 2] - dp[i - 1][1] + 1 + dp[i][j - 1];
				dp[i][j] %= INF;
				if (dp[i][j] < 0) dp[i][j] += INF;
			}
			dp[i][n + 1] = dp[i][n] + 1;
		}
		printf("%lld\n", dp[k][1]);
	}
	return 0;
}