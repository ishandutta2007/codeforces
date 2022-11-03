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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 4e2 + 10;
int dp[N][N];
char s1[N];
char s2[N];
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		MEM(dp, -1);
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		int len1 = strlen(s1 + 1);
		int len2 = strlen(s2 + 1);
		for (int i = 0; i < N; i++)
		{
			v[i].clear();
		}
		for (int i = 1; i <= len1; i++)
		{
			v[s1[i]].push_back(i);
		}
		int flag = 0;
		for (int n = 0; n < len2; n++)
		{
			int m = len2 - n;
			MEM(dp, 0x3f);
			dp[0][0] = 0;
			for (int sum = 0; sum < len2; sum++)
			{
				for (int i = 0; i <= sum; i++)
				{
					if (i > n) break;
					int j = sum - i;
					if (j > m) continue;
					if (j < 0) break;
					if (i < n)
					{
						auto& vp = v[s2[i + 1]];
						auto iter = upper_bound(vp.begin(), vp.end(), dp[i][j]);
						if (iter != vp.end())
						{
							dp[i + 1][j] = min(dp[i + 1][j], *iter);
						}
					}
					if (j < m)
					{
						auto& vp = v[s2[n + j + 1]];
						auto iter = upper_bound(vp.begin(), vp.end(), dp[i][j]);
						if (iter != vp.end())
						{
							dp[i][j + 1] = min(dp[i][j + 1], *iter);
						}
					}
				}
			}
			if (dp[n][m] <= len1)
			{
				flag = 1;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}