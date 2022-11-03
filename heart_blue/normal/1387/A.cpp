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
int dp[N][2];
vector<pair<int, int>> vp[N];
double ans[N];
int inf = 0x3f3f3f3f;
void dfs(int x, int o, int val, vector<pair<int, int>>& key)
{
	if (dp[x][o] != inf)
	{
		if (dp[x][o] != val)
		{
			puts("NO");
			exit(0);
		}
		return;
	}
	key.emplace_back(x, o);
	dp[x][o] = val;
	for (auto& [y, w] : vp[x])
	{
		dfs(y, o ^ 1, w - val, key);
	}
}
double check(vector<pair<int, int>>& vp)
{
	vector<pair<int, int>> v;
	for (auto [x, o] : vp)
	{
		v.emplace_back(dp[x][o] * (o == 0 ? -1 : 1), x);
	}
	sort(v.begin(), v.end());
	return v[v.size() / 2].first;
}
void solve(vector<pair<int, int>>& vp, double val)
{
	for (auto [x, o] : vp)
	{
		if (o == 0) ans[x] = dp[x][o] + val;
		else ans[x] = dp[x][o] - val;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		vp[x].emplace_back(y, w);
		vp[y].emplace_back(x, w);
	}
	MEM(dp, 0x3f);
	for (int i = 1; i <= n; i++)
	{
		if (dp[i][0] != inf || dp[i][1] != inf) continue;
		vector<pair<int, int>> key;
		dfs(i, 0, 0, key);
		if (dp[i][1] != inf)
		{
			int pre = -2 * INF;
			for (auto& [x, o] : key)
			{
				int sum = dp[x][1] - dp[x][0];
				if (sum != pre && pre != -2 * INF) puts("NO"), exit(0);
				pre = sum;
			}
			solve(key, pre / 2.0);
			continue;
		}
		solve(key, check(key));
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%.15f ", ans[i]);
	return 0;
}