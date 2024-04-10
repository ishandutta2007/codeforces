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
const int N = 2e3 + 10;
int dp[N][N];
int pre[N][N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", str + 1);
	dp[0][k] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < 2 * k; j++)
		{
			if (dp[i][j] == 0) continue;
			if (str[i + 1] == '?' || str[i + 1] == 'L')
				dp[i + 1][j - 1] = 1, pre[i + 1][j - 1] = j;
			if (str[i + 1] == '?' || str[i + 1] == 'D')
				dp[i + 1][j] = 1, pre[i + 1][j] = j;
			if (str[i + 1] == '?' || str[i + 1] == 'W')
				dp[i + 1][j + 1] = 1, pre[i + 1][j + 1] = j;
		}
	}
	if (pre[n][0] == 0 && pre[n][2 * k] == 0)
	{
		puts("NO");
		return 0;
	}
	int o = 0;
	if (dp[n][2 * k]) o = 2 * k;
	for (int i = n; i >= 1; i--)
	{
		int t = pre[i][o];
		if (t < o) str[i] = 'W';
		if (t == o) str[i] = 'D';
		if (t > o) str[i] = 'L';
		o = t;
	}
	puts(str + 1);
	return 0;
}