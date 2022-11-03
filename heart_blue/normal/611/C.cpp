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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char chess[N][N];
int dp1[N][N];
int dp2[N][N];

int getans(int r1, int c1, int r2, int c2, int dp[N][N])
{
	if (r1 > r2) return 0;
	if (c1 > c2) return 0;
	return dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp1, 0);
	MEM(dp2, 0);
	MEM(chess, '#');
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		getchar();
		for (int j = 1; j <= m; j++)
		{
			chess[i][j] = getchar();
			dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1] - dp1[i - 1][j - 1];
			dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
			if (chess[i][j] == '#') continue;
			if (chess[i][j - 1] == '.')
			{
				dp1[i][j]++;
			}
			if (chess[i - 1][j] == '.')
			{
				dp2[i][j]++;
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int r1, r2, c1, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		printf("%d\n", getans(r1, c1 + 1, r2, c2, dp1) + getans(r1 + 1, c1, r2, c2, dp2));
	}
	return 0;
}