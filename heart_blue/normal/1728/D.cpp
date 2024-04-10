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
char str[N];
int check(int o, char a, char b)
{
	if (o != 0) return o;
	if (a > b) return 1;
	else if (a == b) return 0;
	else return -1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%s", str + 1);
		int n = strlen(str + 1);
		for (int i = n - 1; i >= 1; i--)
		{
			if (str[i] == str[i + 1]) dp[i][i + 1] = 0;
			else dp[i][i + 1] = 1;
			for (int j = i + 3; j <= n; j += 2)
			{
				char a = str[i], b = str[i + 1], c = str[j - 1], d = str[j];
				int minv1 = min(check(dp[i + 1][j - 1], a, d), check(dp[i + 2][j], a, b));
				int minv2 = min(check(dp[i + 1][j - 1], d, a), check(dp[i][j - 2], d, c));
				dp[i][j] = max(minv1, minv2);
			}
		}
		if (dp[1][n] == 1) puts("Alice");
		else if (dp[1][n] == 0) puts("Draw");
		else puts("Bob");
	}
	return 0;
}