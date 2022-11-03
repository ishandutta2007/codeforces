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
int val[N][2];
LL dp[N][2];
vector<int> v[N];
void dfs(int x, int fa = 0)
{
	dp[x][0] = dp[x][1] = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		for (int i = 0; i < 2; i++)
		{
			LL maxv = 0;
			for (int j = 0; j < 2; j++)
			{
				maxv = max(maxv, dp[y][j] + abs(val[x][i] - val[y][j]));
			}
			dp[x][i] += maxv;
		}
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
		{
			scanf("%d%d", &val[i][0], &val[i][1]);
		}
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		printf("%lld\n", max(dp[1][0], dp[1][1]));
	}
	return 0;
}