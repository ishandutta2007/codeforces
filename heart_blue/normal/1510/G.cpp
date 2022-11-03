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
const int N = 1e2 + 10;
tuple<int, int, int> pre[N][N][2];
int dp[N][N][2];
int sz[N];
vector<int> v[N];
int flag[N];
vector<int> ans;
void dfs1(int x, int fa = 0)
{
	dp[x][0][0] = 0;
	dp[x][0][1] = 1;
	sz[x] = 0;
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		dfs1(y, x);
		for (int i = sz[x] + sz[y] + 1; i >= 1; i--)
		{
			for (int j = sz[y]; j >= 0; j--)
			{
				if (i - j - 1 < 0) continue;
				for (int o1 = 0; o1 < 2; o1++)
				{
					for (int o2 = 0; o2 < 2; o2++)
					{
						if (o1 & o2) continue;
						int sum = dp[x][i - j - 1][o1] + dp[y][j][o2] + (o2 ^ 1) + 1;
						if (dp[x][i][o1 | o2] > sum)
						{
							dp[x][i][o1 | o2] = sum;
							pre[x][i][o1 | o2] = { y,j,o2 };
						}
					}
				}
			}
		}
		sz[x] += sz[y] + 1;
	}
}
void dfs2(int x, int s, int o)
{
	if (o == 1) flag[x] = 1;
	else flag[x] = 2;
	while (s > 0)
	{
		auto [y, j, o2] = pre[x][s][o];
		dfs2(y, j, o2);
		s -= j + 1;
		o ^= o2;
	}
}
void dfs3(int x, int fa = 0)
{
	ans.push_back(x);
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (flag[y] == 2) dfs3(y, x);
	}
	for (auto& y : v[x])
	{
		if (y == fa) continue;
		if (flag[y] == 1) dfs3(y, x);
	}
	if (flag[x] == 2)
		ans.push_back(fa);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(dp, 0x3f);
		MEM(flag, 0);
		ans.clear();
		int n, k;
		scanf("%d%d", &n, &k);
		v[1].clear();
		for (int i = 2; i <= n; i++)
		{
			v[i].clear();
			int x;
			scanf("%d", &x);
			v[x].push_back(i);
		}
		dfs1(1);
		dfs2(1, k - 1, 1);
		dfs3(1);
		printf("%d\n", ans.size() - 1);
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	}
	return 0;
}