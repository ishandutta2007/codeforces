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
const int N = 1e6 + 10;
int dp[N][10];
string str = "0121*";
int flag[5][5] =
{
	1,0,0,1,0,
	1,0,0,1,0,
	0,0,0,0,1,
	0,0,0,0,1,
	0,1,1,0,1
};
inline bool check(char x, char y)
{
	return x == y || x == '?';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	if (check(s[0], '0')) dp[0][0] = 1;
	if (check(s[0], '1')) dp[0][3] = 1;
	if (check(s[0], '*')) dp[0][4] = 1;
	if (n == 1) dp[0][3] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (!check(s[i - 1], str[j])) continue;
			for (int k = 0; k < 5; k++)
			{
				if (!check(s[i], str[k])) continue;
				if (flag[j][k] == 0) continue;
				dp[i][k] += dp[i - 1][j];
				if (dp[i][k] >= INF) dp[i][k] -= INF;
			}
		}
	}
	int ans = 0;
	dp[n - 1][2] = 0, dp[n - 1][3] = 0;
	for (int i = 0; i < 5; i++)
	{
		ans += dp[n - 1][i];
		if (ans >= INF) ans -= INF;
	}
	cout << ans << endl;
	return 0;
}