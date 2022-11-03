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
const int N = 1e5 + 10;
vector<int> v[N];
int fa[N];
int dis[N];
void dfs1(int x, int p = 0)
{
	fa[x] = p;
	dis[x] = dis[p] + 1;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs1(y, x);
	}
}
void solve(int& rt, int n)
{
	dfs1(rt);
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] >= dis[rt])
			rt = i;
	}
}
void check(int x, int rest, int p = 0)
{
	int sz = 0;
	for (auto& y : v[x])
	{
		if (y == p) continue;
		sz++;
		check(y, rest - 1, x);
	}
	if (rest > 0 && sz < 3) puts("NO"), exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int rt = 1;
	solve(rt, n);
	solve(rt, n);
	int len = dis[rt] - 1;
	if (len % 2 == 1 || len / 2 != k)
	{
		puts("NO");
		return 0;
	}
	len /= 2;
	for (int i = 0; i < len; i++)
		rt = fa[rt];
	check(rt, len);
	puts("YES");
	return 0;
}