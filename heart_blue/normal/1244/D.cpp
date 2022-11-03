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
vector<int> v[N];
int c[4][N];
int n;
vector<pair<int, int>> tmp;
vector<pair<int, int>> ans;
LL res = INF * INF;
void dfs(int x, int fa, int o1, int o2, LL sum)
{
	if (sum >= res) return;
	if (tmp.size() == n)
	{
		res = sum;
		ans = tmp;
		return;
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		int o = o1 ^ o2;
		tmp.emplace_back(y, o);
		dfs(y, x, o, o1, sum + c[o][y]);
		tmp.pop_back();
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int o = 1; o <= 3; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &c[o][i]);
		}
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	int key = 0;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 1) key = i;
		if (deg[i] > 2) puts("-1"), exit(0);
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (i == j) continue;
			tmp.emplace_back(key, i);
			dfs(key, 0, i, j, c[i][key]);
			tmp.pop_back();
		}
	}
	sort(ans.begin(), ans.end());
	printf("%lld\n", res);
	for (auto& p : ans)
		printf("%d ", p.second);
	return 0;
}