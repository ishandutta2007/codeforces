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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL dp[N];
int a[N];
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
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dp[0] = 0;
		for (int i = 2; i < n; i += 2)
		{
			dp[i] = dp[i - 2] + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
		}
		dp[n + 1] = 0;
		for (int i = n - 1; i > 1; i -= 2)
		{
			dp[i] = dp[i + 2] + max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
		}
		if (n & 1)
		{
			printf("%lld\n", dp[2]);
			continue;
		}
		LL ans = min(dp[3], dp[n - 2]);
		for (int i = 2; i + 3 < n; i++)
		{
			ans = min(ans, (dp[i] + dp[i + 3]));
		}
		printf("%lld\n", ans);



	}
	return 0;
}