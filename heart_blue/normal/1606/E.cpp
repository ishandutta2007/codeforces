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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
const int mod = 998244353;
LL dp[N][N];
LL c[N][N];
LL p[N][N];
void init()
{
	MEM(dp, -1);
	for (int i = 0; i < N; i++) c[i][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= mod)
				c[i][j] -= mod;
		}
	}
	for (int i = 1; i < N; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j < N; j++)
		{
			p[i][j] = p[i][j - 1] * i % mod;
		}
	}
}
LL dfs(int n, int x)
{
	if (x <= n - 1)
	{
		return p[x][n] - p[x - 1][n];
	}
	if (n == 1) return 0;
	if (dp[n][x] != -1) return dp[n][x];
	LL ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += c[n][i] * p[n - 1][n - i] % mod * dfs(i, x - (n - 1)) % mod;
	}
	ret %= mod;
	if (ret < 0) ret += mod;
	return dp[n][x] = ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n, x;
	scanf("%d%d", &n, &x);
	LL ret = 0;
	for (int i = 1; i <= x; i++)
		ret += dfs(n, i);
	printf("%lld\n", ret % mod);
	return 0;
}