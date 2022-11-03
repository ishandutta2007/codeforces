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
const int N = 3e2 + 10;
int dp[N][N][N];
void dfs(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0) return;
	if (dp[r][g][b]) return;
	dp[r][g][b] = 1;
	if (r > 1) dfs(r - 1, g, b);
	if (g > 1) dfs(r, g - 1, b);
	if (b > 1) dfs(r, g, b - 1);
	dfs(r + 1, g - 1, b - 1);
	dfs(r - 1, g + 1, b - 1);
	dfs(r - 1, g - 1, b + 1);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int r, g, b;
	r = g = b = 0;
	int n;
	cin >> n;
	char c;
	while (n--)
	{
		cin >> c;
		if (c == 'R') r++;
		if (c == 'G') g++;
		if (c == 'B') b++;
	}
	MEM(dp, 0);
	dfs(r, g, b);
	if (dp[0][0][1]) putchar('B');
	if (dp[0][1][0]) putchar('G');
	if (dp[1][0][0]) putchar('R');
	return 0;
}