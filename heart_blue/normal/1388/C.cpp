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
vector<int> v[N];
int sz[N];
int sz1[N];
int sz2[N];
int h[N];
bool dfs(int x, int fa = 0)
{
	sz1[x] = sz2[x] = 0;
	int tot = sz[x];
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (!dfs(y, x)) return false;
		tot += sz[y];
		sz1[x] += sz1[y];
		sz2[x] += sz2[y];
	}
	if ((tot & 1) ^ (abs(h[x]) & 1)) return false;
	int a = (tot + h[x]) / 2;
	int b = tot - a;
	if (a < 0 || b < 0) return false;
	if (sz2[x] + sz[x] < b) return false;
	sz2[x] += sz[x];
	int o = max(0, sz2[x] - b);
	sz2[x] -= o;
	sz1[x] += o;
	sz[x] = tot;
	return true;
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
		for (int i = 1; i <= n; i++) scanf("%d", &sz[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if (dfs(1)) puts("YES");
		else puts("NO");
	}
	return 0;
}