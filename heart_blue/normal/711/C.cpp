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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int a[N][N];
int b[N];
LL dp[2][N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (b[i] != 0) a[i][j] = 0;
		}
	}
	MEM(dp, 0x1f);
	LL inf = dp[0][0][0];
	for (int i = 1; i <= m; i++)
	{
		if (b[1] == i || b[1] == 0)	dp[0][1][i] = a[1][i];
	}
	int o = 0;
	for (int i = 2; i <= n; i++)
	{
		o ^= 1;
		MEM(dp[o], 0x1f);
		for (int j = 1; j < i; j++)
		{
			if (b[i] != 0)
			{
				for (int t = 1; t <= m; t++)
				{
					LL &tmp = dp[o][j + (b[i] != t)][b[i]];
					tmp = min(tmp, dp[o ^ 1][j][t]);
				}
			}
			else
			{
				for (int s = 1; s <= m; s++)
				{
					for (int t = 1; t <= m; t++)
					{
						LL &tmp = dp[o][j + (s != t)][s];
						tmp = min(tmp, dp[o ^ 1][j][t] + a[i][s]);
					}
				}
			}
		}
	}
	LL ans = inf;
	for (int i = 1; i <= m; i++) ans = min(ans, dp[o][k][i]);
	if (ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}