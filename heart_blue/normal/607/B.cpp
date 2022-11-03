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
const int N = 5e2 + 10;
int dp[N][N];
int flag[N][N];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	MEM(dp, 0);
	MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][i - 1] = dp[i][i] = 1;
		flag[i][i - 1] = flag[i][i] = 1;
	}
	for (int k = 1; k < n; k++)
	{
		for (int i = 1; i + k <= n; i++)
		{
			if (a[i] == a[i + k])
			{
				dp[i][i + k] = dp[i + 1][i + k - 1];
				if (flag[i + 1][i + k - 1])
				{
					flag[i][i + k] = 1;
				}
			}
			else
			{
				dp[i][i + k] = dp[i + 1][i + k - 1] + 2;
			}
			for (int j = i; j < i + k; j++)
			{
				dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}