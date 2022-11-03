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
const int N = 60 + 10;
int dp[N][N][N];
int cnt[N];
int mask;
int refrain(int x)
{
	int ret = x;
	ret |= (x << 1) | (x >> 1);
	return ret & mask;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	MEM(dp, 0xcf);
	dp[0][0][0] = 0;
	int tot = 1 << n;
	mask = tot - 1;
	for (int i = 0; i < m; i++)
	{
		for (int o1 = 0; o1 < tot; o1++)
		{
			for (int o2 = 0; o2 < tot; o2++)
			{
				if (o1 & o2) continue;
				if (dp[i][o1][o2] < 0) continue;
				for (int o3 = 0; o3 < tot; o3++)
				{
					if ((o2 & o3) != o2) continue;
					int o4 = (o1 | refrain(o3)) ^ mask;
					dp[i + 1][o3][o4] = max(dp[i + 1][o3][o4], dp[i][o1][o2] + cnt[mask ^ o3]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < tot; i++)
	{
		ans = max(ans, dp[m][i][0]);
	}
	printf("%d\n", ans);
	return 0;

}