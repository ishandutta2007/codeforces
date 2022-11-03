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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int pre1[N][N];
int pre2[N][N];
int dp[N][N];
int a[N][N];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
string oxy = "RD";
char str[2 * N];
inline int check(int o, int x)
{
	int ret = 0;
	while (o % x == 0)
	{
		ret++;
		o /= x;
	}
	return ret;
}
int solve(int n, int x, int pre[N][N])
{
	pre[1][1] = -1;
	for (int i = 0; i <= n; i++) dp[i][0] = dp[0][i] = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = check(a[i][j], x);
			if (i == 1 && j == 1) continue;
			if (dp[i][j - 1] > dp[i - 1][j]) dp[i][j] += dp[i - 1][j], pre[i][j] = 1;
			else dp[i][j] += dp[i][j - 1], pre[i][j] = 0;
			
		}
	}
	return dp[n][n];
}
void output(int n, int pre[N][N])
{
	int x = n, y = n;
	int k = n * 2 - 2;
	str[k] = 0;
	while (pre[x][y] != -1)
	{
		assert(k >= 0);
		int o = pre[x][y];
		str[--k] = (oxy[o]);
		x -= dx[o];
		y -= dy[o];
	}
	puts(str);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	int flag = 0;
	int x = -1, y = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0)
			{
				x = i, y = j;
				a[i][j] = 10;
			}
		}
	}
	int ans2 = solve(n, 2, pre1);
	int ans5 = solve(n, 5, pre2);
	int ans = min(ans2, ans5);
	if (x != -1 && ans != 0)
	{
		cout << 1 << endl;
		cout << string(x - 1, 'D');
		cout << string(n - 1, 'R');
		cout << string(n - x, 'D') << endl;
		return 0;
	}
	printf("%d\n", min(ans2, ans5));
	if (ans2 < ans5) output(n, pre1);
	else output(n, pre2);
	return 0;
}