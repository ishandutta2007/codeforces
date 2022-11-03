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
int flag[N];
int dis[N];
int dfs1(int x, int p = 0)
{
	for (auto &y : v[x])
	{
		if (y == p) continue;
		flag[x] |= dfs1(y, x);
	}
	return flag[x];
}
void dfs2(int x, int p = 0)
{
	if (flag[x] == 0) return;
	dis[x] = dis[p] + 1;
	for (auto &y : v[x])
	{
		if (y == p) continue;
		dfs2(y, x);
	}
}
int solve(int &rt, int n)
{
	dfs1(rt);
	MEM(dis, -1);
	dfs2(rt);
	for (int i = n; i >= 1; i--) if (dis[rt] <= dis[i]) rt = i;

	int ans = rt;
	dfs2(rt);
	for (int i = n; i >= 1; i--) if (dis[rt] <= dis[i]) rt = i;
	ans = min(ans, rt);

	dfs2(rt);
	for (int i = n; i >= 1; i--) if (dis[rt] <= dis[i]) rt = i;
	ans = min(ans, rt);

	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += flag[i];
	int ret = (cnt - 1) * 2 - dis[rt];
	rt = ans;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int rt;
	while (m--)
	{
		cin >> rt;
		flag[rt] = 1;
	}
	int ans = solve(rt, n);
	cout << rt << endl;
	cout << ans << endl;
	return 0;
}