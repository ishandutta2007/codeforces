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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
LL dp[2][N*2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int o = 0;
	MEM(dp, 0x3f);
	dp[0][N] = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, c;
		cin >> t >> c;
		o ^= 1;
		MEM(dp[o], 0x3f);

		for (int j = n; j >= -n + t; j--)
		{
			dp[o][j+N] = min(dp[o][j + N], dp[o ^ 1][j + N - t] + c);
		}
		if (t >= n)
		{
			for (int j = -n; j <= n; j++)
			{
				dp[o][j + N] = min({ dp[o][j + N],dp[o][j + N - 1],dp[o ^ 1][j + N - 1] + c });
			}
		}
		for (int j = n; j >= -n; j--)
		{
			dp[o][j + N] = min({ dp[o][j + N + 1], dp[o][j + N],dp[o ^ 1][j + N + 1] });
		}
	}
	LL ans = INF * INF;
	//for (int i = 0; i < N*2; i++) ans = min(ans, dp[o][i]);
	cout << dp[o][N] << endl;
	return 0;
}