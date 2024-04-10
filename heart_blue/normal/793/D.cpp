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
const int N = 8e1 + 10;
int dp[N][N][N];
vector<pair<int, int>> vp[N];
int dfs(int o, int u, int v)
{
	if (dp[o][u][v] != -1)
		return dp[o][u][v];
	if (o == 0) return 0;
	int& ret = dp[o][u][v] = INF;
	int l = min(u, v) + 1;
	int r = max(u, v) - 1;
	for (auto& [x, w] : vp[u])
	{
		if (x < l || x > r) continue;
		ret = min(ret, dfs(o - 1, x, u) + w);
		ret = min(ret, dfs(o - 1, x, v) + w);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		vp[0].emplace_back(i, 0);
		vp[n + 1].emplace_back(i, 0);
	}
	MEM(dp, -1);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x].emplace_back(y, w);
	}
	int ans = min(dfs(k, 0, n + 1), dfs(k, n + 1, 0));
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}