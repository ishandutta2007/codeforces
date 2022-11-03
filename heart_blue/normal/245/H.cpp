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
const int N = 5e3 + 10;
int dp[N][N];
int flag[N][N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(dp, 0);
	MEM(flag, 0);
	int n;
	scanf("%s%d", str + 1, &n);
	int a, b;
	int l = strlen(str + 1);
	for (int i = 1; i <= l; i++)
	{
		dp[i][i] = 1;
		flag[i][i] = 1;
		flag[i][i - 1] = 1;
	}
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j + i <= l; j++)
		{
			dp[j][j + i] = dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][i + j - 1];
			if (str[j] == str[j + i] && flag[j + 1][i + j - 1])
			{
				dp[j][j + i] ++;
				flag[j][j + i] = 1;
			}
		}
	}
	while (n--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", dp[a][b]);
	}
	return 0;
}