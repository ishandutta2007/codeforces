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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<pair<int, int>> v[N];
int w[N];
pair<LL, LL> maxv[N];
LL ans = 0;
void dfs1(int x, int fa = 0)
{
	maxv[x].first = w[x];
	maxv[x].second = w[x];
	for (auto& p : v[x])
	{
		int y, val;
		tie(y, val) = p;
		if (y == fa) continue;
		dfs1(y, x);
		LL res = maxv[y].first - val;
		res = max(1LL * w[x], res + w[x]);
		if (res > maxv[x].second)
			maxv[x].second = res;
		if (maxv[x].first < maxv[x].second)
			swap(maxv[x].first, maxv[x].second);
	}
}
void dfs2(int x, int fa = 0, LL cur = 0)
{
	cur = max(1LL * w[x], cur + w[x]);
	if (cur > maxv[x].second) maxv[x].second = cur;
	if (maxv[x].first < maxv[x].second)
		swap(maxv[x].first, maxv[x].second);
	ans = max(ans, maxv[x].first);
	for (auto& p : v[x])
	{
		int y, val;
		tie(y, val) = p;
		if (y == fa) continue;
		LL res = maxv[y].first - val;
		res = max(res + w[x], 1LL * w[x]);
		if (res == maxv[x].first)
			res = maxv[x].second;
		else
			res = maxv[x].first;
		dfs2(y, x, res - val);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y, val;
		scanf("%d%d%d", &x, &y, &val);
		v[x].emplace_back(y, val);
		v[y].emplace_back(x, val);
	}
	dfs1(1);
	dfs2(1);
	printf("%lld\n", ans);
	return 0;
}