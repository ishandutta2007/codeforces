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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int dp[N];
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
		fill(dp, dp + n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (i + a[i] <= n && dp[i - 1] == 1) dp[i + a[i]] = 1;
			if (i - a[i] - 1 >= 0 && dp[i - a[i] - 1] == 1)
				dp[i] = 1;
		}
		if (dp[n]) puts("YES");
		else puts("NO");
	}
	return 0;
}