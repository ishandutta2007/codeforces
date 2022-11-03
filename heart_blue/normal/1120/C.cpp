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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int maxv[N][N];
int dp[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (str[i] == str[j]) 
				maxv[i][j] = maxv[i - 1][j - 1] + 1;
			else 
				maxv[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + a;
		int cur = 0;
		for (int j = 1; j < i; j++)
		{
			cur = max(cur, maxv[i][j]);
			if (cur >= i - j)
				dp[i] = min(dp[i], dp[j] + b);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}