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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int fa[N];
int w[N];
vector<int> v[N];
int depth[N];
void dfs(int x, int p = 0)
{
	fa[x] = p;
	depth[x] = depth[p] + 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
vector<int> check(int x, int y)
{
	vector<int> v;
	while (x != y)
	{
		if (depth[x] < depth[y])
			swap(x, y);
		v.push_back(x);
		x = fa[x];
	}
	return v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		vp.emplace_back(x, y);
	}
	fill(w + 1, w + n + 1, 1000000);
	dfs(1);
	vector<tuple<int, int, int>> key;	
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		key.emplace_back(w, x, y);
	}
	sort(key.begin(), key.end());
	for (auto [w, x, y] : key)
	{
		auto v = check(x, y);
		for (auto& o : v)
			::w[o] = w;
	}
	for (auto [w, x, y] : key)
	{
		auto v = check(x, y);
		int minv = INF;
		for (auto& o : v)
			minv = min(minv, ::w[o]);
		if (minv != w)
		{
			puts("-1");
			return 0;
		}
	}
	for (auto [x, y] : vp)
	{
		if (fa[x] != y) swap(x, y);
		printf("%d ", w[x]);
	}
	return 0;
}