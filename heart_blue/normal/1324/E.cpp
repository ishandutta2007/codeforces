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
int dp[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	MEM(dp, 0xdf);
	int o = 0;
	dp[o][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		o ^= 1;
		MEM(dp[o], 0xdf);
		int x;
		cin >> x;
		for (int i = 0; i < h; i++)
		{
			for (int t = -1; t <= 0; t++)
			{
				int cur = (i + x + t) % h;
				int flag = 0;
				if (cur >= l && cur <= r) flag = 1;
				dp[o][cur] = max(dp[o][cur], dp[o ^ 1][i] + flag);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= h; i++)
		ans = max(ans, dp[o][i]);
	cout << ans << endl;
	return 0;
}