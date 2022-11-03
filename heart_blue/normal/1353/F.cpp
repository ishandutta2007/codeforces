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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
LL a[N][N];
int flag[N][N];
LL dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<LL> v;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%lld", &a[i][j]);
				a[i][j] -= i + j;
				v.push_back(a[i][j]);
			}
		}
		LL ans = 4 * INF * INF;
		for(auto &x : v)
		{
			MEM(flag, 0);
			MEM(dp, 0x3f);
			LL inf = dp[0][0];
			flag[1][1] = 1;
			dp[1][1] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (a[i][j] < x) flag[i][j] = 0;
					if (flag[i][j] == 0) continue;
					dp[i][j] += a[i][j] - x;
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
					flag[i + 1][j] |= 1;
					flag[i][j + 1] |= 1;
				}
			}
			if (flag[n][m] != 0)
				ans = min(ans, dp[n][m]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}