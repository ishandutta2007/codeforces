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
const int N = 2e5 + 10;
int a[N];
LL sum[N];
LL res[N];
vector<int> v[N];
LL ans = 0;
void dfs1(int x, int fa = 0)
{
	sum[x] = a[x];
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		sum[x] += sum[y];
		res[x] += sum[y] + res[y];
	}
}
void dfs2(int x, LL s = 0, LL r = 0, int fa = 0)
{
	ans = max(ans, res[x] + s + r);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs2(y, s + sum[x] - sum[y], s + r + res[x] - sum[y] - res[y], x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
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