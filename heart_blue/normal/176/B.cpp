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
int dp[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	cin >> s1 >> s2;
	int k;
	cin >> k;
	if (k == 0)
	{
		if (s1 == s2) puts("1");
		else puts("0");
		return 0;
	}
	int n = s1.length();
	MEM(dp, 0);
	dp[0][1] = 1;
	int o = 0;
	for (int i = 1; i <= k; i++)
	{
		o ^= 1;
		MEM(dp[o], 0);
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += dp[o ^ 1][j];
			if (sum >= INF)
				sum -= INF;
		}
		for (int j = 1; j <= n; j++)
		{
			int &tmp = dp[o][j] = sum - dp[o ^ 1][j];
			if (tmp < 0) tmp += INF;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s1.substr(i - 1) + s1.substr(0, i - 1) == s2)
		{
			ans += dp[o][i];
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}