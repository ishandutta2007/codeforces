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
const int N = 4e3 + 10;
LL dp[N][N];
LL c[N][N];
void init()
{
	dp[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
			dp[i][j] %= INF;
		}
	}
	for (int i = 0; i < N; i++) c[i][i] = c[i][0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= INF) c[i][j] -= INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	LL ans = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			ans += dp[i][j] * c[n][i] % INF;
			if (ans >= INF) ans -= INF;
		}
	}
	cout << ans << endl;
	return 0;
}