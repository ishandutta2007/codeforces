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
const int N = 4e4 + 10;
const int M = 5e3 + 10;
const int K = 5e1 + 10;
LL dp[N][K];
LL p[N][K];
int a, b, n;
void init()
{
	MEM(dp, -1);
	for (int i = 1; i < N; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j < K; j++)
		{
			p[i][j] = min(INF, p[i][j - 1] * i);
		}
	}
}
int dfs(int a, int b)
{
	if (dp[a][b] != -1) return dp[a][b];
	if (p[a][b] >= n) return 1;
	if (b == 1 && p[a][b + 1] >= n)
	{
		return dp[a][b] = (n - a - 1) % 2 == 0 ? 2 : 1;
	}
	if (a != 1 && dfs(a, b + 1) == 2)
		return dp[a][b] == 1;
	if (dfs(a + 1, b) == 2 || dfs(a, b + 1) == 2)
		return dp[a][b] = 1;
	return dp[a][b] = 2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	cin >> a >> b >> n;
	if (a == 1 && p[a + 1][b] >= n)
	{
		puts("Missing");
		return 0;
	}
	int res = dfs(a, b);
	if (res == 2) puts("Stas");
	else puts("Masha");
	return 0;
}