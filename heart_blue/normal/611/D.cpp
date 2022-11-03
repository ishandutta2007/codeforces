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
const int N = 5e3 + 10;
char str[N];
int nex[N][N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0);
	MEM(nex, -1);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n;
		while (l > 0)
		{
			if (str[l] < str[r]) nex[l][r] = l;
			else if (str[l] == str[r]) nex[l][r] = nex[l + 1][r + 1];
			else nex[l][r] = -1;
			l--, r--;
		}
	}
	for (int i = 1; i <= n; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j];
			int r = i - 1;
			int l = max(0, r - (j - i));
			if (str[i] != '0') dp[i][j] += dp[r][r] - dp[l][r];
			if (dp[i][j] < 0) dp[i][j] += INF;
			if (dp[i][j] >= INF) dp[i][j] -= INF;
			if (l != 0)
			{
				if (nex[l][i] == -1 || nex[l][i] >= i) continue;
				if (str[l] == '0' || str[i] == '0') continue;
				dp[i][j] += dp[l][r] - dp[l - 1][r];
				if (dp[i][j] < 0) dp[i][j] += INF;
				if (dp[i][j] >= INF) dp[i][j] -= INF;
			}
		}
	}
	int ans = 0;
	cout << dp[n][n] << endl;
	return 0;
}