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
const int N = 1e3 + 10;
double dp[N][N][2];
double dfs(int x, int y, int o)
{
	if (x <= 0 && y <= 0) return 0;
	if (y <= 0)
	{
		if (o == 0) return 1;
		else return 0;
	}
	if (x <= 0) return 0;
	if (dp[x][y][o] >= 0) return dp[x][y][o];
	double &ret = dp[x][y][o] = 0;
	if (o == 0)
	{
		ret = 1.0*x / (x + y) + 1.0*y / (x + y)*dfs(x, y - 1, o ^ 1);
	}
	else
	{
		if (x + y == 2) return 0;
		ret = 1.0*y / (x + y)*
			((y - 1.0) / (x + y - 1)*dfs(x, y - 2, o ^ 1) + 
				1.0*x / (x + y - 1)*dfs(x - 1, y - 1, o ^ 1));
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	printf("%.15f\n", dfs(n, m, 0));
	return 0;
}