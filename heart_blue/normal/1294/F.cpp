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
const int N = 2e5 + 10;
vector<int> v[N];
int maxlen[N];
int ans2[N];
tuple<int, int, int> maxv[N];
pair<int, int> ans = { 0,0 };
void dfs1(int x, int fa = 0)
{
	auto& [maxv1, maxv2, maxv3] = maxv[x];
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		maxv3 = max(maxv3, maxlen[y]);
		if (maxv2 < maxv3)
			swap(maxv2, maxv3);
		if (maxv1 < maxv2)
			swap(maxv1, maxv2);
	}
	ans2[x] = max(ans2[x], maxv1 + maxv2 + 1);
	maxlen[x] = maxv1 + 1;
	ans = max(ans, { maxv1 + maxv2 + maxv3 + 1,x });
}
void dfs2(int x, int fa = 0, int cur = 0)
{
	ans = max(ans, { cur + ans2[x],x });
	auto& [maxv1, maxv2, maxv3] = maxv[x];
	maxv3 = max(maxv3, cur);
	if (maxv2 < maxv3)
		swap(maxv2, maxv3);
	if (maxv1 < maxv2)
		swap(maxv1, maxv2);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs2(y, x, maxlen[y] == maxv1 ? maxv2 + 1 : maxv1 + 1);
	}
}
pair<int, int> key[N];
void dfs3(int x, int p = 0)
{
	int cnt = 0;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs3(y, x);
		key[x] = max(key[y], key[x]);
		cnt++;
	}
	if (cnt == 0) key[x].second = x;
	else key[x].first++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
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
	printf("%d\n", ans.first - 1);
	int rt = ans.second;
	dfs3(rt);
	vector<pair<int, int>> vp;
	for (auto& x : v[rt])
	{
		vp.emplace_back(key[x]);
	}
	sort(vp.rbegin(), vp.rend());
	vector<int> res;
	for (int i = 0; i < vp.size(); i++)
	{
		res.push_back(vp[i].second);
		if (res.size() == 3) break;
	}
	int cur = rt;

	while (res.size() < 3)
	{
		while (find(res.begin(), res.end(), cur) != res.end())
		{
			cur++;
		}
		if (cur > n)
		{
			cur = 1;
			continue;
		}
		res.push_back(cur);
	}
	for (auto& x : res)
		printf("%d ", x);
	return 0;
}