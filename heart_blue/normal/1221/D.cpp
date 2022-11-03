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
const int N = 3e5 + 10;
const int M = 6;
int a[N];
int b[N];
LL dp[N][6];
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
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
		for (int i = 1; i <= n; i++) MEM(dp[i], 0x3f);
		a[0] = -INF;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < M; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (a[i - 1] + j == a[i] + k) continue;
					dp[i][k] = min(dp[i][k], dp[i - 1][j] + 1LL * k * b[i]);
				}
			}
		}
		LL ans = INF * INF;
		for (int i = 0; i < M; i++)
			ans = min(ans, dp[n][i]);
		printf("%lld\n", ans);
	}
	return 0;
}