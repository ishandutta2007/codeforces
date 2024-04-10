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
const int N = 2e5 + 10;
char str[N];
int dp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int pre[3] = { 0,0,0 };
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		o = (o + str[i] - '0') % 3;
		dp[i] = dp[i - 1];
		if (o == 0) dp[i] = max(dp[i], dp[pre[o]] + 1);
		else
		{
			if (pre[o]) dp[i] = max(dp[i], dp[pre[o]] + 1);
		}
		pre[o] = i;
	}
	cout << dp[n] << endl;
	return 0;
}