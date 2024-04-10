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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int pos[200];
char str[N];
int a[N];
LL dp[N][5];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	pos['h'] = 1;
	pos['a'] = 2;
	pos['r'] = 3;
	pos['d'] = 4;
	MEM(dp, 0x3f);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			dp[i][j] = dp[i - 1][j] + a[i];
		}
		for (int j = 0; j < 4; j++)
		{
			int o = (j + 1 == pos[str[i]] ? pos[str[i]] : j);
			dp[i][o] = min(dp[i][o], dp[i - 1][j]);
		}
	}
	cout << min({ dp[n][0],dp[n][1],dp[n][2],dp[n][3] }) << endl;
	return 0;
}