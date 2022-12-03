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
int in[N];
int vis[N];
int dp[N];
vector<int> v[N];
int w[N];
bool dfs1(int x, int key)
{
	if (w[x] > key) return false;
	if (in[x]) return true;
	if (vis[x]) return false;
	in[x] = 1;
	vis[x] = 1;
	for (auto& y : v[x])
	{
		if (dfs1(y, key)) return true;
	}
	in[x] = 0;
	return false;
}
int dfs2(int x, int key)
{
	if (w[x] > key) return 0;
	if (dp[x]) return dp[x];
	dp[x] = 1;
	for (auto& y : v[x])
	{
		dp[x] = max(dp[x], dfs2(y, key) + 1);
	}
	return dp[x];
}
LL check(int n, int key)
{
	MEM(in, 0);
	MEM(vis, 0);
	MEM(dp, 0);
	for (int i = 1; i <= n; i++)
	{
		if (dfs1(i, key)) return INF * INF;
	}
	LL ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, 1LL * dfs2(i, key));
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	LL k;
	scanf("%d%d%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	int l = 1, r = INF;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(n, mid) >= k) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}