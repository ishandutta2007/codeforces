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
const int N = 2e5 + 10;
char str[N];
int a[N];
int dp[N][2][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		a[n + 1] = a[n + 2] = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			MEM(dp[i], 0);
			for (int o1 = 0; o1 < 2; o1++)
			{
				for (int o2 = 0; o2 < 2; o2++)
				{
					dp[i][o2][0] = max(dp[i][o2][0], dp[i - 1][o1][o2]);
					if (str[i] != '1') continue;
					if (o1 == 0) dp[i][o2][0] = max(dp[i][o2][0], dp[i - 1][o1][o2] + a[i - 1]);
					if (o2 == 0) dp[i][1][0] = max(dp[i][1][0], dp[i - 1][o1][o2] + a[i]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				ans = max(ans, dp[n + 1][i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}