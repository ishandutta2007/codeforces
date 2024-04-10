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
const int N = 2e3 + 10;
LL dp[20][11][N];
int cnt[N];
int d[20];
LL dfs(int pos, int s1, int s2, bool lead = true, bool limit = true)
{
	if (lead) s2 = 0;
	if (cnt[s2] > s1) return 0;
	if (pos < 0) return s2 > 0 ? 1 : 0;
	if (!lead && !limit && dp[pos][s1][s2] != -1)
		return dp[pos][s1][s2];
	int up = limit ? d[pos] : 9;
	LL ret = 0;
	for (int i = 0; i <= up; i++)
	{
		ret += dfs(pos - 1, s1, 1 << i | s2, lead && i == 0, limit && i == d[pos]);
	}
	if (!lead && !limit)
		dp[pos][s1][s2] = ret;
	return ret;
}
LL solve(LL x, int k)
{
	int len = 0;
	while (x)
	{
		d[len++] = x % 10;
		x /= 10;
	}
	return dfs(len - 1, k, 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	MEM(dp, -1);
	for (int i = 1; i < N; i++)
	{
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		int cnt = solve(n - 1, k) + 1;
		LL l = n;
		LL r = 1e10;
		LL ans = 0;
		while (l <= r)
		{
			LL mid = (l + r) / 2;
			if (solve(mid, k) >= cnt) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}