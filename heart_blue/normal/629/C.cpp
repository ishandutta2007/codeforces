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
const int N = 5e3 + 10;
int dp[N][N];
void init()
{
	MEM(dp, 0);
	dp[0][0] = 1;
	int n = 2001;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j + 1];
			if (j > 0) dp[i][j] += dp[i - 1][j - 1];
			if (dp[i][j] >= INF) dp[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	init();
	int cur = 0;
	int maxv = 0;
	for (auto &c : str)
	{
		if (c == '(') cur++;
		else cur--;
		maxv = max(maxv, -cur);
	}
	int k = n - m;
	LL ans = 0;
	for (int i = 0; i <= k; i++)
	{
		for (int j = maxv; j <= i; j++)
		{
			if (j + cur >= N) break;
			ans += 1LL * dp[i][j] * dp[k - i][j + cur] % INF;
		}
	}
	cout << ans % INF << endl;
	return 0;
}