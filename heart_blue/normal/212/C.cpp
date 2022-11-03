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
const int mod = 1e6 + 3;
const int N = 1e3 + 10;
char str[N];
LL dp[N][2][2];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	LL ans = 0;
	for (int o = 0; o < 2; o++)
	{
		MEM(dp, 0);
		dp[1][(str[1] - 'A') ^ o][o] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int o1 = 0; o1 < 2; o1++)
			{
				for (int o2 = 0; o2 < 2; o2++)
				{
					for (int o3 = 0; o3 < 2; o3++)
					{
						int o4 = (str[i] - 'A') != o3;
						if (o1 == 0 && o2 == 1)
						{
							if (o3 != 1 || o4 != 1) continue;
						}
						if (o3 == 1 && o4 == 1)
						{
							if (o1 != 0 || o2 != 1) continue;
						}
						if (o1 < o3 && o2 + o4 != 2) continue;
						dp[i][o3][o4] += dp[i - 1][o1][o2];
					}
				}
			}
		}
		for (int o1 = 0; o1 < 2; o1++)
		{
			for (int o2 = 0; o2 < 2; o2++)
			{
				for (int o3 = 0; o3 < 2; o3++)
				{
					for (int o4 = 0; o4 < 2; o4++)
					{
						if (o1 == 0 && o2 == 1)
						{
							if (o3 != 1 || o4 != 1) continue;
						}
						if (o3 == 1 && o4 == 1)
						{
							if (o1 != 0 || o2 != 1) continue;
						}
						if (o1 < o3 && o2 + o4 != 2) continue;
						ans += dp[n][o1][o2] * dp[1][o3][o4];
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}