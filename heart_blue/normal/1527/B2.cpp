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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][N][2][2];
int dfs(int x, int y, int o1, int o2)
{
	if (dp[x][y][o1][o2] != -1) return dp[x][y][o1][o2];
	int maxv = 0;
	if (y > 0 && o1 == 0)
	{
		maxv = max(maxv, dfs(x, y, 1, o2));
	}
	if (x > 0)
		maxv = max(maxv, dfs(x - 1, y + 1, 0, o2));
	if (y > 0)
		maxv = max(maxv, dfs(x, y - 1, 0, o2));
	if (o2 == 0)
		maxv = max(maxv, dfs(x, y, 0, 1));
	int tot = x * 2 + y + (o2 ^ 1);
	return dp[x][y][o1][o2] = tot - maxv;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	MEM(dp, -1);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		int l = 0, r = n - 1;
		int x = 0;
		int y = 0;
		int o1 = 0;
		int o2 = 1;
		while (l < r)
		{
			if (str[l] == str[r])
			{
				if (str[l] == '0') x++;
			}
			else
			{
				y++;
			}
			l++, r--;
		}
		if (l == r && str[l] == '0')
			o2 = 0;
		int alice = dfs(x, y, o1, o2);
		int bob = x * 2 + y + (o2 ^ 1) - alice;
		if (alice < bob) puts("ALICE");
		else if (alice > bob) puts("BOB");
		else puts("DRAW");
	}
	return 0;
}