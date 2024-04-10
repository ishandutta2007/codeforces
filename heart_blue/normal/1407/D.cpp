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
const int N = 3e5 + 10;
class UnionFind
{
public:
	int p[N];
	int l[N];
	int r[N];
	void init(int n = N)
	{
		memset(p, -1, sizeof(int) * n);
		for (int i = 0; i < n; i++)
			l[i] = r[i] = i;
	}
	int treesize(int x)
	{
		return -p[Find(x)];
	}
	int Find(int x)
	{
		int s = x;
		while (p[s] >= 0) s = p[s];
		while (x != s)
		{
			int t = p[x];
			p[x] = s;
			x = t;
		}
		return s;
	}
	pair<int, int> getlr(int x)
	{
		int fa = Find(x);
		return { l[fa],r[fa] };
	}
	void Union(int x, int y)
	{
		int px = Find(x);
		int py = Find(y);
		if (px == py) return;
		if (p[px] > p[py]) swap(px, py);
		l[px] = min(l[px], l[py]);
		r[px] = max(r[px], r[py]);
		p[px] += p[py];
		p[py] = px;
	}
} uf;
int flag[N];
vector<int> v[N];
int dp[N];
void check(vector<pair<int, int>> vp, int o)
{
	sort(vp.begin(), vp.end());
	if (o)
		reverse(vp.begin(), vp.end());
	uf.init();
	MEM(flag, 0);
	while (!vp.empty())
	{
		vector<int> key;
		int val = vp.back().first;
		while (!vp.empty() && vp.back().first == val)
		{
			int x = vp.back().second;
			vp.pop_back();
			flag[x] = 1;
			if (flag[x - 1])
				uf.Union(x, x - 1);
			if (flag[x + 1])
				uf.Union(x, x + 1);
			key.push_back(x);
		}
		for (auto& x : key)
		{
			auto [l, r] = uf.getlr(x);
			v[l - 1].push_back(r + 1);
		}
	}
}
int dfs(int x)
{
	if (dp[x] != -1) return dp[x];
	dp[x] = INF;
	for (auto& y : v[x])
	{
		dp[x] = min(dp[x], dfs(y) + 1);
	}
	return dp[x];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		vp.emplace_back(x, i);
		v[i].push_back(i + 1);
	}
	check(vp, 1);
	check(vp, 0);
	MEM(dp, -1);
	dp[n] = 0;
	dp[n + 1] = INF;
	printf("%d\n", dfs(1));
	return 0;
}