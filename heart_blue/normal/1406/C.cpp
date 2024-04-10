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
typedef long long ll;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int ans[N];
vector<int> v[N];
int deg[N];
int flag[N];
int sons[N];
int n;
void dfs1(int x, int p = 0)
{
	ans[x] = 0;
	sons[x] = 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs1(y, x);
		sons[x] += sons[y];
		ans[x] = max(ans[x], sons[y]);
	}
	ans[x] = max(ans[x], n - sons[x]);
}
void dfs2(int x, int p = 0)
{
	flag[x] = 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs2(y, x);
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
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) deg[i] = 0;
		for (int i = 1; i <= n; i++) flag[i] = 0;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
			deg[x] ++;
			deg[y]++;
		}
		dfs1(1);
		int minv = INF;
		for (int i = 1; i <= n; i++) minv = min(minv, ans[i]);
		vector<int> key;
		for (int i = 1; i <= n; i++)
		{
			if (minv == ans[i])
				key.push_back(i);
		}
		if (key.size() == 1)
		{
			printf("%d %d\n", 1, v[1][0]);
			printf("%d %d\n", 1, v[1][0]);
			continue;
		}
		dfs2(key[1], key[0]);
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (flag[i] && deg[i] == 1)
			{
				res = i;
				break;
			}
		}
		printf("%d %d\n", res, v[res][0]);
		printf("%d %d\n", res, key[0]);
	}
	return 0;
}