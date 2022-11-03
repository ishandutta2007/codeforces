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
const int N = 2e3 + 10;
bitset<20> solve(int a[4])
{
	bitset<20> dp;
	dp[0] = 1;
	for (int i = 1; i <= 3; i++)
	{
		int sz = a[i];
		while (sz--)
		{
			dp |= dp << i;
		}
	}
	return dp;
}
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
		vector<int> v(n);
		for (auto& x : v)
		{
			scanf("%d", &x);
		}
		int ans = INF;
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				for (int k = 0; k <= 3; k++)
				{
					int a[] = { 0,i,j,k };
					auto dp = solve(a);
					int maxv = 0;
					for (auto& x : v)
					{
						if (x < 20)
						{
							if (dp[x] == 0)
							{
								maxv = INF;
								break;
							}
							continue;
						}
						int cost = INF;
						for (int o = 0; o < 20; o++)
						{
							if (dp[o] && (x - o) % 3 == 0)
							{
								cost = (x - o) / 3;
							}
						}
						maxv = max(maxv, cost);
					}
					ans = min(ans, maxv + i + j + k);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}