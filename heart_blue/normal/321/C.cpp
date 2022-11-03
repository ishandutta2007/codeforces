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
vector<int> v[N];
int vis[N];
int sons[N];
int ans[N];
int maxv[N];
int dfssize(int x, int fa = -1)
{
	sons[x] = 1;
	for (auto &y : v[x])
	{
		if (vis[y] || y == fa) continue;
		int sz = dfssize(y, x);
		sons[x] += sz;
	}
	return sons[x];
}
int dfsroot(int s, int x, int fa = -1)
{
	int maxv = sons[s] - sons[x];
	for (auto &y : v[x])
	{
		if (vis[y] || y == fa) continue;
		int ret = dfsroot(s, y, x);
		if (ret != -1)
		{
			return ret;
		}
		maxv = max(maxv, sons[y]);
	}
	if (maxv * 2 <= sons[s]) return x;
	else return -1;
}
void solve(int x, int depth = 0)
{
	dfssize(x);
	int root = dfsroot(x, x);
	vis[root] = 1;
	ans[root] = depth;
	for (auto &y : v[root])
	{
		if (vis[y]) continue;
		solve(y, depth + 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%c ", ans[i] + 'A');
	}
	return 0;
}