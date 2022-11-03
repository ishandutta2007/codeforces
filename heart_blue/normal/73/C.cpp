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
const int N = 1e2 + 30;
int w[N][N];
int dp[N][N][N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int k;
	scanf("%d", &k);
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char c1, c2;
		int val;
		scanf(" %c %c %d", &c1, &c2, &val);
		w[c1][c2] = val;
	}
	MEM(dp, 0xaf);
	for (int i = 'a'; i <= 'z'; i++)
	{
		dp[1][i != str[1]][i] = 0;
	}
	n = strlen(str + 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int c1 = 'a'; c1 <= 'z'; c1++)
			{
				for (int c2 = 'a'; c2 <= 'z'; c2++)
				{
					int o = j + (c2 != str[i + 1]);
					if (o > k) continue;
					dp[i + 1][o][c2] = max(dp[i + 1][o][c2], dp[i][j][c1] + w[c1][c2]);
				}
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 'a'; j <= 'z'; j++)
			ans = max(ans, dp[n][i][j]);
	}
	cout << ans << endl;
	return 0;
}