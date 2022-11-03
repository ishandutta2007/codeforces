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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e4 + 10;
const int M = 5e2 + 10;
LL ans = 0;
int dp[N][M];
vector<int> v[N];
int n, k;
void dfs(int x, int fa = -1)
{
	MEM(dp[x], 0);
	dp[x][0] = 1;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		ans += dp[y][k];
		for (int i = 1; i < k; i++)
		{
 			ans += LL(dp[x][i])*dp[y][k - i];
 		}
		for (int i = 1; i <= k; i++) dp[x][i] += dp[y][i];
	}
	for (int i = k; i > 0; i--) dp[x][i] = dp[x][i - 1];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}