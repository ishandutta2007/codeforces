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
const int N = 1e3 + 10;
int n;
char str[N];
int len[N];
int dp[N];
int solve1()
{
	MEM(dp, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int o = len[str[i]];
		for (int j = i; j > 0 && i - j + 1 <= o; o = min(o,len[str[--j]]))
		{
			char c = str[j];
			dp[i] += dp[j - 1];
			if (dp[i] >= INF) dp[i] -= INF;
		}
	}
	return dp[n];
}
int solve2()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int o = len[str[i]];
		int cnt = 0;
		for (int j = i; j <= n && j - i + 1 <= o; o = min(o, len[str[++j]]))
		{
			char c = str[j];
			cnt++;
		}
		ans = max(ans, cnt);
	}
	return ans;
}
int solve3()
{
	MEM(dp, 0x3f);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int o = len[str[i]];
		for (int j = i; j > 0 && i - j + 1 <= o; o = min(o, len[str[--j]]))
		{
			char c = str[j];
			dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}
	return dp[n];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	scanf("%s", &str[1]);
	for (int i = 'a'; i <= 'z'; i++) scanf("%d", &len[i]);
	cout << solve1() << endl;
	cout << solve2() << endl;
	cout << solve3() << endl;
	return 0;
}