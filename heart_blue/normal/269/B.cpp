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
int a[N];
int b[N];
int dp[N][N];
int solve(int n)
{
	MEM(dp, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}
	return n - dp[n][n];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%*f", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	cout << solve(n) << endl;
	return 0;
}