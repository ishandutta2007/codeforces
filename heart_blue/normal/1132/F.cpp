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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
int dp[N][N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	MEM(dp, 0x3f);
	scanf("%d", &n);
	scanf("%s", str + 1);
	//n = unique(str + 1, str + n + 1) - str;
	MEM(dp, 0);
	for (int i = 1; i <= n; i++) dp[i][i] = 1;
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int l = i;
			int r = i + len;
			dp[l][r] = INF;
			if (str[l] == str[r])
				dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]);

			for (int k = l; k < r; k++)
			{
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;
}