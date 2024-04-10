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
const int N = 5e3 + 10;
short pos[N][N];
vector<pair<int, int>> vp[N];
short dp[N][N];
int minv[N];
int cnt[N];
int a[N];
int tot = 0;
int dfs(int l, int r, int cur)
{
	if (cur >= N) return INF;
	if (pos[l][r] == 0)
	{
		pos[l][r] = ++tot;
		minv[tot] = INF;
		for (int i = l; i <= r; i++)
		{
			minv[tot] = min(minv[tot], a[i]);
		}
		cnt[tot] = count(a + l, a + r + 1, minv[tot]);
		auto& v = vp[tot];
		for (int i = l; i <= r; i++)
		{
			if (a[i] == minv[tot]) continue;
			if (v.empty() || i > v.back().second + 1) v.emplace_back(i, i);
			else v.back().second++;
		}
	}
	int id = pos[l][r];
	if (dp[id][cur] != -1) return dp[id][cur];
	if (cnt[id] == r - l + 1) return min(r - l + 1, minv[id] - cur);
	int ret1 = cnt[id], ret2 = minv[id] - cur;
	for (auto [l, r] : vp[id])
	{
		ret1 += dfs(l, r, cur);
		ret2 += dfs(l, r, minv[id]);
		if (ret2 >= INF) ret2 = INF;
	}
	return dp[id][cur] = min(ret1, ret2);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", dfs(1, n, 0));
	return 0;
}