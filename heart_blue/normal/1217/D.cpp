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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
vector<pair<int, int>> v[N];
int ans[N];
int dfn[N], low[N], cnt;
int s[N], top;
int in[N];
void dfs(int x)
{
	low[x] = dfn[x] = ++cnt;
	s[top++] = x;
	in[x] = 1;
	for (auto& [y, id] : v[x])
	{
		if (dfn[y])
		{
			if (in[y])
			{
				if (dfn[x] > dfn[y])
					ans[id] = 2;
				low[x] = min(low[x], dfn[y]);
			}
		}
		else
		{
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == dfn[x])
	{
		while (1)
		{
			int y = s[--top];
			in[y] = 0;
			if (y == x) break;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].emplace_back(y, i);
	}
	fill(ans + 1, ans + m + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		if (dfn[i]) continue;
		dfs(i);
	}
	if (count(ans + 1, ans + m + 1, 2)) puts("2");
	else puts("1");
	for (int i = 1; i <= m; i++)
	{
		printf("%d%c", ans[i], " \n"[i == m]);
	}
	return 0;
}