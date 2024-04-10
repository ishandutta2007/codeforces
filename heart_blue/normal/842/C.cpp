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
vector<int> vd[N], vp[N];
int ans[N];
int cnt[N];
int w[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i) vd[j].push_back(i);
	}
}

void dfs(int x, int o = 1, int fa = -1)
{
	for (auto &d : vd[w[x]]) cnt[d]++;
	ans[x] = 1;
	for (auto &d : vd[w[x]])
	{
		if (cnt[d] >= o - 1)
			ans[x] = max(ans[x], d);
	}
	if (fa != -1)
	{
		for (auto &d : vd[w[fa]])
		{
			if (cnt[d] >= o - 1)
				ans[x] = max(ans[x], d);
		}
	}
	for (auto &y : vp[x])
	{
		if (y == fa) continue;
		dfs(y, o + 1, x);
	}
	for (auto &d : vd[w[x]]) cnt[d]--;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}