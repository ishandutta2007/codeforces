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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
LL dp[N][N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		string s1, s2;
		cin >> s1 >> s2;
		int sz = 0;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] ^ s2[i])
				a[++sz] = i;
		}
		if (sz & 1)
		{
			puts("-1");
			continue;
		}
		if (sz == 2)
		{
			int s = a[1];
			int t = a[2];
			if (s + 1 == t)
			{
				LL ans = x;
				int k = -1;
				for (int i = 1; i <= n; i++)
				{
					if (abs(i - s) != 1 && abs(i - t) != 1)
					{
						k = i;
						break;
					}
				}
				if (k != -1)
				{
					ans = min(ans, y * 2LL);
				}
				printf("%lld\n", ans);
				continue;
			}
		}
		MEM(dp[0], 0x3f);
		dp[0][0] = 0;
		MEM(dp[1], 0x3f);
		dp[1][1] = 0;

		for (int i = 2; i <= sz; i++)
		{
			MEM(dp[i], 0x3f);
			for (int j = 1; j <= i; j++)
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			int len = a[i] - a[i - 1];
			for (int j = 0; j <= i; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i - 2][j] + 1LL * x * len);
			}
		}
		LL ans = INF * INF;
		for (int i = 0; i <= sz; i += 2)
		{
			ans = min(ans, dp[sz][i] + (i / 2) * 1LL * y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}