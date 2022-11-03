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
const int N = 2e3 + 10;
int a[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x > k)
		{
			cout << 0 << endl;
			return 0;
		}
		x = k - x;
		if (x == 0)
		{
			dp[i][0] = dp[i - 1][0];
			continue;
		}
		dp[i][x] = (dp[i - 1][x] + dp[i - 1][x - 1]) % INF;
		dp[i][x - 1] = (1LL * x*dp[i][x]) % INF;
	}
	cout << dp[n][0] << endl;
	return 0;
}