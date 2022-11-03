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
const int N = 5e3 + 10;
LL dp[N][N];
LL lsum[N];
LL rsum[N];
LL a[N];
LL b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
	for (int i = 1; i <= n; i++)
	{
		lsum[i] = lsum[i - 1] + a[i] * b[i];
	}
	for (int i = n; i >= 1; i--)
	{
		rsum[i] = rsum[i + 1] + a[i] * b[i];
	}
	for (int i = 1; i <= n; i++)
		dp[i][i] = a[i] * b[i];
	LL ans = lsum[n];
	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			dp[i][j] = dp[i + 1][j - 1] + a[i] * b[j] + a[j] * b[i];
			ans = max(ans, dp[i][j] + lsum[i - 1] + rsum[j + 1]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}