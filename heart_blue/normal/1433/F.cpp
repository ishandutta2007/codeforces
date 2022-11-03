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
const int N = 70 + 10;
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	MEM(dp, 0xdf);
	dp[0][0] = 0;
	while (n--)
	{
		for (int i = 1; i <= m; i++)
		{
			MEM(dp[i], 0xdf);
		}
		int maxv = (m / 2);
		for (int i = 1; i <= m; i++)
		{
			int x;
			scanf("%d", &x);
			for (int j = maxv; j > 0; j--)
			{
				for (int r = 0; r < k; r++)
				{
					dp[j][(r + x) % k] = max(dp[j][(r + x) % k], dp[j - 1][r] + x);
				}
			}
		}
		for (int i = 1; i <= maxv; i++)
		{
			for (int j = 0; j < k; j++)
				dp[0][j] = max(dp[0][j], dp[i][j]);
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}