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
const int N = 2e2 + 10;
int a[N];
int dp[N][2];
int flag[N][2];
int n;
int dfs(int x, int o)
{
	if (x > n) return 0;
	if (flag[x][o]) return dp[x][o];
	flag[x][o] = 1;
	if (o == 0)
	{
		dp[x][o] = max(dfs(x + 1, o ^ 1) + a[x], dfs(x + 1, o) - a[x]);
	}
	else
	{
		dp[x][o] = min(dfs(x + 1, o ^ 1) - a[x], dfs(x + 1, o) + a[x]);
	}
	return dp[x][o];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	MEM(flag, 0);
	int sub = dfs(1, 1);
	cout << (sum + sub) / 2 << ' ' << (sum - sub) / 2 << endl;
	return 0;
}