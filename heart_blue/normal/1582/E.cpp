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
const int N = 1e5 + 10;
const int M = 450;
LL dp[N][M];
int a[N];
LL sum[N];
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
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = a[i] + sum[i - 1];
		}
		MEM(dp[n + 1], 0);
		int ans = 1;
		for (int i = n; i >= 1; i--)
		{
			MEM(dp[i], 0);
			dp[i][1] = a[i];
			for (int j = 2; j < M && i + j <= n; j++)
			{
				if (sum[i + j - 1] - sum[i - 1] < dp[i + j][j - 1])
				{
					dp[i][j] = sum[i + j - 1] - sum[i - 1];
					ans = max(ans, j);
				}
			}
			for (int j = 1; j < M; j++)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}