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
const int N = 2e2 + 10;
int dis[N];
vector<int> v[N];
void dfs(int x, int fa = -1)
{
	dis[x] = 0;
	if (fa != -1) dis[x] = dis[fa] + 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
	}
}
int getans(int n, int& rt)
{
	dfs(rt);
	for (int i = 1; i <= n; i++)
	{
		if (dis[rt] < dis[i]) rt = i;
	}
	return dis[rt];
}
int solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int rt = 1;
	getans(n, rt);
	return getans(n, rt);
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ncase;
	int ans = 0;
	cin >> ncase;
	while (ncase--)
	{
		ans += solve();
	}
	cout << ans << endl;
	return 0;
}