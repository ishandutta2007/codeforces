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
const int N = 1e3 + 10;
long long dp[20][2];
int d[20];
double ddp[N];
LL dfs(int cur, int state, bool limit = true, bool lead = true)
{
	if (cur == -1)
	{
		return state;
	}
	if (!limit && !lead && dp[cur][state] != -1)
		return dp[cur][state];
	int up = limit ? d[cur] : 9;
	LL ret = 0;
	for (int i = 0; i <= up; i++)
	{
		ret += dfs(cur - 1, state | (i == 1 && lead ? 1 : 0), limit && i == d[cur], lead && i == 0);
	}
	if (!limit && !lead)
		dp[cur][state] = ret;
	return ret;
}
LL solve(LL x)
{
	int len = 0;
	while (x)
	{
		d[len++] = x % 10;
		x /= 10;
	}
	return dfs(len - 1, 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int n;
	scanf("%d", &n);
	ddp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		LL l, r;
		scanf("%lld%lld", &l, &r);
		double p = (solve(r) - solve(l - 1)) * 1.0 / (r - l + 1);
		for (int j = i; j >= 0; j--)
		{
			ddp[j] = ddp[j] * (1 - p);
			if (j > 0) ddp[j] += ddp[j - 1] * p;
		}
	}
	int k;
	scanf("%d", &k);
	double ans = 0;
	for (int i = 0; i <= n; i++)
	{
		if (i * 100 >= k * n)
		{
			ans += ddp[i];
		}
	}
	printf("%.15f\n", ans);
	return 0;
}