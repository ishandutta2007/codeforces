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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int deg[N];
vector<pair<int, int>> vp[N];
int ans[N];
void dfs(int x, int o = 2, int fa = 0)
{
	for (auto& [y, id] : vp[x])
	{
		if (y == fa) continue;
		ans[id] = o;
		dfs(y, o ^ 1, x);
		o ^= 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			vp[i].clear();
		fill(deg + 1, deg + n + 1, 0);
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vp[x].emplace_back(y, i);
			vp[y].emplace_back(x, i);
			deg[x]++;
			deg[y]++;
		}
		if (*max_element(deg + 1, deg + n + 1) > 2) puts("-1");
		else
		{
			dfs(1);
			for (int i = 1; i < n; i++)
				printf("%d%c", ans[i], " \n"[i + 1 == n]);

		}
	}
	return 0;
}