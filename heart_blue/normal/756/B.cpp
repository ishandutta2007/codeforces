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
const int N = 1e5 + 10;
int dp[N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	a[0] = dp[0] = 0;
	int b[3] = { 1,90,1440 };
	int cost[3] = { 20,50,120 };
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 20;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 20;
		int sum = 0;
		for (int j = i - 1; j > 0; j--)
		{
			if (a[i] - a[j] >= 1440) break;
			sum += dp[j];
			for (int o = 0; o < 3; o++)
			{
				if (a[i] - a[j] >= b[o]) continue;
				dp[i] = min(dp[i], cost[o] - sum);
			}
		}
		dp[i] = max(0, dp[i]);
	}
	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';

	return 0;
}