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
const int N = 3e5 + 10;
double dp[N];
int cnt[N];
double a[20][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double x;
			scanf("%lf", &x);
			if (i == j) continue;
			a[i][1 << j] = 1 - x;
		}
		for (int j = 1; j < (1 << n); j++)
		{
			a[i][j] = a[i][(j & -j)] + a[i][j - (j & -j)];
		}
	}
	dp[(1 << n) - 1] = 1;
	for (int o = (1 << n) - 1; o >= 1; o--)
	{
		if (cnt[o] == 1) continue;
		int sum = cnt[o] * (cnt[o] - 1) / 2;
		for (int j = 0; j < n; j++)
		{
			if (o >> j & 1)
			{
				dp[o ^ (1 << j)] += dp[o] * a[j][o] / sum;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%.10f ", dp[1 << i]);
	return 0;
}