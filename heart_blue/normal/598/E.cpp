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
const int N = 5e1 + 10;
int flag[N][N][N];
int dp[N][N][N];
int dfs(int n, int m, int k)
{
	if (k == 0) return 0;
	if (n*m == k) return 0;
	if (flag[n][m][k]) return dp[n][m][k];
	if (n*m < k) return INF;
	flag[n][m][k] = 1;
	int &ret = dp[n][m][k] = INF;
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			ret = min(ret, dfs(n, i, j) + dfs(n, m - i, k - j) + n*n);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			ret = min(ret, dfs(i, m, j) + dfs(n - i, m, k - j) + m*m);
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", dfs(n, m, k));
	}
	return 0;
}