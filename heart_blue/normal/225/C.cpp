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
const int N = 1e3 + 10;
int dp[N][N][2];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x1f);
	int inf = dp[0][0][0];
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	MEM(a, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if (c == '#') a[j]++;
		}
	}
	dp[0][0][1] = 0;
	dp[0][0][0] = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			dp[i + 1][j + 1][0] = min(dp[i + 1][j + 1][0], dp[i][j][0] + a[i + 1]);
			dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][1] + n - a[i + 1]);
			if (j >= x) dp[i + 1][1][0] = min(dp[i + 1][1][0], dp[i][j][1] + a[i + 1]);
			if (j >= x)dp[i + 1][1][1] = min(dp[i + 1][1][1], dp[i][j][0] + n - a[i + 1]);
		}
	}
	int ans = inf;
	for (int i = x; i <= y; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			ans = min(ans, dp[m][i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}