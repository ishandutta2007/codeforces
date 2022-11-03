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
const int N = 1e2 + 10;
const int M = 1e6 + 10;
vector<tuple<int, int, int>> vp[N];
vector<tuple<int, int, int, int>> key[M];
vector<tuple<int, int, int, int>> edge;
int flag[M];
int ans[N];
int cur[N];
vector<int> v;
bool dfs(int x, int val)
{
	if (cur[x] != 0) return cur[x] == val;
	v.push_back(x);
	cur[x] = val;
	for (auto [y, key1, key2] : vp[x])
	{
		if (val != key1 && val != key2)
			return false;
		if (!dfs(y, val ^ key1 ^ key2))
			return false;
	}
	return true;
}
void check(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i) continue;
		flag[i] = 1;
		while (x % i == 0)
			x /= i;
	}
	flag[x] = 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	edge.resize(m);
	for (auto& [x, y, g, l] : edge)
	{
		scanf("%d%d%d%d", &x, &y, &g, &l);
		if (l % g) puts("NO"), exit(0);
		check(l);
	}

	fill(ans, ans + N, 1);
	for (int o = 2; o < M; o++)
	{
		if (flag[o] == 0) continue;
		for (int i = 1; i <= n; i++) vp[i].clear();
		for (auto [x, y, g, l] : edge)
		{
			if (l % o == 0)
			{
				int key1 = 1, key2 = 1;
				while (g % o == 0) key1 *= o, g /= o;
				while (l % o == 0) key2 *= o, l /= o;
				vp[x].emplace_back(y, key1, key2);
				vp[y].emplace_back(x, key1, key2);
			}
			else
			{
				vp[x].emplace_back(y, 1, 1);
				vp[y].emplace_back(x, 1, 1);
			}
		}
		MEM(cur, 0);
		for (int i = 1; i <= n; i++)
		{
			if (cur[i]) continue;
			if (vp[i].empty())
			{
				cur[i] = 1;
				continue;
			}
			vector<int> a;
			for (auto [j, t1, t2] : vp[i])
			{
				a.push_back(t1);
				a.push_back(t2);
				break;
			}
			int ok = 0;
			for (auto& val : a)
			{
				for (auto& x : v) cur[x] = 0;
				v.clear();
				if (dfs(i, val))
				{
					ok = 1;
					v.clear();
					break;
				}
			}
			if (!ok) puts("NO"), exit(0);
		}
		for (int i = 1; i <= n; i++)
			ans[i] *= cur[i];
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}