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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL dp[N][11][3];
vector<int> v[N];
int n, m, k, t;
void dfs(int x, int fa = -1)
{
	LL dp2[2][11][3];
	MEM(dp2, 0);
	int o = 0;
	dp2[o][0][0] = k - 1;
	dp2[o][0][1] = 1;
	dp2[o][0][2] = m - k;
	for (auto &y : v[x])
	{
		if (y == fa) continue;
		dfs(y, x);
		o ^= 1;
		MEM(dp2[o], 0);
		for (int i = t; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				dp2[o][i][0] = (dp2[o][i][0] +
					dp2[o ^ 1][i - j][0] * (1LL * dp[y][j][0] + dp[y][j][2] + dp[y][j][1])) % INF;
				dp2[o][i][1] = (dp2[o][i][1] +
					dp2[o ^ 1][i - j][1] * 1LL * dp[y][j][0]) % INF;
				dp2[o][i][2] = (dp2[o][i][2] +
					dp2[o ^ 1][i - j][2] * (1LL * dp[y][j][0] + dp[y][j][2])) % INF;
			}
		}
	}
	for (int i = t; i > 0; i--)
	{
		dp2[o][i][1] = dp2[o][i - 1][1];
	}
	dp2[o][0][1] = 0;
	memcpy(dp[x], dp2[o], sizeof(dp[x]));
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> k >> t;
	dfs(1);
	int ans = 0;
	for (int i = 0; i <= t; i++)
	{
		for (int o = 0; o <= 2; o++)
		{
			ans += dp[1][i][o];
			if (ans >= INF) ans -= INF;
		}
	}
	cout << ans << endl;
	return 0;
}