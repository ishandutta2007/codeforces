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
const int N = 2e5 + 10;
int dfn;
int in[N];
int out[N];
vector<pair<int, int>> vp[N];
void dfs(int x, int fa = 0)
{
	in[x] = ++dfn;
	for (auto& [w, y] : vp[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		w = in[y];
	}
	if (fa)
		vp[x].erase(find(vp[x].begin(), vp[x].end(), make_pair(0, fa)));
	out[x] = dfn;
}
void solve()
{
	int sz;
	scanf("%d", &sz);
	vector<int> key(sz);
	for (auto& x : key)
		scanf("%d", &x);
	sort(key.begin(), key.end(), [](const int& x, const int& y) ->bool
		{
			return in[x] < in[y];
		});
	if (key.size() <= 2)
	{
		puts("YES");
		return;
	}
	int cnt = 0;
	int rt = key[0];
	auto iter = upper_bound(vp[rt].begin(), vp[rt].end(), make_pair(in[key.back()], N));
	if (iter != vp[rt].begin())
	{
		iter--;

		int rt0 = iter->second;
		int l = in[rt0];
		int r = out[rt0];
		if (l <= in[key[1]] && in[key[1]] <= r && in[rt] <= in[key.back()] && in[key.back()] <= out[rt])
			cnt++;
	}
	while (!key.empty())
	{
		cnt++;
		int x = key.back();
		key.pop_back();
		while (!key.empty())
		{
			if (in[key.back()] <= in[x] && in[x] <= out[key.back()])
				key.pop_back();
			else
				break;
		}
	}
	if (cnt > 2) puts("NO");
	else puts("YES");
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
		vp[x].emplace_back(0, y);
		vp[y].emplace_back(0, x);
	}
	dfs(1);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		solve();
	}
	return 0;
}