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
const int N = 6e1 + 10;
double dp1[N][N];
double dp2[N][N];
double p[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int tot = 1 << n;
	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < tot; j++)
		{
			scanf("%lf", &p[i][j]);
			p[i][j] /= 100;
		}
	}
	for (int i = 0; i < tot; i++)
		dp1[0][i] = 1;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < tot; j++)
		{
			for (int k = 0; k < tot; k++)
			{
				if ((j >> i) != (k >> i)) continue;
				if ((j >> (i - 1)) == (k >> (i - 1))) continue;
				dp1[i][j] += dp1[i - 1][j] * dp1[i - 1][k] * p[j][k];
			}
		}
		for (int j = 0; j < tot; j++)
		{
			for (int k = 0; k < tot; k++)
			{
				if ((j >> i) != (k >> i)) continue;
				if ((j >> (i - 1)) == (k >> (i - 1))) continue;
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j] + dp2[i - 1][k] + dp1[i][j] * (1 << (i - 1)));
			}
		}
	}
	for (int i = 0; i < tot; i++)
		ans = max(ans, dp2[n][i]);
	printf("%.15f\n", ans);
	return 0;
}