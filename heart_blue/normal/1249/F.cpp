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
const int N = 2e2 + 10;
vector<int> v[N];
int dp[N][N];
int sum[N];
int a[N];
int n, k;
void dfs(int x, int fa = 0)
{
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
	MEM(sum, 0);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		for (int i = 0; i <= k; i++)
		{
			sum[i] += dp[y][i];
		}

		dp[x][0] += dp[y][k];
	}
	dp[x][0] += a[x];
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		for (int i = 1; i <= k; i++)
		{
			int o = max(i - 1, k - i);
			dp[x][i] = max(dp[x][i], dp[y][i - 1] + sum[o] - dp[y][o]);
		}
	}
	for (int i = k; i >= 0; i--)
		dp[x][i] = max(dp[x][i], dp[x][i + 1]);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans = max(ans, dp[1][i]);
	}
	printf("%d\n", ans);
	return 0;
}