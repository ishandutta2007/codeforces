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
const int N = 2e5 + 10;
int dp[N][2];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	dp[1][0] = 0;
	dp[1][1] = c;
	for (int i = 1; i < n; i++)
	{
		dp[i + 1][0] = min(dp[i][0], dp[i][1]) + a[i];
		dp[i + 1][1] = min(dp[i][0] + b[i] + c, dp[i][1] + b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d%c", min(dp[i][0], dp[i][1]), " \n"[i == n]);
	}
	return 0;
}