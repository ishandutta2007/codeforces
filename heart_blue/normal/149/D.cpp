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
const int N = 7e2 + 10;
char str[N];
int dp[N][N][3][3];
int flag[N][N];
int key[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for (int i = 1; i < n; i++)
	{
		if (str[i] == '(' && str[i + 1] == ')')
		{
			flag[i][i + 1] = 1;
			dp[i][i + 1][0][1] = dp[i][i + 1][0][2] = 1;
			dp[i][i + 1][1][0] = dp[i][i + 1][2][0] = 1;
			key[i + 1] = i;
		}
	}
	for (int len = 3; len <= n; len += 2)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int l = i, r = i + len;
			if (!(str[l] == '(' && str[r] == ')')) continue;
			if (flag[l + 1][r - 1])
			{
				key[r] = l;
				flag[l][r] = 1;
				for (int o1 = 0; o1 < 3; o1++)
				{
					for (int o2 = 0; o2 < 3; o2++)
					{
						if (o1 == 0 && o2 == 0) continue;
						if (o1 * o2 > 0) continue;
						for (int o3 = 0; o3 < 3; o3++)
						{
							if (o1 == o3 && o1 > 0) continue;
							for (int o4 = 0; o4 < 3; o4++)
							{
								if (o2 == o4 && o2 > 0) continue;
								int &tmp = dp[l][r][o1][o2] += dp[l + 1][r - 1][o3][o4];
								if (tmp >= INF)
									tmp -= INF;
							}
						}
					}
				}
			}
			if (key[r] == 0 || flag[l][key[r] - 1] == 0) continue;
			int l1 = l, r1 = key[r] - 1;
			int l2 = key[r], r2 = r;
			flag[l][r] = 1;
			for (int o1 = 0; o1 < 3; o1++)
			{
				for (int o2 = 0; o2 < 3; o2++)
				{
					for (int o3 = 0; o3 < 3; o3++)
					{
						if (o2 == o3 && o2 > 0) continue;
						for (int o4 = 0; o4 < 3; o4++)
						{
							dp[l][r][o1][o4] = (dp[l][r][o1][o4] + 1LL * dp[l1][r1][o1][o2] * dp[l2][r2][o3][o4]) % INF;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans += dp[1][n][i][j];
			ans %= INF;
		}
	}
	cout << ans << endl;
	return 0;
}