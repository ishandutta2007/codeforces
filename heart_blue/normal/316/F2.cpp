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
#include <regex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1.6e3 + 10;
int s1[N][N];
int s2[N][N];
int belong[N][N];
int cnt[N][N];
int cur = 0;
int n, m;
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { 0,-1,1,0,-1,1,1,-1 };
int ans[N * N];
void dfs(int x, int y)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > m) return;
	if (s1[x][y] == 0) return;
	if (belong[x][y]) return;
	belong[x][y] = cur;
	for (int i = 0; i < 8; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
void refrain(int l, int r)
{
	MEM(cnt, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int o = 0; o < 8; o++)
			{
				cnt[i][j] += s2[i + dx[o]][j + dy[o]] == 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cnt[i][j] >= l && cnt[i][j] <= r) s2[i][j] = 1;
			else s2[i][j] = 0;
		}
	}
}
void solve(int x, int y, int key)
{
	if (x < 1 || x > n) return;
	if (y < 1 || y > m) return;
	if (belong[x][y] != key) return;
	if (s1[x][y] == 0) return;
	if (s1[x][y] == 1 && s2[x][y] == 1) return;
	s1[x][y] = 0;
	for (int i = 0; i < 8; i++)
	{
		solve(x + dx[i], y + dy[i], key);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &s1[i][j]);
		}
	}

	memcpy(s2, s1, sizeof(s1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i][j] == 0 || belong[i][j]) continue;
			cur++;
			dfs(i, j);
		}
	}
	for (int i = 1; i <= 2; i++) refrain(8, 8);
	for (int i = 1; i <= 3; i++) refrain(1, 8);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i][j] == 1 && s2[i][j] == 0)
			{
				ans[belong[i][j]]++;
				solve(i, j, belong[i][j]);
			}
		}
	}
	printf("%d\n", cur);
	sort(ans + 1, ans + cur + 1);
	for (int i = 1; i <= cur; i++)
		printf("%d ", ans[i]);
	return 0;
}