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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N];
int c[N][N];
int dp[10][N];
void init()
{
	for (int i = 0; i < N; i++) c[i][0] = c[i][i] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= INF) c[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = a[9]; i <= n; i++) dp[9][i] = 1;
	for (int o = 8; o >= 0; o--)
	{
		for (int i = a[o]; i <= n; i++)
		{
			for (int j = (o == 0 ? 1 : 0); i + j <= n; j++)
			{
				if (i == 0)
				{
					dp[o][j] = dp[o + 1][j];
					continue;
				}
				if (o != 0) dp[o][i + j] = (dp[o][i + j] + 1LL * c[i + j][j] * dp[o + 1][j]) % INF;
				else dp[o][i + j] = (dp[o][i + j] + 1LL * c[i + j - 1][j - 1] * dp[o + 1][j]) % INF;
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) ans += dp[0][i];
	cout << ans % INF << endl;
	return 0;
}