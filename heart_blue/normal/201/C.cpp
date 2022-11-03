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
int a[N];
LL sum[N];
LL dp[N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--)
	{
		sum[i] = a[i] / 2 * 2 + sum[i + 1];
		if (a[i] < 2) sum[i] = 0;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, sum[i] + max(dp[i][0], dp[i][1]));
		dp[i + 1][0] = dp[i][0] + a[i] / 2 * 2;
		if (a[i] < 2) dp[i + 1][0] = 0;
		int x = a[i];
		if (x % 2 == 0) x--;
		dp[i + 1][1] = max(dp[i + 1][0], dp[i][1] + x);
	}
	printf("%lld\n", ans);
	return 0;
}