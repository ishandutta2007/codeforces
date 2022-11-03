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
const int N = 3e5 + 10;
vector<int> vp[N];
int depth[N];
int fa[N];
int ans[N];
vector<pair<int, int>> key[N];
set<int> s;
void dfs(int x, int p = 0)
{
	depth[x] = depth[p] + 1;
	fa[x] = p;
	for (auto& y : vp[x])
	{
		if (y == p) continue;
		dfs(y, x);
	}
}
void solve(int x, int p = 0)
{
	s.emplace(x);
	for (auto [pos, y] : key[x])
	{
		if (!s.count(y))
			ans[pos] = 0;
	}
	for (auto& y : vp[x])
	{
		if (y == p) continue;
		solve(y, x);
	}
	s.erase(x);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	dfs(1);
	fa[1] = 1;
	for (int i = 1; i <= q; i++)
	{
		ans[i] = 1;
		int sz;
		scanf("%d", &sz);
		vector<int> v(sz);
		for (auto& x : v)
		{
			scanf("%d", &x);
			x = fa[x];
		}
		v.push_back(1);
		sort(v.begin(), v.end(), [](const int& x, const int& y)->bool
			{
				return depth[x] < depth[y];
			});
		for (int j = 1; j < v.size(); j++)
		{
			key[v[j]].emplace_back(i, v[j - 1]);
		}
	}
	solve(1);
	for (int i = 1; i <= q; i++)
	{
		if (ans[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}