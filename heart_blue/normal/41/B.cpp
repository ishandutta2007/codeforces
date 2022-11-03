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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(dp, 0xaf);
	dp[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = x; j <= m; j++)
		{
			if (dp[j - x] >= 0)
			{
				dp[j] = max(dp[j - x] + 1, dp[j]);
			}
		}
		for (int i = 0; i <= m; i++)
		{
			if (dp[i] >= 0) ans = max(ans, m - i + dp[i] * x);
		}
	}
	cout << ans << endl;
	return 0;
}