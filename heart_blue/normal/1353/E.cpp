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
const int N = 2e6 + 10;
int sum[N];
int dp[N];
char str[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) a[i] = str[i] & 1;
		for (int i = 1; i <= n; i++)
			sum[i] = a[i] + sum[i - 1];
		int ans = sum[n];
		for (int i = 1; i <= n; i++)
		{
			dp[i] = sum[i - 1];
			if (i >= k)
				dp[i] = min(dp[i], dp[i - k] + sum[i - 1] - sum[i - k] + (a[i] ^ 1));
			ans = min(ans, dp[i] + sum[n] - sum[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}