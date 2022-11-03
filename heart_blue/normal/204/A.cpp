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
int a[N];
LL dp[N][10][10];
LL dfs(int pos, int s, bool limit, int front)
{
	if (pos == -1)
	{
		return s == front;
	}
	if (!limit && front != 0 && dp[pos][s][front] != -1) return dp[pos][s][front];
	int up = limit ? a[pos] : 9;
	LL ans = 0;
	for (int i = 0; i <= up; i++)
	{
		ans += dfs(pos - 1, i, limit && i == a[pos], front > 0 ? front : i);
	}
	if (!limit && front != 0) dp[pos][s][front] = ans;
	return ans;
}
LL solve(LL x)
{
	int len = 0;
	while (x)
	{
		a[len++] = x % 10;
		x /= 10;
	}
	return dfs(len - 1, 0, true, 0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	LL L, R;
	cin >> L >> R;
	cout << solve(R) - solve(L - 1) << endl;
	return 0;
}