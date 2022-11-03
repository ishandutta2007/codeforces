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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
vector<pair<int, int>> vp[N];
vector<int> v[N];
int pos[N];
int deg[N];
int vis[N];
vector<int> ans;
void dfs(int x, int p = 0, int o = 0)
{
	if (vis[x]) return;
	v[p].push_back(x);
	vis[x] = 1;
	pos[x] = o;
	for (auto &pp : vp[x])
	{
		int y, oo;
		tie(y, oo) = pp;
		dfs(y, x, oo);
	}
}
int solve(int x)
{
	int cur = deg[x];
	for (auto &y : v[x])
	{
		cur ^= solve(y);
	}
	if (cur) ans.push_back(pos[x]);
	return cur;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int cnt1 = 0, cnt_1 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> deg[i];
		if (deg[i] == 1) cnt1 ^= 1;
		if (deg[i] == -1) cnt_1++;
	}
	if (cnt1 == 1 && cnt_1 == 0)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == -1)
		{
			deg[i] = cnt1;
			cnt1 = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		vp[x].push_back({ y,i });
		vp[y].push_back({ x,i });
	}
	dfs(1);
	solve(1);
	printf("%d\n", ans.size());
	for (auto &x : ans) printf("%d\n", x);
	return 0;
}