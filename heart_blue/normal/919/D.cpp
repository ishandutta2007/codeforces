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
vector<int> v[N];
char str[N];
int dp[N];
int cnt = 0;
int dfn[N];
int low[N];
int in[N];
stack<int> s;
bool dfs(int x, int fa = -1)
{
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	in[x] = 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		if (dfn[y])
		{
			if (in[y])
				low[x] = min(low[x], dfn[y]);
		}
		else
		{
			if (!dfs(y, x)) return false;
			low[x] = min(low[x], low[y]);
		}
		if (low[x] < dfn[x])
			return false;
	}
	if (dfn[x] == low[x])
	{
		while (1)
		{
			int y = s.top();
			in[y] = 0;
			s.pop();
			if (x == y) break;
		}
	}
	return true;
}
int solve(int x, char c, int fa = -1)
{
	if (dp[x] >= 0) return dp[x];
	dp[x] = str[x] == c;
	int maxv = 0;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		maxv = max(solve(y, c, x), maxv);
	}
	dp[x] += maxv;
	return dp[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y)
		{
			puts("-1");
			return 0;
		}
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i]) continue;
		if (!dfs(i))
		{
			puts("-1");
			return 0;
		}
	}
	int ans = 0;
	for (int i = 'a'; i <= 'z'; i++)
	{
		MEM(dp, -1);
		for (int j = 1; j <= n; j++)
		{
			ans = max(ans, solve(j, i));
		}
	}
	printf("%d\n", ans);
	return 0;
}