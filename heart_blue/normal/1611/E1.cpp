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
vector<int> v[N];
int minv[N];
void dfs1(int x, int fa = 0)
{
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		minv[x] = min(minv[x], minv[y] + 1);
	}
}
bool dfs2(int x, int cur = 0, int fa = 0)
{
	if (minv[x] <= cur) return false;
	if (fa != 0 && v[x].size() == 1) return true;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (dfs2(y, cur + 1, x))
			return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		fill(minv + 1, minv + n + 1, int(INF));
		while (m--)
		{
			int x;
			scanf("%d", &x);
			minv[x] = 0;
		}
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1);
		if (dfs2(1)) puts("YES");
		else puts("NO");
	}
	return 0;
}