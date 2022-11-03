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
int dp[N][N][2];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int j = i + len;
			dp[i][j][0] = min({
				//dp[i][j - 1][0] + (a[i] != a[j]),
				dp[i + 1][j][0] + (a[i] != a[i + 1]),
				dp[i + 1][j][1] + (a[i] != a[j])
				});
			dp[i][j][1] = min({
				dp[i][j - 1][0] + (a[i] != a[j]),
				dp[i][j - 1][1] + (a[j - 1] != a[j]),
				//dp[i + 1][j][1] + (a[i] != a[j])
				});
		}
	}
	printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
	return 0;
}