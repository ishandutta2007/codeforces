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
const int N = 2e2 + 10;
vector<int> v[N];
int vis[N];
int fa[N];
int dis[N];
int key[N];
int n;
int dfs(int x, int p = -1)
{
	fa[x] = p;
	dis[x] = 0;
	if (p != -1) dis[x] = dis[p] + 1;
	int ret = x;
	vis[x] = x;
	for (auto &y : v[x])
	{
		if (vis[y] == -1 || y == p) continue;
		int o = dfs(y, x);
		if (dis[ret] < dis[o]) ret = o;
	}
	return ret;
}
int solve(int x, int y)
{
	MEM(dis, 0);
	MEM(vis, 0);
	dfs(x);
	int o = y;
	int ans1 = dis[y];
	MEM(vis, 0);
	while (o != -1)
	{
		vis[o] = -1;
		o = fa[o];
	}
	vector<int> v1;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		v1.push_back(dfs(i));
	}
	MEM(dis, 0);
	for (auto &t : v1) dfs(t);
	int ans2 = 0;
	for (int i = 1; i <= n; i++) ans2 = max(ans2, dis[i]);
	return ans1 * ans2;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}