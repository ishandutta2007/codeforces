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
const int N = 5e3 + 10;
int flag[N][N];
int dp[N][N];
char str[N];
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	MEM(flag, 0);
	for (int i = 1; i <= n; i++) flag[i][i] = 1;
	for (int i = 1; i < n; i++)
	{
		if (str[i] == str[i + 1]) flag[i][i + 1] = 1;
	}
	for (int d = 2; d <= n; d++)
	{
		for (int i = 1; i + d <= n; i++)
		{
			if (str[i] == str[i + d] && flag[i + 1][i + d - 1])
				flag[i][i + d] = 1;
		}
	}
	memcpy(dp, flag, sizeof(dp));
	for (int o = 1; o <= 20; o++)
	{
		int f = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				int len = j - i - 1;
				if (dp[i][j] && dp[i][i + len / 2] >= o && dp[j - len / 2][j] >= o)
				{
					dp[i][j] = o + 1;
					f = 1;
				}
			}
		}
		if (f == 0) break;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			ans[dp[i][j]]++;
		}
	}
	for (int i = n; i > 0; i--)
	{
		ans[i - 1] += ans[i];
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}