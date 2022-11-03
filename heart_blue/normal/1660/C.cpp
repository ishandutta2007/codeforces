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
const int N = 2e2 + 10;
const int M = 2e5 + 10;
int dp[N][2];
char str[M];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		MEM(dp, 0xaf);
		for (int i = 1; i <= n; i++)
		{
			char c = str[i];
			int ans0 = max(0, dp[c][1] + 1);
			int ans1 = 1;
			for (char o = 'a'; o <= 'z'; o++)
			{
				ans1 = max(ans1, dp[o][0] + 1);
			}
			dp[c][0] = max(dp[c][0], ans0);
			dp[c][1] = max(dp[c][1], ans1);
		}
		int res = 0;
		for (char c = 'a'; c <= 'z'; c++)
			res = max(res, dp[c][0]);
		printf("%d\n", n - res);

	}
	return 0;
}