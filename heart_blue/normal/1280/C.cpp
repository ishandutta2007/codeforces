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
LL ans1 = 0, ans2 = 0;
vector<pair<int, int>> vp[N];
int sons[N];
int n;
void dfs(int x, int fa = 0)
{
	sons[x] = 0;
	for (auto [y, w] : vp[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		sons[x] += sons[y];
		ans2 += 1LL * min(2 * n - sons[y], sons[y]) * w;
		if (sons[y] & 1) ans1 += w;
	}
	sons[x]++;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) vp[i].clear();
		for (int i = 1; i < 2 * n; i++)
		{
			int x, y, w;
			scanf("%d%d%d", &x, &y, &w);
			vp[x].emplace_back(y, w);
			vp[y].emplace_back(x, w);
		}
		ans1 = 0, ans2 = 0;
		dfs(1);
		printf("%lld %lld\n", ans1, ans2);
	}
	return 0;
}