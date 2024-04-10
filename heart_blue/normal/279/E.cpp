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
char str[N];
int dp[N][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 2);
	str[1] = '0';
	int len = strlen(str + 1);
	int last = 1;
	for (int i = 1; i <= len; i++)
	{
		if (str[i] == '1')
			last = i;
	}
	MEM(dp, 0x3f);
	dp[1][0] = 0;
	for (int i = 1; i < last; i++)
	{
		for (int o = 0; o < 2; o++)
		{
			if (str[i] - '0' == o)
			{
				dp[i + 1][o] = min(dp[i + 1][o], dp[i][o]);
				dp[i + 1][o ^ 1] = min(dp[i + 1][o ^ 1], dp[i][o] + 1);
			}
			else
			{
				dp[i + 1][o] = min(dp[i + 1][o], dp[i][o] + 1);
			}
		}
	}
	printf("%d\n", min(dp[last][1], dp[last][0]) + 1);
	return 0;
}