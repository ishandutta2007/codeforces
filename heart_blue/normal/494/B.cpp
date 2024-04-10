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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
char s1[N], s2[N];
int fail[N];
int dp[N];
int sum[N];
void getfail(char *str, int n)
{
	int j = 0;
	fail[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		while (j > 0 && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) j++;
		fail[i] = j;
	}
}
LL getans(int n, int m)
{
	int j = 0;
	int pre = 0;
	dp[0] = 0;
	LL ans = 0;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		while (j > 0 && s2[j + 1] != s1[i]) j = fail[j];
		if (s2[j + 1] == s1[i]) j++;
		if (j == m)
		{
			pre = i - m + 1;
			j = fail[j];
		}
		if (pre != 0)
		{
			dp[i] = sum[pre - 1] + pre;
			ans += dp[i];
			if (ans >= INF) ans -= INF;
		}
		dp[i] += dp[i - 1];
		if (dp[i] >= INF) dp[i] -= INF;
		sum[i] = dp[i] + sum[i - 1];
		if (sum[i] >= INF) sum[i] -= INF;

	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s%s", s1 + 1, s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	getfail(s2, m);
	printf("%lld\n", getans(n, m));
	return 0;
}