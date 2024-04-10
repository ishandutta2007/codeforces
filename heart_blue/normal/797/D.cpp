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
const int N = 1e5 + 10;
int sons[N][2];
int deg[N];
int val[N];
map<int, int> mc;
void dfs(int x, int l, int r)
{
	if (x == 0) return;
	if (l <= val[x] && val[x] <= r) mc[val[x]] = 1;
	dfs(sons[x][0], l, min(r, val[x] - 1));
	dfs(sons[x][1], max(l, val[x] + 1), r);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		for (int o = 0; o < 2; o++)
		{
			int x;
			scanf("%d", &x);
			if (x != -1)
			{
				deg[x]++;
				sons[i][o] = x;
			}
		}
	}
	int rt = 1;
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0)
			rt = i;
	}
	dfs(rt, -INF, INF);
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		ans -= mc[val[i]];
	}
	printf("%d\n", ans);
	return 0;
}