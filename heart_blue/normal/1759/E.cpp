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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL dp[N][3][2];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int h;
		scanf("%d", &h);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		dp[0][2][1] = h;
		int k1[] = { 1,2,4 };
		int k2[] = { 1,3 };
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			MEM(dp[i], 0);
			for (int o1 = 0; o1 <= 2; o1++)
			{
				for (int o2 = 0; o2 <= 1; o2++)
				{
					for (int o3 = 0; o3 <= o1; o3++)
					{
						for (int o4 = 0; o4 <= o2; o4++)
						{
							if (dp[i - 1][o1][o2] * k1[o1 - o3] * k2[o2 - o4] > a[i])
							{
								dp[i][o3][o4] = max(dp[i][o3][o4],
									dp[i - 1][o1][o2] * k1[o1 - o3] * k2[o2 - o4] + a[i] / 2);
								ans = i;
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}