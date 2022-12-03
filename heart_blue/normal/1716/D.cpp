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
const int N = 2e5 + 10;
const int mod = 998244353;
int dp[N];
int sum[N];
LL ans[N];
void add(int& x, int y)
{
	x += y;
	if (x >= mod) x -= mod;
}
void sub(int& x, int y)
{
	x -= y;
	if (x < 0) x += mod;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0] = 1;
	int n, k;
	scanf("%d%d", &n, &k);
	while (count(dp, dp + N, 0) != N)
	{
		for (int i = 0; i <= n; i++)
		{
			add(sum[i % k], dp[i]);
		}
		for (int i = n; i >= 0; i--)
		{
			sub(sum[i % k], dp[i]);
			dp[i] = sum[i % k];
			ans[i] += dp[i];
		}
		dp[n] = 0;
		k++;
	}
	for (int i = 1; i <= n; i++)
		printf("%lld%c", ans[i] % mod, " \n"[i == n]);
	return 0;
}