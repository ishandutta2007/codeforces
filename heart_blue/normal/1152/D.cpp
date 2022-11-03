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
const int N = 2e3 + 10;
int dp[N][N];
int flag[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	flag[0][0] = 1;
	for (int i = 1; i <= 2 * n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int o = 0;
			if (j > 0)
			{
				dp[i][j] += dp[i - 1][j - 1];
				o |= flag[i - 1][j - 1];
			}
			if (j < i)
			{
				dp[i][j] += dp[i - 1][j + 1];
				o |= flag[i - 1][j + 1];
			}
			if (o)
				dp[i][j]++;
			else
				flag[i][j] = 1;
			if (dp[i][j] >= INF)
				dp[i][j] -= INF;
		}
	}
	printf("%d\n", dp[2 * n][0]);
	return 0;

}