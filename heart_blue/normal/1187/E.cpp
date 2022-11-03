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
const int N = 2e5 + 10;
vector<int> v[N];
LL sum[N];
LL sz[N];
LL ans = 0;
int n;
void dfs1(int x, int fa = 0)
{
	sum[x] = 1;
	sz[x] = 1;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		sum[x] += sum[y] + sz[y];
	}
}
void dfs2(int x, LL pre = 0, int fa = 0)
{
	ans = max(ans, sum[x] + pre + n - sz[x]);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs2(y, sum[x] - sum[y] - sz[y] + pre + n - sz[x], x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	printf("%lld\n", ans);
	return 0;
}