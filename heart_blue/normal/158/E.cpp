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
const int N = 4e3 + 10;
int dp[N][N];
int a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	fill(dp[0], dp[0] + N, 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = max(dp[i - 1][j], a[i]) + b[i];
			if (j > 0)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		}
	}
	a[n + 1] = 86401;
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, a[i + 1] - dp[i][k]);
	}
	cout << ans << endl;
	return 0;
}