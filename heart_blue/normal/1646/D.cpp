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
const int N = 2e5 + 10;
pair<int, int> dp[N][2];
vector<int> v[N];
int ans[N];
pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return { p1.first + p2.first,p1.second + p2.second };
}
void dfs1(int x, int fa = 0)
{
	pair<int, int> res0, res1;
	res0 = res1 = { 0,0 };
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		auto p0 = dp[y][0];
		auto p1 = dp[y][1];
		res0 = res0 + max(p0, p1);
		res1 = res1 + p0;
	}
	res0.second--;
	res1.first++;
	res1.second -= v[x].size();
	dp[x][0] = res0;
	dp[x][1] = res1;
}
void dfs2(int x, int o, int fa = 0)
{
	if (o == 0) ans[x] = 1;
	else ans[x] = v[x].size();
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (o == 1)
		{
			dfs2(y, 0, x);
		}
		else
		{
			if (dp[y][0] >= dp[y][1]) dfs2(y, 0, x);
			else dfs2(y, 1, x);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	if (n == 2)
	{
		puts("2 2");
		puts("1 1");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1);
	auto res = max(dp[1][0], dp[1][1]);
	if (dp[1][0] >= dp[1][1]) dfs2(1, 0);
	else dfs2(1, 1);
	printf("%d %d\n", res.first, -res.second);
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}