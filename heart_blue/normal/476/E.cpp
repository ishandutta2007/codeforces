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
const int N = 2e3 + 10;
int pre[N];
char s1[N], s2[N];
int dp[N][N];
int n, m;
int check(int p1)
{
	int p2 = m;
	while (p1 > 0 && p2 > 0)
	{
		while (p1 > 0 && s1[p1] != s2[p2]) p1--;
		if (p2 == 1) break;
		p2--, p1--;
	}
	return p1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	n = strlen(s1 + 1);
	m = strlen(s2 + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s1[i] == s2[m])
			pre[i] = check(i);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
		if (pre[i])
		{
			int d = i - pre[i] + 1 - m;
			for (int j = d; j <= i - m; j++)
			{
				dp[i][j] = max(dp[i][j], dp[pre[i] - 1][j - d] + 1);
			}
		}
	}
	for (int i = 0; i <= n; i++) printf("%d ", dp[n][i]);
	return 0;
}