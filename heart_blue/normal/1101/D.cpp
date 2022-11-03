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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> vd[N];
vector<int> v[N];
vector<pair<int, int>> vp[N];
int dis[N];
int a[N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}
void init()
{
	for (int i = 2; i < N; i++)
	{
		if (!vd[i].empty()) continue;
		for (int j = i; j < N; j += i)
			vd[j].push_back(i);
	}
}
pair<int, int> dfs(int x, int p = 0)
{
	dis[x] = dis[p] + 1;
	pair<int, int> ret = make_pair(dis[x], x);
	for (auto& y : v[x])
	{
		if (y == p) continue;
		ret = max(ret, dfs(y, x));
	}
	return ret;
}
int solve(int o)
{
	vector<int> key;
	for (auto& [x, y] : vp[o])
	{
		key.push_back(x);
		key.push_back(y);
		v[x].clear();
		v[y].clear();
	}
	sort(key.begin(), key.end());
	key.resize(unique(key.begin(), key.end()) - key.begin());
	for (auto& [x, y] : vp[o])
	{
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (auto& x : key)
	{
		dis[x] = 0;
	}
	int ret = 0;
	for (auto& x : key)
	{
		if (dis[x]) continue;
		auto [d, rt] = dfs(x);
		tie(d, rt) = dfs(rt);
		tie(d, rt) = dfs(rt);
		ret = max(ret, d);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > 1) ans = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int g = gcd(a[x], a[y]);
		for (auto& d : vd[g])
		{
			vp[d].emplace_back(x, y);
		}
	}
	for (int i = 2; i < N; i++)
	{
		ans = max(ans, solve(i));
	}
	printf("%d\n", ans);
	return 0;
}