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
const int N = 1e5 + 10;
vector<int> v[N];
int dfn[N];
int low[N];
int cnt = 0;
vector<pair<int, int>> ans;
map<pair<int, int>, int> mc;
void add(int x, int y)
{
	if (mc.count({ x,y })) return;
	mc[{x, y}] = 1;
	mc[{y, x}] = 1;
	ans.emplace_back(x, y);
}
void dfs(int x, int fa = 0)
{
	dfn[x] = low[x] = ++cnt;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		add(x, y);
		if (dfn[y]) low[x] = min(low[x], dfn[y]);
		else
		{
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (dfn[x] < low[y])
			{
				puts("0");
				exit(0);
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	//cerr << endl;
	for (auto& [x, y] : ans)
	{
		printf("%d %d\n", x, y);
	}
	return 0;
}