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
const int N = 5e2 + 10;
LL dp[N][N];
int d[N];
int k = 0;
LL dfs(int pos, int s, bool limit = true, bool lead = true)
{
	if (pos == -1)
	{
		return s == k ? 1 : 0;
	}
	if (!limit && !lead && dp[pos][s] != -1) return dp[pos][s];
	int up = limit ? d[pos] : 1;
	LL ret = 0;
	for (int i = 0; i <= up; i++)
	{
		ret += dfs(pos - 1, s + i, limit && i == d[pos], lead && i == 0);
	}
	if (!limit && !lead) dp[pos][s] = ret;
	return ret;
}
LL solve(LL n)
{
	int len = 0;
	while (n)
	{
		d[len++] = n & 1;
		n >>= 1;
	}
	return dfs(len - 1, 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	LL n, t;
	cin >> n >> t;
	while (t > 1)
	{
		k++;
		if (t & 1)
		{
			puts("0");
			return 0;
		}
		t >>= 1;
	}
	n++;
	k++;
	printf("%lld\n", solve(n) - solve(1));
	return 0;
}