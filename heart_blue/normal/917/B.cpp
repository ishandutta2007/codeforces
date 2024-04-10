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
const int N = 2e2 + 10;
vector<pair<int, char>> v[N];
int dp[N][N][N];
int dfs(int x, int y, char c)
{
	if (dp[x][y][c] >= 0) return dp[x][y][c];
	int &ret = dp[x][y][c] = 0;
	for (auto &p : v[x])
	{
		int to;
		char w;
		tie(to, w) = p;
		if (w < c) continue;
		if (dfs(y, to, w) == 0)
		{
			ret = 1;
			break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, -1);
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int x, y;
		char c;
		cin >> x >> y >> c;
		v[x].push_back({ y,c });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			putchar("BA"[dfs(i, j, 0)]);
		}
		puts("");
	}
	return 0;
}