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
const int N = 1e6 + 10;
char str[N];
int dp[N][2];
int pre[N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x3f);
	dp[0][0] = 0;
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			dp[i][o] = dp[i - 1][o] + (str[i] - '0' != o);
			pre[i][o] = o;
		}
		for (int o = 0; o < 2; o++)
		{
			if (o != str[i] - '0' && dp[i][o ^ 1] > dp[i - 1][o] + 1)
			{
				dp[i][o ^ 1] = dp[i - 1][o] + 1;
				pre[i][o ^ 1] = o;
			}
		}
	}
	vector<pair<int, int>> ans;
	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '1')
			m = i;
	}
	int cur = 1;
	int o = (str[m] - '0') ^ 1;
	if (dp[m][o ^ 1] + 1 < dp[m][o]) o ^= 1, ans.emplace_back(n - m, 1);
	for (int i = m; i >= 1; i--)
	{
		int k = pre[i][o];
		if (dp[i][o] - dp[i - 1][k] == 1)
		{
			if (o != k)
			{
				if (!ans.empty()) ans.back().second *= -1;
				ans.emplace_back(n - i + 1, 1);
			}
			else
			{
				ans.emplace_back(n - i, 1);
			}
		}
		o = k;
	}
	reverse(ans.begin(), ans.end());
	int t = 1;
	for (auto& [x, o] : ans)
	{
		t *= o;
		o = t;
	}
	printf("%d\n", ans.size());
	for (auto& [x, o] : ans)
	{
		printf("%c2^%d\n", "+-"[o == -1], x);
	}
	return 0;
}