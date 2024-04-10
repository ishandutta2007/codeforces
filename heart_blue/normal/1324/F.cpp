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
const int N = 2e5 + 10;
vector<int> v[N];
int w[N];
int ans[N];
int maxv[N];
void dfs1(int x, int p = 0)
{
	maxv[x] = w[x];
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs1(y, x);
		maxv[x] += max(0, maxv[y]);
	}
}
void dfs2(int x, int cur = 0, int p = 0)
{
	cur = max(cur, 0);
	ans[x] = cur + maxv[x];
	for (auto& y : v[x])
	{
		if (y == p) continue;
		dfs2(y, ans[x] - max(maxv[y], 0), x);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
		if (w[i] == 0)
			w[i] = -1;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}