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
int dp[N][2][2];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		if (n == 1)
		{
			puts("0");
			continue;
		}
		MEM(dp[2], 0x3f);
		int o = 0;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (i == j) continue;
				dp[2][i + 'a' != str[1]][j + 'a' != str[2]] =
					(i + 'a' != str[1]) + (j + 'a' != str[2]);
			}
		}
		for (int o = 3; o <= n; o++)
		{
			MEM(dp[o], 0x3f);
			int a[4] = { str[o - 2],str[o - 1],str[o],'0' };
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						if (i == 0 && str[o - 2] == a[k]) continue;
						if (j == 0 && str[o - 1] == a[k]) continue;
						int& tmp = dp[o][j][a[k] != str[o]];
						tmp = min(tmp, dp[o - 1][i][j] + (a[k] != str[o]));
					}
				}
			}
		}
		int ans = INF;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				ans = min(ans, dp[n][i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}