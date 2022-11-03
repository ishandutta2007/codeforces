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
const int N = 2e5 + 10;
int a[N];
int b[N];
int c[N];
int dp[N][4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n == 1)
	{
		cout << a[1] << endl;
		return 0;
	}
	MEM(dp, 0);
	dp[1][0] = a[1];
	dp[1][1] = 0;
	dp[1][2] = b[1];
	dp[1][3] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] += max(dp[i - 1][2], dp[i - 1][3]) + a[i];
		dp[i][1] += max(dp[i - 1][1], dp[i - 1][0]) + b[i];
		dp[i][2] += max(dp[i - 1][2], dp[i - 1][3]) + b[i];
		dp[i][3] += max(dp[i - 1][1], dp[i - 1][0]) + c[i];
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	return 0;
}