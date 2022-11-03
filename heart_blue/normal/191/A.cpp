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
const int N = 3e5 + 10;
int dp[2][26][26];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int o = 0;
	scanf("%d", &n);
	while (n--)
	{
		o ^= 1;
		memcpy(dp[o], dp[o ^ 1], sizeof(dp[o]));
		scanf("%s", str);
		int len = strlen(str);
		int x = str[0] - 'a';
		int y = str[len - 1] - 'a';
		dp[o][x][y] = max(dp[o][x][y], len);
		for (int i = 0; i < 26; i++)
		{
			if (dp[o ^ 1][i][x])
			{
				dp[o][i][y] = max(dp[o][i][y], dp[o ^ 1][i][x] + len);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) ans = max(ans, dp[o][i][i]);
	printf("%d\n", ans);
	return 0;
}