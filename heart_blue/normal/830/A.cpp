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
int dp[N][N];
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0x7f);
	int n, k, p;
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) cin >> b[i];
	MEM(dp[0], 0);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= k; j++)
		{
			dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - p)));
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}