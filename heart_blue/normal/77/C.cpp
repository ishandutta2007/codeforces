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
int a[N];
vector<int> v[N];
pair<LL, LL> dfs(int x, int fa = 0)
{
	LL ret0 = 0, ret1 = 0;
	LL tot = 0;
	vector<pair<LL, int>> key;
	LL rest = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		auto [res0, res1] = dfs(y, x);
		key.emplace_back(res1 + 2, 1);
		key.emplace_back(2, a[y] - 1);
		tot += res1 + 2 + 2 * (a[y] - 1);
		rest += a[y];
	}
	sort(key.rbegin(), key.rend());
	while (rest > a[x])
	{
		auto [val, cnt] = key.back();
		key.pop_back();
		int o = min(1LL * cnt, rest - a[x]);
		cnt -= o;
		rest -= o;
		tot -= o * val;
		if (cnt) key.emplace_back(val, cnt);
	}
	ret0 = tot;
	while (rest >= a[x])
	{
		auto [val, cnt] = key.back();
		key.pop_back();
		int o = min(1LL * cnt, rest - a[x] + 1);
		cnt -= o;
		rest -= o;
		tot -= o * val;
		if (cnt) key.emplace_back(val, cnt);
	}
	ret1 = tot;
	a[x] -= rest;
	return { ret0,ret1 };
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
	int s;
	scanf("%d", &s);
	auto [res1, res2] = dfs(s);
	printf("%lld\n", max(res1, res2));
	return 0;
}