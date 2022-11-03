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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
vector<int> v[N];
LL ans = 0;
pair<int, int> dfs(int x, int minv = INF, int fa = 0)
{
	int ret0 = 0;
	int ret1 = 0;
	if (b[x] != c[x])
	{
		if (b[x] == 0) ret0++;
		else ret1++;
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		auto res = dfs(y, min(minv, a[x]), x);
		ret0 += res.first;
		ret1 += res.second;
	}
	int o = min(ret0, ret1);
	ret0 -= o;
	ret1 -= o;
	ans += min(a[x], minv) * 2LL * o;
	return { ret0,ret1 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (count(b + 1, b + n + 1, 1) != count(c + 1, c + n + 1, 1))
	{
		puts("-1");
		return 0;
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}