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
const int N = 2e3 + 10;
const int MOD = 998244353;
int o[4][4] = { 0,1,1,1,
			0,0,2,0,
			0,2,0,0,
			1,1,1,0 };
int dp[N][N][4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	dp[1][1][0] = 1;
	dp[1][2][1] = dp[1][2][2] = 1;
	dp[1][1][3] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= 2 * i; j++)
		{
			for (int o1 = 0; o1 < 4; o1++)
			{
				if (dp[i][j][o1] == 0) continue;
				for (int o2 = 0; o2 < 4; o2++)
				{
					int& tmp = dp[i + 1][j + o[o1][o2]][o2] += dp[i][j][o1];
					if (tmp >= MOD)
						tmp -= MOD;
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i < 4; i++)
	{
		ans += dp[n][k][i];
	}
	cout << ans % MOD << endl;
	return 0;
}