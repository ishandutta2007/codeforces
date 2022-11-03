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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tot;
	scanf("%d", &tot);
	int n = 0, m = 0;
	for (int i = 1; i <= tot; i++)
	{
		int x;
		scanf("%d", &x);
		if (x == 1) a[++n] = i;
		else b[++m] = i;
	}
	MEM(dp, 0x3f);
	MEM(dp[0], 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + abs(a[i] - b[j]);
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[n][m]);
	
	return 0;
}