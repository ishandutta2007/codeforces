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
const int N = 1e2 + 10;
int dp[N][4][4];
int a[N][10];
int dfs(int l1, int r1, int l2, int r2)
{
	int l = min(l1, l2);
	int r = max(r1, r2);
	int o1 = 0, o2 = 0;
	if (l != l1) o1 |= 1;
	if (r != r1) o1 |= 2;
	if (l != l2) o2 |= 1;
	if (r != r2) o2 |= 2;
	int len = (r - l + 1);
	if (len <= 0) return 0;
	if (dp[len][o1][o2] != -1)
		return dp[len][o1][o2];
	vector<int> flag(200, 0);
	for (int i = l1; i <= r1; i++)
	{
		flag[dfs(l1, i - 1, l2, i - 2) ^ dfs(i + 1, r1, i + 2, r2)] = 1;
	}
	for (int i = l2; i <= r2; i++)
	{
		flag[dfs(l1, i - 2, l2, i - 1) ^ dfs(i + 2, r1, i + 1, r2)] = 1;
	}
	int ret = 0;
	for (int i = 0; i < flag.size(); i++)
	{
		if (flag[i] == 0)
		{
			ret = i;
			break;
		}
	}
	return dp[len][o1][o2] = ret;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i][1] + a[i][2] > 0) continue;
		int j = i;
		while (j <= n && a[j][1] + a[j][2] == 0)
			j++;
		j--;
		int l1 = i, l2 = i;
		int r1 = j, r2 = j;
		if (i > 1)
		{
			if (a[i - 1][1] == 1) l2++;
			else l1++;
		}
		if (j < n)
		{
			if (a[j + 1][1] == 1) r2--;
			else r1--;
		}
		ans ^= dfs(l1, r1, l2, r2);
		i = j;
	}
	if (ans)
		puts("WIN");
	else
		puts("LOSE");
	return 0;
}