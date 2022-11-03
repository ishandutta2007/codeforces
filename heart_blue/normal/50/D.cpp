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
const int N = 1e2 + 10;
const double eps = 1e-9;
double dp[N];
int dis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n;
	scanf("%d", &n);
	int k;
	int limit;
	scanf("%d%d", &k, &limit);
	int x0, y0;
	scanf("%d%d", &x0, &y0);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x -= x0, y -= y0;
		dis[i] = x * x + y * y;
	}
	double l = 0, r = 1e9;
	int cnt = 100;
	while (cnt--)
	{
		double mid = (l + r) / 2;
		fill(dp, dp + N, 0.0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			double p;
			if (dis[i] <= mid * mid)
				p = 1;
			else
				p = exp(1 - dis[i] / mid / mid);
			for (int j = i; j >= 1; j--)
			{
				dp[j] = (1 - p) * dp[j] + p * dp[j - 1];
			}
			dp[0] = dp[0] * (1 - p);
		}
		double sum = 0;
		for (int i = 0; i < k; i++)
			sum += dp[i];
		if (sum * 1000 - eps >= limit) l = mid;
		else r = mid;
	}
	printf("%.15f\n", r);
	return 0;
}