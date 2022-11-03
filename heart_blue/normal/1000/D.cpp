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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
const int MOD = 998244353;
int a[N][N];
int dp[N];
int sum[N];
int b[N];
void init()
{
	for (int i = 0; i < N; i++) a[i][0] = a[i][i] = 1;
	for (int i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			if (a[i][j] >= MOD)
				a[i][j] -= MOD;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	dp[0] = 1;
	sum[0] = 1;
	int n;
	int ans = 0;
	init();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		for (int j = 1; j < i; j++)
		{
			if (b[j] <= 0) continue;
			if (b[j] >= N) continue;
			dp[i] = (dp[i] + 1LL * a[i - j - 1][b[j] - 1] * sum[j - 1]) % MOD;
		}
		ans += dp[i];
		if (ans >= MOD) ans -= MOD;
		sum[i] = sum[i - 1] + dp[i];
		if (sum[i] >= MOD) sum[i] -= MOD;
	}
	printf("%d\n", ans);
	return 0;
}