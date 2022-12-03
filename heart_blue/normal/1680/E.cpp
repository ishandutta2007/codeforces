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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int dp1[N][4];
int dp2[N][4];
char str[2][N];
int getmask(int pos)
{
	int o0 = str[0][pos] == '*';
	int o1 = str[1][pos] == '*';
	int o = o1 << 1 | o0;
	return o;
}
void build(int dp[4])
{
	dp[1] = min(dp[1], dp[3] + 1);
	dp[2] = min(dp[2], dp[3] + 1);
	dp[1] = min(dp[1], dp[2] + 1);
	dp[2] = min(dp[2], dp[1] + 1);
}
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
		scanf("%s%s", str[0] + 1, str[1] + 1);
		MEM(dp1[1], 0x3f);
		dp1[1][getmask(1)] = 0;
		for (int i = 1; i <= n; i++)
		{
			int key[4];
			memcpy(key, dp1[i], sizeof(key));
			build(key);
			int o = getmask(i + 1);
			MEM(dp1[i + 1], 0x3f);
			for (int k = 0; k < 4; k++)
			{
				int cnt = 0;
				if (k >= 3) cnt = 2;
				else if (k >= 1) cnt = 1;
				dp1[i + 1][o | k] = min(dp1[i + 1][o | k], key[k] + cnt);
			}
		}
		MEM(dp2[n], 0x3f);
		dp2[n][getmask(n)] = 0;
		for (int i = n; i >= 1; i--)
		{
			int key[4];
			memcpy(key, dp2[i], sizeof(key));
			build(key);
			int o = getmask(i - 1);
			MEM(dp2[i - 1], 0x3f);
			for (int k = 0; k < 4; k++)
			{
				int cnt = 0;
				if (k >= 3) cnt = 2;
				else if (k >= 1) cnt = 1;
				dp2[i - 1][o | k] = min(dp2[i - 1][o | k], dp2[i][k] + cnt);
			}
		}
		int ans = INF;
		for (int i = 1; i <= n; i++)
		{
			int key[4];
			MEM(key, 0x3f);
			for (int o1 = 0; o1 < 4; o1++)
			{
				for (int o2 = 0; o2 < 4; o2++)
				{
					key[o1 | o2] = min(key[o1 | o2], dp1[i][o1] + dp2[i][o2]);
				}
			}
			build(key);
			ans = min({ ans,key[1],key[2] });
		}
		printf("%d\n", ans);
	}
	return 0;
}