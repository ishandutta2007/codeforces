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
const int N = 2e2 + 10;
char str[N];
int dp[N][N][N];
int flag[N][N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, tot;
	cin >> n >> tot;
	scanf("%s", str + 1);
	string s;
	cin >> s;
	flag[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		string key = s;
		key.push_back(str[i]);
		sort(key.begin(), key.end());
		key.resize(unique(key.begin(), key.end()) - key.begin());
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= n; k++)
			{
				if (flag[i - 1][j][k] == 0) continue;
				for (auto& c : key)
				{
					dp[i][j + (c == s[0])][k + (c != str[i])] =
						max(dp[i][j + (c == s[0])][k + (c != str[i])],
							dp[i - 1][j][k] + (c == s[1] ? j : 0));
					flag[i][j + (c == s[0])][k + (c != str[i])] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= tot; j++)
		{
			ans = max(ans, dp[n][i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}