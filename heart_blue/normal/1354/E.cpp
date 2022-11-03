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
const int N = 5e3 + 10;
int dp[N][N];
int pre[N][N];
vector<int> v[N][2], vp[N];
int flag[N];
int key[N];
int ans[N];
void dfs(int x, int k, int o = 0)
{
	if (flag[x] != -1)
	{
		if (flag[x] != o)
			puts("NO"), exit(0);
		return;
	}
	flag[x] = o;
	v[k][o].push_back(x);
	for (auto& y : vp[x])
	{
		dfs(y, k, o ^ 1);
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(pre, -1);
	int n, m;
	scanf("%d%d", &n, &m);
	int n1, n2, n3;
	scanf("%d%d%d", &n1, &n2, &n3);
	vector<int> rest[2];
	for (int i = 0; i < n1; i++) rest[1].push_back(1);
	for (int i = 0; i < n2; i++) rest[0].push_back(2);
	for (int i = 0; i < n3; i++) rest[1].push_back(3);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vp[x].push_back(y);
		vp[y].push_back(x);
	}
	MEM(flag, -1);
	dp[0][0] = 1;
	int tot = 0;
	int tota = 0, totb = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i] != -1) continue;
		dfs(i, i);
		int a = v[i][0].size();
		int b = v[i][1].size();
		int sz = a + b;
		tot += sz;
		key[tot] = i;
		tota += a;
		totb += b;
		for (int j = 0; j <= tot; j++)
		{
			if (j >= a && dp[tot - sz][j - a])
			{
				dp[tot][j] = 1;
				pre[tot][j] = j - a;
			}
			if (j >= b && dp[tot - sz][j - b])
			{
				dp[tot][j] = 1;
				pre[tot][j] = j - b;
			}
		}
	}
	if (dp[tot][n2] == 0)
	{
		puts("NO");
		return 0;
	}
	int cx = tot, cy = n2;
	while (cx > 0)
	{
		int id = key[cx];
		int p = pre[cx][cy];
		int o = 0;
		if (cy - p != v[id][o].size()) o ^= 1;
		for (int i = 0; i < 2; i++)
		{
			for (auto x : v[id][o ^ i])
			{
				ans[x] = rest[i].back();
				rest[i].pop_back();
			}
		}
		cy = p;
		cx -= v[id][0].size() + v[id][1].size();
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		putchar(ans[i] + '0');

	return 0;
}