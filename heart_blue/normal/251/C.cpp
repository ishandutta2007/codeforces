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
const int N = 2e3 + 10;
const int mod = 13 * 11 * 9 * 8 * 7 * 5;
int dp[mod + 1];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL a, b;
	int k;
	scanf("%lld%lld%d", &a, &b, &k);
	int lcm = 1;
	for (int i = 1; i <= k; i++)
	{
		lcm = i / gcd(i, lcm) * lcm;
	}
	for (int i = 1; i <= lcm; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j <= k; j++)
		{
			dp[i] = min(dp[i], dp[i - i % j] + 1);
		}
	}
	LL ans = 0;
	LL c = (b + lcm - 1) / lcm * lcm;
	if (a >= c)
	{
		ans += dp[a % lcm] + (a - c) / lcm * dp[lcm];
		a = c;
	}
	a %= lcm;
	b %= lcm;
	if (a < b) a = lcm;
	MEM(dp, 0x3f);
	dp[b] = 0;
	for (int i = b + 1; i <= a; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; j <= k; j++)
		{
			dp[i] = min(dp[i], dp[i - i % j] + 1);
		}
	}
	printf("%lld\n", dp[a] + ans);
	return 0;
}