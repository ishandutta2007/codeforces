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
const int N = 3e2 + 10;
int dp2[N][N];
int dfs2(int x, int y)
{
	if (x + y == 0) return 0;
	if (x == y) return 1;
	if (x * y == 0) return 1;
	if (dp2[x][y] >= 0) return dp2[x][y];
	for (int i = 0; i < x; i++)
	{
		if (dfs2(i, y) == 0)
		{
			return dp2[x][y] = 1;
		}
	}
	for (int i = 0; i < y; i++)
	{
		if (dfs2(x, i) == 0)
		{
			return dp2[x][y] = 1;
		}
	}
	for (int i = min(x, y); i > 0; i--)
	{
		if (dfs2(x - i, y - i) == 0)
		{
			return dp2[x][y] = 1;
		}
	}
	return dp2[x][y] = 0;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	MEM(dp2, -1);
	int n;
	cin >> n;
	int a[3];
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1)
	{
		if (a[0]) puts("BitLGM");
		else puts("BitAryo");
		return 0;
	}
	if (n == 2)
	{
		if (dfs2(a[0], a[1])) puts("BitLGM");
		else puts("BitAryo");
	}
	if (n == 3)
	{
		if (a[0] ^ a[1] ^ a[2]) puts("BitLGM");
		else puts("BitAryo");
	}

	return 0;
}