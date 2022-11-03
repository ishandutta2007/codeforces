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
const int N = 1e5;
int dp[2][N * 2 + 10];
int a[N * 2 + 10];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int ans = 0;
	int o = 0;
	MEM(dp, 0);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		o ^= 1;
		MEM(dp[o], 0);
		sum += x;
		for (int j = -sum; j + x <= sum; j++)
		{
			j += N;
			dp[o][j] += dp[o ^ 1][j + x];
			if (dp[o][j] >= INF) dp[o][j] -= INF;
			j -= N;
		}
		for (int j = sum; j - x >= -sum; j--)
		{
			j += N;
			dp[o][j] += dp[o ^ 1][j - x];
			if (dp[o][j] >= INF) dp[o][j] -= INF;
			j -= N;
		}
		ans += dp[o][N];
		if (ans >= INF) ans -= INF;
		dp[o][N - x]++;
		dp[o][N + x]++;
	}
	printf("%d\n", ans);


	return 0;
}