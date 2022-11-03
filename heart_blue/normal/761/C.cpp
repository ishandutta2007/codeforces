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
const int N = 2e5 + 10;
int dp[2][8];
int check(char c)
{
	if (isalpha(c)) return 1;
	else if (isdigit(c)) return 2;
	else return 4;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	MEM(dp, 0x3f);
	int o = 0;
	dp[o][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		o ^= 1;
		MEM(dp[o], 0x3f);
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			int s = check(str[j]);
			for (int k = 0; k < 8; k++)
			{
				dp[o][k | s] = min(dp[o][k | s], dp[o ^ 1][k] + min(j, m - j));
			}
		}
	}
	cout << dp[n & 1][7] << endl;
	return 0;
}