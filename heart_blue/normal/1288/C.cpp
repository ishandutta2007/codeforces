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
const int N = 1e3 + 10;
LL dp[2][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	dp[0][n - 1] = 1;
	int o = 0;
	while (m--)
	{
		o ^= 1;
		MEM(dp[o], 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				dp[o][i] += 1LL * dp[o ^ 1][j] * (j - i + 1) % INF;
			}
			dp[o][i] %= INF;
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++) ans += dp[o][i];
	cout << ans % INF << endl;
	return 0;
}