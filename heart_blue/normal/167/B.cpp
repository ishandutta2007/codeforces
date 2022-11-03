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
const int N = 2e2 + 10;
double dp[N][N][N * 2];
double p[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int offset = 200;
	int maxv = 400;
	MEM(dp, 0);
	int n, l, k;
	cin >> n >> l >> k;
	dp[0][0][200 + k] = 1;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < i; j++)
		{
			for (int k = maxv; k >= 0; k--)
			{
				if (dp[i - 1][j][k] < 1e-12) continue;
				dp[i][j + 1][min(maxv, k + x)] += dp[i - 1][j][k] * p[i] / 100.0;
				dp[i][j][k] += dp[i - 1][j][k] * (100 - p[i]) / 100;
			}
		}
	}
	double ans = 0;
	for (int i = l; i <= n; i++)
	{
		for (int j = offset; j <= maxv; j++)
		{
			ans += dp[n][i][j];
		}
	}
	printf("%.15f\n", ans);
	return 0;
}