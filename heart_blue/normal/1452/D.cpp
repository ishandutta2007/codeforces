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
const int N = 2e5 + 10;
const int mod = 998244353;
LL dp[N];
LL sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0] = dp[1] = 1;
	sum[0] = sum[1] = 1;
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		dp[i] = sum[i - 1];
		sum[i] = dp[i] + sum[i - 2];
		if (sum[i] >= mod) sum[i] -= mod;
	}
	int inv2 = (mod + 1) / 2;
	LL ans = dp[n];
	for (int i = 1; i <= n; i++)
	{
		ans = ans * inv2 % mod;
	}
	printf("%lld\n", ans);

	return 0;
}